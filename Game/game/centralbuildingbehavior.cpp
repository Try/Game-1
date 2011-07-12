#include "centralbuildingbehavior.h"

#include "../globject.h"
#include "playler.h"

#include "control/castlecontrol.h"

#include "runtime/gameclasses.h"

const AbstractBehavior::Registrator<CentralBuildingBehavior>
  CentralBuildingBehavior::registration( "central_building" );

CentralBuildingBehavior::CentralBuildingBehavior( GLObject *obj )
                        :BuildingBehavior(obj){
    Game::instance().playler( owner()->playler() ).addCentralBuilding( *this );
    Game::instance().playler( owner()->playler() ).addCastleEvent( this );
    }

CentralBuildingBehavior::~CentralBuildingBehavior(){
    Game::instance().playler( owner()->playler() ).delCentralBuilding( *this );
    Game::instance().playler( owner()->playler() ).delCastleEvent( this );
    }

void CentralBuildingBehavior::setPlaylerEvent(int Old, int New){
    Game::instance().playler( Old ).
        addLim( owner()->getClass()->cost.lim );
    Game::instance().playler( Old ).delCentralBuilding( *this );
    Game::instance().playler( Old ).delCastleEvent( this );

    Game::instance().playler( New ).
        addLim( -owner()->getClass()->cost.lim );
    Game::instance().playler( New ).addCentralBuilding( *this );
    Game::instance().playler( New ).addCastleEvent( this );
    }

void CentralBuildingBehavior::buyWorker(){
    build( "worker" );
    }
