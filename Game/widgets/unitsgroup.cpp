#include "unitsgroup.h"
#include "ui_unitsgroup.h"

#include <QGridLayout>

#include <QToolButton>

#include "../game/game.h"
#include "../globject.h"

#include "hud/unitavatar.h"

#include "unitbutton.h"

UnitsGroup *UnitsGroup::inst = 0;

UnitsGroup::UnitsGroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UnitsGroup) {
    ui->setupUi(this);
    inst = this;

    layOut = new QGridLayout();
    layOut->setSpacing(0);

    ui->btnsWidget->setLayout( layOut );

    kControl.setKey("Ctrl");
    //upSet();
    }

UnitsGroup::~UnitsGroup(){
    delete ui;
    }

void UnitsGroup::addButton( UnitButton*b ){
    layOut->addWidget( b, buttons.size()/10, buttons.size()%10 );
    buttons.push_back(b);

    updateAvatar();
    }

void UnitsGroup::updateAvatar(){
    if( inst->buttons.size() ){
      UnitAvatar::instance().
          update( inst->buttons[0]->object );
      } else {
      UnitAvatar::instance().update( 0 );
      }
    }

void UnitsGroup::removeUnit( GLObject *obj ){
    for(int i=0; i<inst->buttons.size(); ++i){
      if( inst->buttons[i]->object == obj ){
        delete inst->buttons[i];
        inst->buttons[i] = inst->buttons.back();
        inst->buttons.pop_back();
        inst->updateAvatar();
        return;
        }
      }

    }

void UnitsGroup::rebuildData(){
    for(int i=0; i<inst->buttons.size(); ++i){
      delete inst->buttons[i];
      }

    inst->buttons.clear();

    for(size_t i=0; i<Game::instance().selected().size(); ++i){
      inst->addButton( new UnitButton( Game::instance().selected()[i] ) );
      }


    inst->updateAvatar();
    inst->setEnabled(1);
    }

void UnitsGroup::lock(){
    inst->setEnabled(0);
    UnitAvatar::instance().update(0);
    }
