#include "workercontroller.h"

#include "ui_workercontroller.h"
#include "ui_unitctrl.h"

#include "globject.h"

#include "game/ui/buybutton.h"

#include "globject.h"
#include "game/workerbehavior.h"
#include "game/playler.h"

#include "dataCtrl/pixmaps.h"
#include "hud/showhint.h"

WorkerController::WorkerController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkerController) {
    ui->setupUi(this);

    ui->pages->setCurrentIndex(0);
    connect( ui->buildSome, SIGNAL(clicked()),
             this, SLOT(showBuildPage()) );

    ui->buildSome->setIcon( Pixmaps::getIcon("build") );

    hKey.setKey("b");
    hKey.setEvent(this, &WorkerController::showBuildPage );
    }

WorkerController::~WorkerController(){
    delete ui;
    }

WorkerController::Controller::Controller( GLObject *ow,
                                          WorkerBehavior *w){
    gui = 0;
    owner = ow;
    buildable = 0;
    worker = w;
    wrkGui = 0;
    }

WorkerController::Controller::~Controller(){
    // delete gui;

    caselBuild();
    }

void WorkerController::Controller::rectEvent(QRectF r){
    uCtrl.rectEvent(r);
    }

void WorkerController::Controller::mouseLClick(float x, float y){
    if( buildable ){
      if( buildable->validateLand() ){
        worker->setBuild( buildable->x(), buildable->y(),
                          buildable->getClass()->name );
        caselBuild();
        } else {
        if( owner->playlerPtr().isDrived() ){
          const GameObjectClass* str =
              Game::instance().playler( owner->playler() ).
              canBuyMsg(buildable->getClass()->name);
          ShowHint::instance().addMessage( str );
          }
        }

      } else {
      uCtrl.mouseLClick(x,y);
      }
    }

void WorkerController::Controller::mouseRClick(float x, float y){
    if( buildable )
      caselBuild(); else
      uCtrl.mouseRClick(x,y);
    }

void WorkerController::Controller::mouseMoveEvent(float x, float y, float z){
    float coord[] = {x,y};

    if( buildable ){
      for(int i=0; i<2; ++i){
        coord[i]*=2.0;
        coord[i]+=0.5;
        coord[i] = (int)coord[i];
        coord[i]/=2.0;
        }
      buildable->setPosition(coord[0], coord[1], z);
      buildable->validateLand();
      }
    }

void WorkerController::Controller::caselBuild(){
    if( buildable ){
      delete buildable;
      buildable = 0;
      }
    }

void WorkerController::showBuildPage(){
    ui->pages->setCurrentIndex(1);
    }

QWidget * WorkerController::Controller::createGUI( QLayout * lay ){/*
    delete gui;
    gui = new UnitCtrl();

    QWidget *w =  gui;
    lay->addWidget(w);*/

    gui = (UnitCtrl*)uCtrl.createGUI( lay );

    wrkGui = new WorkerController();
    gui->getUi()->layAdd->addWidget( wrkGui );

    for(unsigned i=0; i<owner->getClass()->recruts.size(); ++i ){
      BuyButton *btn = new BuyButton( this,
                                      owner->getClass()->recruts[i].name );
      wrkGui->ui->layBtns->addWidget(btn, i/4, i%4);
      btn->setHotKey( owner->getClass()->recruts[i].hotKey );
      }

    return gui;
    }

void WorkerController::Controller::build(const std::string &name){
    if( wrkGui->ui->pages->currentIndex()==1){
      if(Game::instance().playler( owner->playler() ).canBuy(name) ){
        caselBuild();
        buildable = new GLObject( Game::instance().getScene(),
                                  name);//Game::instance().add( name );
        buildable->setBuildable();
        } else {
        if( owner->playlerPtr().isDrived() ){
          const GameObjectClass* str =
              Game::instance().playler( owner->playler() ).canBuyMsg(name);
          ShowHint::instance().addMessage( str );
          }
        }
      }
    }
