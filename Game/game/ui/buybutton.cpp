#include "buybutton.h"

#include "runtime/gameclasses.h"
#include "runtime/gameobjectclass.h"

#include "game/control/castlecontrol.h"
#include "game/control/workercontroller.h"

#include "game/game.h"
#include "hud/showhint.h"

#include <QDebug>

BuyButton::BuyButton(CastleControl *ctrl,
                     const std::string & str):name(str) {
    init();

    owner = ctrl;
    connect(this, SIGNAL(clicked()),
            this, SLOT(pressEvent()) );

    //&BuyButton::clicked;
    }

BuyButton::BuyButton( WorkerController::Controller *ctrl,
                      const std::string & str ):name(str){
    init();
    wowner = ctrl;
    connect(this, SIGNAL(clicked()),
            this, SLOT(buildSome()) );
    }

BuyButton::~BuyButton(){
    }

void BuyButton::setHotKey( const std::string& k ){
    hKey.setKey( k );
    hKey.setEvent(this, &BuyButton::click);
    }

void BuyButton::init(){
    setIconSize   ( QSize(32, 32) );
    setMinimumSize( QSize(40, 40) );
    setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );

    setMouseTracking(1);

    const GameObjectClass *cls = GameClasses::get( name );

    if( cls ){
      setIcon   ( cls->icon );
      }
    }

void BuyButton::pressEvent(){
    owner->recrut( name );
    }

void BuyButton::buildSome(){
    wowner->build( name );
    }

bool BuyButton::event(QEvent *event){
    if( event->type() == QEvent::Enter ){
      const GameObjectClass *cls = GameClasses::get( name );
      ShowHint::instance().setText( cls->hint );
      }

    if( event->type() == QEvent::Leave ){
      ShowHint::instance().setText( "" );
      }

    return QToolButton::event( event );
    }
