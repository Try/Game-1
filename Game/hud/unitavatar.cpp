#include "unitavatar.h"
#include "ui_unitavatar.h"

UnitAvatar* UnitAvatar::inst = 0;

#include "globject.h"

#include "runtime/gameclasses.h"
#include "runtime/gameobjectclass.h"

UnitAvatar::UnitAvatar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UnitAvatar) {

    ui->setupUi(this);

    inst = this;

    object = 0;
    connect(&timer, SIGNAL(timeout()),
            this, SLOT(updateT()) );

    connect(ui->icon, SIGNAL(pressed()),
            this,     SLOT(setCamera()) );

    connect(ui->icon, SIGNAL(released()),
            this,     SLOT(unsetCamera()) );

    timer.start(10);
    cameraCtrl = 0;

    ui->hp->setFormat( "" );
    ui->hp->setMaximum( 1 );
    ui->hp->setValue  ( 0 );
    }

UnitAvatar::~UnitAvatar(){
    delete ui;
    }

UnitAvatar& UnitAvatar::instance(){
    return *inst;
    }

void UnitAvatar::updateT(){
    update(object);
    }

void UnitAvatar::setCamera(){
    cameraCtrl = 1;
    }

void UnitAvatar::unsetCamera(){
    cameraCtrl = 0;
    }

void UnitAvatar::update( GLObject* obj ){
    if( obj ){
      if( object!=obj ){
        ui->icon->setIcon( obj->getClass()->icon );
        ui->hp->setMaximum( obj->getClass()->maxHp );
        }

      ui->hp->setValue( obj->hp() );
      ui->hp->setFormat( "%v/" + QString::number( obj->getClass()->maxHp ) );
      } else {
      if( object ){
        ui->icon->setIcon( QIcon() );

        ui->hp->setFormat( "" );
        ui->hp->setMaximum( 1 );
        ui->hp->setValue  ( 0 );
        }
      }

    object = obj;

    if( cameraCtrl && object )
      Game::instance().setCameraPosition( object );
    }
