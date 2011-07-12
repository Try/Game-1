#include "gameclasses.h"

#include "gameobjectclass.h"
#include "runtime/atacktypes.h"

#include <QDebug>

GameClasses *GameClasses::inst = 0;
AtackTypes  *GameClasses::atkTypes = 0;

GameClasses::GameClasses(){
    inst = this;
    atkTypes = new AtackTypes();
    }

GameClasses::~GameClasses(){
    for(unsigned i=0; i<cls.size(); ++i){
      delete cls[i];
      }
    inst = 0;
    delete atkTypes;
    }

const std::vector<GameObjectClass*>& GameClasses::classes(){
    return inst->cls;
    }

void GameClasses::add(GameObjectClass *cls){
    for( size_t i=0; i<inst->cls.size(); ++i)
      if( inst->cls[i]->name == cls->name ){
        inst->cls[i]->copy( *cls );
        delete cls;
        return;
        }

    inst->cls.push_back( cls );
    }

const GameObjectClass* GameClasses::get(const char * name){
    for(unsigned i=0; i<inst->cls.size(); ++i){
      if( inst->cls[i]->name==name )
        return inst->cls[i];
      }

    return 0;
    }

const GameObjectClass* GameClasses::get(const std::string &s){
    return get( s.data() );
    }
