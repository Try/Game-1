#include "bmpmap.h"

#include "game/game.h"
#include "globject.h"

#include <QImage>
#include <cmath>

#include "game/playler.h"

int BmpMap::curPl = 0;

void BmpMap::load(Game &game, const std::string &file){
    QImage img;
    curPl = 1;

    img.load( file.data() );
    game.map.resize( img.width()-1, img.height()-1 );

    for(int i=0; i<img.width(); ++i)
      for(int r=0; r<img.height(); ++r){
        pixel(game, i, r, QColor(img.pixel(img.width()-i-1,r)) );
        }

    game.map.rebuildPaintData();
    }

void BmpMap::pixel(Game &game, int x, int y, const QColor& c){
    if( c==QColor(0, 0, 0) ){
      if( game.rand()%10==0 )
        game.add("grass")->setPosition(x, y, 0);
      } else
    if( c==QColor(0, 255, 0) ){
      game.add("tree0")->setPosition(x, y, 0);
      } else

    if( c.red()==0 && c.blue()==0 &&
        c.green() <= 127){
      for(int i=0; i<1; ++i){
        std::string name = "rock0";
        name.push_back('0'+rand()%5+1 );

        if( rand()%10==0 )
          game.add( name )->setPosition(x,
                                        y, 0);
        }
      } else

    if( c==QColor(128, 128, 128) ){
      int mx =  Map::coordX(x),
          my =  Map::coordX(y);
      game.map.setHeight( mx, my,
                          std::min(-4.0f, game.map.height(mx,my)));

      for(int i=-3; i<=3; ++i)
        for(int r=-3; r<=3; ++r){
          float w = std::max(1.0-sqrt(i*i+r*r)/3.0, 0.0);
          game.map.setHeight( mx+i, my+r,
                              std::min(-4.0f*w, game.map.height(mx+i,my+r)));
          game.map.excludeQuad(mx+i, my+r, 0);
          }

      } else

    if( c==QColor(255, 255, 0) ){
      game.add("gold")->setPosition(x, y, 0);
      } else

    if( c==QColor(255, 255, 255) ){
      if( game.playler(curPl).isActive() && curPl<9 ){
        GLObject *obj = game.add("castle");
        obj->setPosition(x, y, 0);
        obj->setPlayler( curPl );

        for(int i=0; i<6; ++i){
          GLObject *obj = game.add("worker");
          obj->setPosition(x+(i%3)*0.5, y+(i/3)*0.5, 0);
          obj->setPlayler( curPl );
          }
        }

      ++curPl;
      }

    }
