#include "minimap.h"
#include "ui_minimap.h"

#include "game/game.h"

#include <QPainter>

MiniMap *MiniMap::inst = 0;

#include "globject.h"
#include "game/playler.h"

#include <QMouseEvent>

#include "graphis/gamescenegraph.h"

MiniMap::MiniMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiniMap){
    ui->setupUi(this);

    inst = this;
    step = 0;


    }

MiniMap::~MiniMap(){
    delete ui;
    }

MiniMap& MiniMap::instance(){
    return *inst;
    }

void MiniMap::updateMiniMap( Game& game ){
    Map &m = game.map;

    if( imgMinimap.width() !=width() &&
        imgMinimap.height()!=height()  ) {
      int w = width(), h = height();
      imgMinimap = QImage( w, h, QImage::Format_RGB32 );
      imgFog     = QImage( w, h, QImage::Format_RGB32 );
      step = 0;
      updateBackground(m);
      }

    if( game.interactive().size() ){
      int countStp = std::min((int)game.interactive().size(), 100);
      for(int i=0; i<countStp; ++i){
        if( step >= (size_t)game.interactive().size() ){
          step = 0;
          surface = QPixmap::fromImage( imgMinimap );
          update();
          updateBackground(m);
          }

        if( game.interactive().size() )
          smallStep(game);
        ++step;
        }
      } else {
      if( step%2==0 ){
        surface = QPixmap::fromImage( imgMinimap );
        updateBackground(m);
        update();
        }

      ++step;
      }

    }

void MiniMap::smallStep( Game& game ){
    GLObject &obj = *game.interactive()[step];

    int x = Map::coordX( obj.x() )*imgMinimap.width() /game.map.width();
    int y = Map::coordY( obj.y() )*imgMinimap.height()/game.map.height();

    x = std::max( std::min(imgMinimap.width()-1, x), 0);
    y = std::max( std::min(imgMinimap.height()-1, y), 0);

    QColor cl;

    cl = obj.playlerPtr().color();

    imgMinimap.setPixel( imgMinimap.width()-1-x, y, cl.rgba() );
    }

void MiniMap::updateBackground( Map &m ){// return;
    QColor cl;
    for(int i=0; i<imgMinimap.width(); ++i)
      for(int r=0; r<imgMinimap.height(); ++r){
        int x = i*m.width() /imgMinimap.width(),
            y = r*m.height()/imgMinimap.height();
        cl = QColor(0, 127, 0);

        if( !m.isEnable(x,y) )
          cl = QColor(0,0,0);

        if( m.resCount(x,y) )
          cl = QColor(255, 255,0);

        //cl = QColor( at(i,r).group*5, 0, 0 );


        imgMinimap.setPixel( imgMinimap.width()-1-i, r, cl.rgba() );
        }
    }

void MiniMap::paintEvent(QPaintEvent *){
    QPainter p(this);
    Map &m = Game::instance().map;

    p.drawPixmap( 0, 0, width(), height(), surface );

    for(int i=0; i<4; ++i){
      double* a = GameSceneGraph::instance()->gameViewRect[i];
      double* b = GameSceneGraph::instance()->gameViewRect[(i+1)%4];

      double x[2] = {m.width() - Map::coordX(a[0]),
                     m.width() - Map::coordX(b[0]) };
      double y[2] = { Map::coordY(a[1]),
                      Map::coordY(b[1]) };

      for(int r=0; r<2; ++r){
        x[r] = x[r]*width()/m.width();
        y[r] = y[r]*height()/m.height();
        }

      p.drawLine( x[0], y[0], x[1], y[1] );
      }
    }

void MiniMap::mousePressEvent(QMouseEvent *event){
    mouse = 1;
    mouseMoveEvent(event);
    }

void MiniMap::mouseMoveEvent(QMouseEvent *event){
    if( mouse ){
      float x = 1.0 - event->x()/(float)width(),
            y = event->y()/(float)height();

      x*= Game::instance().map.width();
      y*= Game::instance().map.height();

      Game::instance().setCameraPosition(x, y);
      }
    }

void MiniMap::mouseReleaseEvent(QMouseEvent *){
    mouse = 0;
    }
