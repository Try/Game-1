#include "incompletebuildingbehavior.h"

#include "globject.h"
#include "dataCtrl/filestream.h"

#include "playler.h"

#include "control/incompletebuildingcontrol.h"

const AbstractBehavior::Registrator<IncompleteBuildingBehavior>
  IncompleteBuildingBehavior::registration( "incomplete_building" );

IncompleteBuildingBehavior::IncompleteBuildingBehavior(GLObject *obj)
                           :FalagOwnerBahavior(obj){
    point_flag = 0;

    maxTime = obj->getClass()->buildTime;
    time    = maxTime;


    move.tgPos[0] = owner()->x();
    move.tgPos[1] = owner()->y();

    move.fakeMove = 1;

    setName("incomplete_building");

    owner()->hp( calcHp(time) );

    if( owner()->isSel() )
      selectEvent(1);
    }

IncompleteBuildingBehavior::~IncompleteBuildingBehavior(){
//    Game::instance().playler(owner->playler()).buyEvent( owner->getClass()->name,
//                                                         0);
    }

int IncompleteBuildingBehavior::calcHp(int time){
    return std::max( (owner()->getClass()->maxHp*(maxTime-time))/maxTime, 1);
    }

void IncompleteBuildingBehavior::command(float x, float y, int , bool f){
    move.tgPos[0] = x;
    move.tgPos[1] = y;
    move.fakeMove = f;
    move.taget = 0;
    }

void IncompleteBuildingBehavior::deleteUnitEvent(const GLObject *obj){
    if( move.taget==obj )
      move.taget = 0;
    }

void IncompleteBuildingBehavior::setPlaylerEvent(int , int ){}

void IncompleteBuildingBehavior::tick(){
    upsetPointFlagPos();

    if( time ){
      --time;
      owner()->hp( owner()->hp() + calcHp(time) - calcHp(time+1) );

      owner()->setPosition( owner()->x(), owner()->y(),
                            -owner()->maxHeight()*time/(float)maxTime );
      } else {
      MvInfo m = move;
      GLObject *ow = owner();

      ow->setCompleteBuilding();
      if( m.taget )
        ow->command( m.taget ); else
        ow->command( m.tgPos[0], m.tgPos[1], 1, m.fakeMove);
      }

    }


void IncompleteBuildingBehavior::serialize(FileStream &f){
    f + maxTime + time;
    }

IController* IncompleteBuildingBehavior::createController(){
    return new IncompleteBuildingControl::Controller( this );
    }

float IncompleteBuildingBehavior::progress(){
    return 1.0 - (time)/(float)maxTime;
    }

void IncompleteBuildingBehavior::cansel(){
    time = 0;
    owner()->hp(-1);
    owner()->setCompleteBuilding();
    }

void IncompleteBuildingBehavior::upsetPointFlagPos(){
    if( point_flag ){
      if( move.taget ){
        if( move.taget!=owner() )
          point_flag->setPosition( move.taget->x(), move.taget->y(), 0 );  else
          point_flag->setPosition(0, 0, -100);
        } else
        point_flag->setPosition( move.tgPos[0],   move.tgPos[1], 0 );
      }
    }
