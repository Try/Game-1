#include "falagownerbahavior.h"

#include "game/game.h"
#include "globject.h"

#include "playler.h"

FalagOwnerBahavior::FalagOwnerBahavior( GLObject *ow ){
    m_owner = ow;
    point_flag = 0;

    move.taget = 0;
    }

FalagOwnerBahavior::~FalagOwnerBahavior(){
    Game::instance().del( point_flag );
    }

void FalagOwnerBahavior::selectEvent( bool s ){
    if( s ){
      if( owner()->playlerPtr().isDrived() &&
          owner()->getClass()->recruts.size() ){
        if( point_flag==0 )
          point_flag = Game::instance().add("pointFlag");

        upsetPointFlagPos();
        }
      } else {
      Game::instance().del(point_flag);
      }
    }

GLObject *FalagOwnerBahavior::owner() const{
    return m_owner;
    }

void FalagOwnerBahavior::command( GLObject * obj ){
    move.taget = obj;
    }

void FalagOwnerBahavior::deleteUnitEvent( const GLObject *obj ){
    if( obj==move.taget )
      move.taget = 0;
    }

void FalagOwnerBahavior::serialize(FileStream &f){
    serialize_flag(f);
    }

void FalagOwnerBahavior::serialize_flag(FileStream &f){
    f + move.tgPos[0] + move.tgPos[1]+ move.fakeMove;

    f.serialize( move.taget );
    f.serialize( point_flag );
    }
