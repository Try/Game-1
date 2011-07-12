#include "unitctrl.h"
#include "ui_unitctrl.h"

#include "game/game.h"

#include "dataCtrl/pixmaps.h"

#include "game/resourcebehavior.h"

UnitCtrl::UnitCtrl(QWidget *parent) :
      QWidget(parent),
      ui(new Ui::UnitCtrl) {
    ui->setupUi(this);

    state = Normal;

    ui->move->  setIcon( Pixmaps::getIcon("move") );
    ui->cansel->setIcon( Pixmaps::getIcon("cansel") );
    ui->atack ->setIcon( Pixmaps::getIcon("atack") );

    connect(ui->move, SIGNAL(clicked()),
            this, SLOT(setMove()) );
    connect(ui->atack, SIGNAL(clicked()),
            this, SLOT(setAtack()) );
    connect(ui->cansel, SIGNAL(clicked()),
            this, SLOT(stopMove()) );

    atack.setKey("a");
    atack.setEvent(this, &UnitCtrl::setAtack );
    }

UnitCtrl::~UnitCtrl(){
    delete ui;
    }

void UnitCtrl::stopMove(){
    Game::instance().stopMove();
    }

void UnitCtrl::setMove(){
    state = Move;
    }

void UnitCtrl::setAtack(){
    state = Atack;
    }

Ui::UnitCtrl *UnitCtrl::getUi(){
    return ui;
    }

UnitCtrl::Controller::Controller(){
    gui = 0;
    }

UnitCtrl::Controller::~Controller(){
    delete gui;
    }

void UnitCtrl::Controller::rectEvent(QRectF r){
    Game::instance().select(r);
    }

void UnitCtrl::Controller::mouseLClick(float x, float y){
    State state = gui->state;
    gui->state = Normal;

    if( state == Normal ){
      Game::instance().select(x, y);
      } else

    if( state == Move ){
      GLObject *obj = Game::instance().objects().unitAt(x, y);
      if( obj )
        Game::instance().command( obj ); else
        Game::instance().command(x, y);
      } else

    if( state == Atack ){
      Game::instance().aClick(x,y);
      }

    }

void UnitCtrl::Controller::mouseRClick(float x, float y){
    GLObject *obj;
    obj = ResourceBehavior::resAt(x,y);

    if( !obj )
      obj = Game::instance().objects().unitAt(x, y);

    if( obj )
      Game::instance().command( obj ); else
      Game::instance().command(x, y);
    gui->state = Normal;
    }

QWidget * UnitCtrl::Controller::createGUI( QLayout * lay ){
    delete gui;
    gui = new UnitCtrl();

    QWidget *w =  gui;
    lay->addWidget(w);

    return w;
    }
