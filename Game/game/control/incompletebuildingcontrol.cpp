#include "incompletebuildingcontrol.h"
#include "ui_incompletebuildingcontrol.h"

#include "game/game.h"
#include "game/incompletebuildingbehavior.h"

#include "dataCtrl/pixmaps.h"

IncompleteBuildingControl::
    IncompleteBuildingControl( IncompleteBuildingBehavior *ow ) :
    ui(new Ui::IncompleteBuildingControl) {
    ui->setupUi(this);

    connect( &timer, SIGNAL(timeout()),
              this, SLOT(updateGui()) );

    connect( ui->canselBtn, SIGNAL(clicked()),
             this, SLOT(canselBuild()) );

    ui->canselBtn->setIcon( Pixmaps::getIcon("cansel_build") );

    timer.start(30);

    owner = ow;
    updateGui();
    }

IncompleteBuildingControl::~IncompleteBuildingControl(){
    delete ui;
    }


IncompleteBuildingControl::Controller::
                           Controller( IncompleteBuildingBehavior *ow ){
    gui = 0;
    owner = ow;
    }

IncompleteBuildingControl::Controller::~Controller(){
    delete gui;

    //caselBuild();
    }

void IncompleteBuildingControl::Controller::rectEvent(QRectF r){
    Game::instance().select(r);
    }

void IncompleteBuildingControl::Controller::mouseLClick(float x, float y){
    Game::instance().select(x, y);
    }

void IncompleteBuildingControl::Controller::mouseRClick(float x, float y){
    GLObject *obj = Game::instance().objects().unitAt(x, y);
    if( obj )
      Game::instance().command( obj ); else
      Game::instance().command(x, y);
    }

void IncompleteBuildingControl::Controller::mouseMoveEvent(float , float , float ){

    }

void IncompleteBuildingControl::updateGui(){
    ui->progress->setValue( owner->progress()*100 );
    }

QWidget * IncompleteBuildingControl::Controller::createGUI( QLayout * lay ){
    delete gui;
    gui = new IncompleteBuildingControl( owner );

    QWidget *w =  gui;
    lay->addWidget(w);

    return w;
    }

void IncompleteBuildingControl::canselBuild(){
    owner->cansel();
    }
