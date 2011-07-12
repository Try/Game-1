#include "bot.h"

#include <QDebug>

#include "globject.h"

#include "game/workerbehavior.h"
#include "game/buildingbehavior.h"
#include "game/centralbuildingbehavior.h"
#include "game/warriorbehavior.h"
#include "game/unitbehavior.h"

#include "game/playler.h"

#include "dataCtrl/filestream.h"
#include "game/resourcebehavior.h"

#include "runtime/gameclasses.h"

#include <cmath>

Bot::Bot(Playler &pl):playler(pl){
    buildCoord.x = 0;
    buildCoord.y = 0;

    buildCoord.maxCoord = 16;
    wrkId = 0;

    state = Defence;
    atkLim = 20;
    needToUpRange = 0;
    atkRecalc      = 0;

    setSkil(2);
    }

void Bot::tick(){
    --atkRecalc;

    assignWorkers();

    static const int workerPerMineral[] = {1, 2, 3};

    if( workers.size() < castles.size()*6*workerPerMineral[skil] ){
      recrutWorkers();
      }

    if( units.size() - workers.size() >= atkLim &&
        &playler != &Game::instance().playler(0) ){
      atack();
      atkLim += 15;
      atkLim = std::min(atkLim, 150);
      } else {
      if( state != Defence )
        if( tgCastle != findTgCastle(1) )
          goHome();
      state = Defence;
      }
    }

void Bot::assignWorkers(){
    for( StableSet<WorkerBehavior*>::iterator i=workers.begin();
         i!=workers.end(); ++i){
      if( !(*i)->isBusy() )
        (*i)->goToWork();
      }

    if( workers.size() >= 6+5 &&
        playler.countOf("barracks")<2 ){
      tryToBuild("barracks");
      }

    {
      int curLim = playler.lim()
        -(playler.countOfIncom("house") *GameClasses::get("house" )->cost.lim+
          playler.countOfIncom("castle")*GameClasses::get("castle")->cost.lim);
      if( curLim < 5+atkLim/10 ){
        tryToBuild("house");
        }
    }

    if( playler.countOfall("tower")<4 )
      tryToBuild("tower");

    if( (playler.countOfall("barracks")<4 && atkLim>20) ){
      tryToBuild("barracks");
      } else {
      recrutMarines();
      if( playler.countOfall("barracks")>0 &&
          playler.countOfall("forge")<1 )
        tryToBuild("forge");

      if( playler.countOfall("stone_cyrcle")<1 ||
          (playler.countOfall("stone_cyrcle")<2 && atkLim>30 )){
        tryToBuild("stone_cyrcle");
        } else {
        if( playler.countOfall("fire_cram")<1 ||
            (playler.countOfall("fire_cram")<2 && atkLim>40 ))
          tryToBuild("fire_cram");
        }
      }


    }

void Bot::recrut(BuildingBehavior* b, const char* name){
    b->build(name);
    }

void Bot::recrutMarines(){
    int count = units.size() - workers.size();
    for( StableSet<BuildingBehavior*>::iterator i = barracks.begin();
         i!=barracks.end(); ++i){

      if( count < 15 ){
        if( (*i)->buildQueue().size()==0 ) {
          recrut( *i, "pikeman");
          }

        if( (*i)->buildQueue().size()==1 ) {
          recrut( *i, "balista");
          }

        if( (*i)->buildQueue().size()==2 ) {
          recrut( *i, "hummer");
          }
        } else
      if( count < 20 ){
        if( (*i)->buildQueue().size()==0 ) {
          recrut( *i, "balista");
          }
        if( (*i)->buildQueue().size()==1 ) {
          recrut( *i, "pikeman");
          }

        if( (*i)->buildQueue().size()==2 ) {
          recrut( *i, "hummer");
          }
        } else
     if( count < 30 ){
        if( (*i)->buildQueue().size()==0 ) {
          recrut( *i, "golem");
          }
        if( (*i)->buildQueue().size()==0 ) {
          recrut( *i, "pikeman");
          }

        if( (*i)->buildQueue().size()==1 ) {
          recrut( *i, "balista");
          }

        if( (*i)->buildQueue().size()==2 )
          recrut( *i, "hummer");
        } else
      if( count < 150 ){
        if( (*i)->buildQueue().size()==0 ) {
          recrut( *i, "mage");
          } else
        if( (*i)->buildQueue().size()==1 ) {
          recrut( *i, "incvisitor");
          }
        if( (*i)->buildQueue().size()==0 ) {
          recrut( *i, "pikeman");
          }

        if( (*i)->buildQueue().size()==1 ) {
          recrut( *i, "balista");
          }

        if( (*i)->buildQueue().size()==2 )
          recrut( *i, "hummer");
        }
      }

    }

CentralBuildingBehavior* Bot::findTgCastle( bool enemy ){
    if( castles.size()==0 )
      return 0;

    enemy = !enemy;

    int x = (*castles.begin())->x();
    int y = (*castles.begin())->x();
    int l = -1;
    CentralBuildingBehavior *re = 0;

    for( int i=0; i<Game::instance().playlersCount(); ++i ){
      if( (&Game::instance().playler(i) != &playler) ^ enemy ){
        CentralBuildingBehavior *cas =
            Game::instance().playler(i).getCastle(x, y);

        if( cas ){
          float l1 = fabs(cas->x()-x)+fabs(cas->y()-y);
          if( re==0 || ( l1 < l ) ){
            re = cas;
            l  = l1;
            }
          }
        }
      }
    return re;
    }

void Bot::moveToCastle( bool enemy ){
    int tgX = 0, tgY = 0;

    tgCastle = findTgCastle( enemy );
    if( tgCastle ){
      tgX = tgCastle->worldX();
      tgY = tgCastle->worldY();
      } else {
      return;
      }

    atackTo( tgX, tgY );
    }

void Bot::atackTo(float x, float y){
    int count = 0;
    for( StableSet<GLObject*>::iterator i=units.begin(); i!=units.end(); ++i){
      GLObject *obj = *i;{
        UnitBehavior *war = (UnitBehavior*)obj->getBehavior("unit");
        if( war && !obj->getBehavior("worker") ){
          ++count;
          }
        }
      }

    count = sqrt(count);
    int id = 0;
    for( StableSet<GLObject*>::iterator i=units.begin(); i!=units.end(); ++i){
      GLObject *obj = *i;
      float k = 1.0;
      {

        UnitBehavior *war = (UnitBehavior*)obj->getBehavior("unit");

        if( war && !obj->getBehavior("worker") ){
          obj->command( x+(id%count)*k, y+(id/count)*k, 0, 0);
          war->getWarrior()->setAtack(1);
          war->getWarrior()->setAClick(1, x, y );
          ++id;
          }
        }
      }
    }

void Bot::atack(){
    if( state==Atack )
      return;

    moveToCastle(1);

    state = Atack;
    }

void Bot::goHome(){
    if( state==Defence )
      return;

    moveToCastle(0);

    state = Defence;
    }

void Bot::tryToBuild( const std::string &name ){
    if( workers.size()==0 )
      return;

    int id = wrkId % workers.size();
    StableSet<WorkerBehavior*>::iterator i = workers.begin();
    while( id ){
      ++i;
      --id;
      }
    WorkerBehavior &w = **( i );

    if( !w.isBuilder() ){
      if( castles.size() ){
        CentralBuildingBehavior &c = **castles.begin();

        float x = c.worldX() + buildCoord.x-buildCoord.maxCoord/2,
              y = c.worldY() + buildCoord.y-buildCoord.maxCoord/2;
        if( distanceToMinerals( x,y )>2 &&
            GLObject::validateLand(x,y, name, 1) ){
          w.setBuild( x, y, name );
          needToUpRange = 0;
          }
        }
      }


    ++buildCoord.x;
    if( buildCoord.x>buildCoord.maxCoord ){
      buildCoord.x = 0;
      ++buildCoord.y;

      if( buildCoord.y>buildCoord.maxCoord ){
        buildCoord.y = 0;
        if( needToUpRange ){
          buildCoord.maxCoord += 5;
          needToUpRange = 0;
          } else {
          needToUpRange = 1;
          }
        }

      }
    ++wrkId;
    }

int Bot::distanceToMinerals(int x, int y){
    //ResourceBehavior::items();
    int d = -1;
    if( ResourceBehavior::items().size() )
      d = abs(x-ResourceBehavior::items()[0]->x()) +
          abs(y-ResourceBehavior::items()[0]->y());

    for(size_t i = 1; i<ResourceBehavior::items().size(); ++i){
      int d1 = abs(x-ResourceBehavior::items()[i]->x()) +
               abs(y-ResourceBehavior::items()[i]->y());
      if( d1<d )
        d = d1;
      }

    return d;
    }

void Bot::addBuildingsEvent( BuildingBehavior * obj ){
    if( obj->owner()->getClass()->name=="barracks" ||
        obj->owner()->getClass()->name=="stone_cyrcle" ||
        obj->owner()->getClass()->name=="fire_cram" )
      barracks.insert(obj);
    }

void Bot::delBuildingsEvent( BuildingBehavior * obj ){
    if( obj->owner()->getClass()->name=="barracks" ||
        obj->owner()->getClass()->name=="stone_cyrcle" ||
        obj->owner()->getClass()->name=="fire_cram" )
      barracks.erase(obj);
    }

void Bot::recrutWorkers(){
    for(StableSet<CentralBuildingBehavior*>::iterator i=castles.begin();
        i!=castles.end(); ++i){
      if( (*i)->buildQueue().size()==0 )
        (*i)->buyWorker();
      }
    }

void Bot::addUnitEvent( GLObject * obj ){
    units.insert(obj);

    if( castles.size() ){
      CentralBuildingBehavior *c = findTgCastle(0);
      if( c ){
        obj->command( c->worldX(), c->worldY(), 1, 0);
        UnitBehavior *war = (UnitBehavior*)obj->getBehavior("unit");
        if( war ){
          war->getWarrior()->setAtack(1);
          war->getWarrior()->setAClick(1, c->worldX(), c->worldY());
          }
        }
      }
    }

void Bot::delUnitEvent( GLObject * obj ){
    units.erase(obj);
    }

void Bot::addWorkerEvent( WorkerBehavior * obj ){
    workers.insert(obj);
/*
    UnitBehavior *war = (UnitBehavior*)obj->owner()->getBehavior("unit");
    if( war )
      war->getWarrior()->setAtack(1);*/
    }

void Bot::delWorkerEvent( WorkerBehavior * obj ){
    workers.erase(obj);
    }

void Bot::addCastleEvent( CentralBuildingBehavior * obj ){
    castles.insert(obj);
    }

void Bot::delCastleEvent( CentralBuildingBehavior * obj ){
    castles.erase(obj);
    }

void Bot::setSkil(int level){
    skil = level;
    }

int  Bot::skilLevel(){
    return skil;
    }

void Bot::serialize(FileStream &f){
    f + wrkId + atkLim + skil;

    if( f.isOut() ){
      f << int(state);
      } else {
      int s;
      f >> s;
      state = State(s);
      }
    }

void Bot::atackEvent( GLObject * obj ){
    if( atkRecalc )
      return;

    if( obj->getBehavior("building") ||
        obj->getBehavior("worker") ||
        obj->getBehavior("central_building") ){
      atackTo( obj->x(), obj->y() );
      atkRecalc = 30;
      }
    }
