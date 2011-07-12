#include "castlecontrol.h"
#include "ui_castlecontrol.h"

#include "game/game.h"
#include "game/buildingbehavior.h"

#include <QDebug>

#include "globject.h"

#include <QTimer>
#include "game/resourcebehavior.h"

#include "runtime/gameclasses.h"

#include <QObject>
#include "game/ui/buybutton.h"

class CastleControl::UnitBtn:public QToolButton{
  public:
    UnitBtn( CastleControl *ctrl ){
      owner = ctrl;

      setIconSize( QSize(24, 24) );
      setMinimumSize( QSize(32, 32) );
      }

  private:
    void mousePressEvent(QMouseEvent *){
      owner->removeFromQueue( this );
      }

  private:
    CastleControl *owner;
  };

CastleControl::CastleControl( BuildingBehavior *ow ) :
      QWidget(),
      ui(new Ui::CastleControl){
    ui->setupUi(this);
    owner = ow;

    connect( &timer, SIGNAL(timeout()),
             this, SLOT(updateGUI()) );

    timer.start(10);


    creteButton( ui->layCurrenBuild );
    for(int i=0; i<5; ++i){
      creteButton( ui->layBuild );
      }

    for(unsigned i=0; i<ow->ownerClass().recruts.size(); ++i){
      BuyButton *b = new BuyButton(this, ow->ownerClass().recruts[i].name);
      b->setHotKey( ow->ownerClass().recruts[i].hotKey );
      ui->buildButtons->addWidget(b);
      }

    updateGUI();
    }

CastleControl::~CastleControl(){
    delete ui;
    }

CastleControl::UnitBtn* CastleControl::creteButton( QLayout * l ){
    UnitBtn *b =  new UnitBtn( this );
    l->addWidget( b );
    btn.push_back( b  );
    return b;
    }

void CastleControl::recrut( const std::string &str ){
    owner->buildByController( str );
    }

CastleControl::Controller::Controller(BuildingBehavior *ow){
    gui = 0;
    owner = ow;
    }

CastleControl::Controller::~Controller(){
    delete gui;
    }

void CastleControl::Controller::rectEvent(QRectF r){
    Game::instance().select(r);
    }

void CastleControl::Controller::mouseLClick(float x, float y){
    Game::instance().select(x, y);
    }

void CastleControl::Controller::mouseRClick(float x, float y){
    GLObject *obj;
    obj = ResourceBehavior::resAt(x,y);

    if( !obj )
      obj = Game::instance().objects().unitAt(x, y);

    if( obj )
      Game::instance().command( obj ); else
      Game::instance().command(x, y);
    }

QWidget * CastleControl::Controller::createGUI( QLayout * lay ){
    delete gui;
    gui = new CastleControl( owner );

    QWidget *w =  gui;
    lay->addWidget(w);

    return w;
    }

void CastleControl::updateGUI(){
    if( owner->buildQueue().size()==0 ){
      ui->buildPanel->hide();
      } else {
      ui->buildPanel->show();
      }

    ui->progress->setValue( owner->progressBar()*100 );

    for(unsigned i=0; i<btn.size(); ++i){
      if( i<owner->buildQueue().size() ){
        btn[i]->show();
        btn[i]->setIconSize( QSize(24, 24) );

        const GameObjectClass *cls = GameClasses::get( owner->buildQueue()[i] );

        btn[i]->setIcon   ( cls->icon );
        btn[i]->setToolTip( cls->hint );
        } else {
        btn[i]->hide();
        }
      }
    }

void CastleControl::removeFromQueue( UnitBtn* u){
    for(unsigned i=0; i<btn.size(); ++i)
      if( btn[i]==u ){
        owner->removeFromQueue(i);
        updateGUI();

        return;
        }
    }
