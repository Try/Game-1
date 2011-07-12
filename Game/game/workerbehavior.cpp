#include "workerbehavior.h"

#include <cmath>
#include "../globject.h"

#include "movealgo.h"
#include "unitbehavior.h"

#include <QDebug>

#include "playler.h"
#include "centralbuildingbehavior.h"
#include "resourcebehavior.h"

#include "control/workercontroller.h"

#include "dataCtrl/filestream.h"

#include "game.h"
#include "hud/showhint.h"

using namespace std;


const int WorkerBehavior::maxWrkRadius = 10;

const AbstractBehavior::Registrator<WorkerBehavior>
  WorkerBehavior::registration( "worker" );

WorkerBehavior::WorkerBehavior( GLObject * obj ):m_owner(obj){
    setName("worker");

    unitBehavior = new UnitBehavior(obj);
    m_owner->addBehaviorRef( unitBehavior );

    resInfo.resCollector = 0;
    resInfo.wrkTime = 0;
    resInfo.tg      = 0;
    resInfo.state   = ResInfo::sNo;

    buildInfo.state = BuildInfo::Null;

    Game::instance().playler( owner()->playler() ).
        addWorkerEvent( this );
    }

WorkerBehavior::~WorkerBehavior(){
    resetResource();

    m_owner->delBehaviorRef( unitBehavior );
    delete unitBehavior;

    canselBuild();

    Game::instance().playler( owner()->playler() ).
        delWorkerEvent( this );
    }

void WorkerBehavior::setPlaylerEvent(int Old, int New){
    unitBehavior->setPlaylerEvent(Old, New);

    Game::instance().playler(Old).delWorkerEvent( this );
    Game::instance().playler(New).addWorkerEvent( this );
    }

void WorkerBehavior::resetResource(){
    ResourceBehavior* r = findRes( resInfo.tg );

    if( r ){
      r->isUsed = ResourceBehavior::NoUsing;
      resInfo.tg = 0;
      }
    }

void WorkerBehavior::tick(){
    if( (!unitBehavior->isMove()) && resInfo.resCollector ){
      if( resInfo.state == ResInfo::sToResource ){
        ResourceBehavior* r = findRes( resInfo.tg );

        if( validate(r) &&
            (r->isUsed != ResourceBehavior::WorkerJob) ){
          resInfo.wrkTime = 40;
          resInfo.state = ResInfo::sWork;
          r->isUsed = ResourceBehavior::WorkerJob;
          } else {
          m_goToWork();
          }

        } else

      if( resInfo.state == ResInfo::sToCastle ){
        Game::instance().playler( owner()->playler() ).addGold(5);
        m_goToWork();
        } else

      if( resInfo.state == ResInfo::sWork ){
        resInfo.wrkTime--;
        if( resInfo.wrkTime==0 ){
          moveToCastle();
          }
        }

      }

    if( (!unitBehavior->isMove()) &&
        buildInfo.state == BuildInfo::GoToBuild ){
      if( abs(owner()->x() - buildInfo.taget[0])+
          abs(owner()->y() - buildInfo.taget[1]) < 1.5){
        startBuild();
        } else {
        canselBuild();
        }
      }

    unitBehavior->tick();
    }

void WorkerBehavior::startBuild(){
    canselBuild();
    buildInfo.state = BuildInfo::Null;

    if( !GLObject::validateLand( buildInfo.taget[0],
                                 buildInfo.taget[1],
                                 buildInfo.name ) )
      return;

    if( !Game::instance().playler(owner()->playler()).canBuy(buildInfo.name) ){
      if( owner()->playlerPtr().isDrived() ){
        const GameObjectClass* str =
            Game::instance().playler( owner()->playler() ).
            canBuyMsg(buildInfo.name);
        ShowHint::instance().addMessage( str );
        }
      return;
      }

    Game::instance().playler(owner()->playler()).buyEvent(buildInfo.name, 1);

    GLObject *obj = Game::instance().add( buildInfo.name );

    obj->setPosition( buildInfo.taget[0],
                      buildInfo.taget[1], 0);
    obj->setPlayler( owner()->playler() );
    obj->setIncompleteBuilding();

    //buildInfo.state = BuildInfo::Null;
    }

void WorkerBehavior::canselBuild(){
    if( buildInfo.state == BuildInfo::Null )
      return;

    buildInfo.state = BuildInfo::Null;
    Game::instance().playler( owner()->playler() ).
        buyEvent( buildInfo.name, 0);
    }

void WorkerBehavior::moveToCastle(){
    CentralBuildingBehavior *b =
     Game::instance().playler( owner()->playler() ).
        getCastle( Map::coordX(owner()->x()),
                   Map::coordY(owner()->y()) );

    ResourceBehavior* r = findRes( resInfo.tg );
    if( validate(r) ){
      r->isUsed = ResourceBehavior::NoUsing;

      if( b ){
        float bx = b->worldX(),
              by = b->worldY();
        Game::instance().map.findNearestf( bx, by,
                                           owner()->x(), owner()->y() );
        unitBehavior->moveCommand( bx, by, 0, 1, 0 );
        //unitBehavior->command( b->worldX(), b->worldY(), 0 );
        resInfo.state = ResInfo::sToCastle;
        }
      } else {
      m_goToWork();
      }
    }
void WorkerBehavior::goToWork(){
    unitBehavior->command( m_owner->x(), m_owner->y(), 1, 1);
    m_goToWork();
    }

void WorkerBehavior::m_goToWork(){
    ResourceBehavior* r;

    if( resInfo.state==ResInfo::sNo ){
      r = findRes( false );
      } else {

      resInfo.state = ResInfo::sNo;
      r = findResRange( true );
      if(r==0)
        r = findResRange( false );
      }

    if( r ){
      getRes(r);
      resInfo.resCollector = 1;
      }
    }

void WorkerBehavior::getRes(ResourceBehavior *r){
    if( r ){
      resInfo.taget[0] = r->x();
      resInfo.taget[1] = r->y();
      resInfo.tg       = r;

      unitBehavior->moveCommand( r->x(), r->y(), 0, 1, 0 );
      if( r->isUsed==ResourceBehavior::NoUsing )
        r->isUsed = ResourceBehavior::WorkerGo;

      resInfo.state = ResInfo::sToResource;
      }
    }

bool WorkerBehavior::validate(ResourceBehavior* r){
    return r && Map::coordX(resInfo.taget[0])==Map::coordX(r->x()) &&
                Map::coordY(resInfo.taget[1])==Map::coordY(r->y());
    }

void WorkerBehavior::deleteUnitEvent( const GLObject *obj ){
    unitBehavior->deleteUnitEvent( obj );
    }

void WorkerBehavior::command( GLObject * obj ){
    canselBuild();

    if( resInfo.taget ){
      resetResource();
      }

    if( Game::instance().map.resCountf( obj->x(), obj->y() ) ||
        obj->getBehavior("resource") ){
      resInfo.resCollector = 1;

      resInfo.taget[0] = obj->x();
      resInfo.taget[1] = obj->y();
      resInfo.tg       = findRes( false );
      m_goToWork();

      resInfo.state = ResInfo::sToResource;
      //return;
      } else {
      resInfo.resCollector = 0;
      resInfo.tg           = 0;
      resInfo.state = ResInfo::sNo;
      }

    unitBehavior->command( obj );
    }

void WorkerBehavior::command(float x, float y, int sq, bool fake){
    canselBuild();

    if( resInfo.taget ){
      resetResource();
      }

    if( Game::instance().map.resCountf(x, y) ){
      resInfo.resCollector = 1;

      resInfo.taget[0] = x;
      resInfo.taget[1] = y;
      resInfo.state    = ResInfo::sToResource;
      resInfo.tg       = findRes( false );
      m_goToWork();

      //resInfo.state = ResInfo::sToResource;
      return;
      } else {
      resInfo.resCollector = 0;
      resInfo.tg           = 0;
      resInfo.state = ResInfo::sNo;
      }

    unitBehavior->command(x, y, sq, fake);
    }

bool WorkerBehavior::needToMoveDisplace(){
    if( !(resInfo.state==ResInfo::sWork && resInfo.wrkTime!=0)  )
      return unitBehavior->needToMoveDisplace(); else
      return 0;
    }

void WorkerBehavior::setMoveDisplace(float x, float y){
    if( !(resInfo.state==ResInfo::sWork && resInfo.wrkTime!=0)  )
      unitBehavior->setMoveDisplace(x,y);
    }

bool WorkerBehavior::isBusy(){
    return ( resInfo.state != ResInfo::sNo || unitBehavior->isMove()
             || isBuilder() );
    }

bool WorkerBehavior::isBuilder(){
    return buildInfo.state!=BuildInfo::Null;
    }

ResourceBehavior* WorkerBehavior::findResRange(bool ckUsed){
    ResourceBehavior *tg = 0;
    int  len = 0;

    if( resInfo.state == ResInfo::sNo ){
      resInfo.taget[0] = owner()->x();
      resInfo.taget[1] = owner()->y();
      }

    ckUsed = !ckUsed;

    for(size_t i = 0; i<ResourceBehavior::items().size(); ++i){
      ResourceBehavior &r = *ResourceBehavior::items()[i];
      int l = abs( resInfo.taget[0]-r.x() ) +
              abs( resInfo.taget[1]-r.y() );

      if( (tg==0 || len > l) && (!r.isUsed || ckUsed ) &&
          (l < maxWrkRadius) ){
        len = l;
        tg = &r;
        }
      }

    //qDebug() << "len = " << len;

    return tg;
    }

ResourceBehavior* WorkerBehavior::findRes(bool ckUsed){
    //return 0;

    ResourceBehavior *tg = 0;
    int  len = 0;

    if( resInfo.state == ResInfo::sNo ){
      resInfo.taget[0] = owner()->x();
      resInfo.taget[1] = owner()->y();
      }

    ckUsed = !ckUsed;

    for(size_t i = 0; i<ResourceBehavior::items().size(); ++i){
      ResourceBehavior &r = *ResourceBehavior::items()[i];
      int l = abs( resInfo.taget[0]-r.x() ) +
              abs( resInfo.taget[1]-r.y() );

      if( (tg==0 || len > l) && (r.isUsed==ResourceBehavior::NoUsing
                                 || ckUsed ) ){
        len = l;
        tg = &r;
        }
      }

    return tg;
    }

ResourceBehavior* WorkerBehavior::findRes( ResourceBehavior *a ){
    for(size_t i = 0; i<ResourceBehavior::items().size(); ++i)
      if( ResourceBehavior::items()[i]==a )
        return a;

    return 0;
    }

IController* WorkerBehavior::createController(){
    return new WorkerController::Controller( owner(), this );
    }

void WorkerBehavior::serialize(FileStream &f){
    f + resInfo.taget[0] +
        resInfo.taget[1] +
        resInfo.wrkTime  +
        resInfo.resCollector;

    if( f.isIn() ){
      resInfo.tg = 0;

      int index;
      f >> index;

      if( index>=0 ){
        GLObject * obj = Game::instance().getObject(index);

        for(size_t i = 0; i<ResourceBehavior::items().size(); ++i)
          if( ResourceBehavior::items()[i]->owner()==obj )
            resInfo.tg = ResourceBehavior::items()[i];
        }

      } else {
      if( resInfo.tg )
        f << Game::instance().find( resInfo.tg->owner() ); else
        f << -1;
      }

    if( f.isIn() ){
      int state;
      f >> state;
      resInfo.state = ResInfo::State(state);

      f >> state;
      buildInfo.state = BuildInfo::State(state);
      } else {
      int state = int(resInfo.state);
      f << state;

      state = int(buildInfo.state);
      f << state;
      }

    f + buildInfo.taget[0] + buildInfo.taget[1] + buildInfo.name;


    unitBehavior->serialize(f);
    }

void WorkerBehavior::setBuild( float x, float y, const std::string &name ){
    if( !Game::instance().playler( owner()->playler() ).canBuy(name) ){
      if( owner()->playlerPtr().isDrived() ){
        const GameObjectClass* str =
            Game::instance().playler( owner()->playler() ).canBuyMsg(name);
        ShowHint::instance().addMessage( str );
        }
      return;
      }

    if( !GLObject::validateLand( x, y, name ) )
      return;

    canselBuild();
    command(x, y, 0, 0);

    buildInfo.state = BuildInfo::GoToBuild;

    buildInfo.taget[0] = x;
    buildInfo.taget[1] = y;

    buildInfo.name = name;
    Game::instance().playler( owner()->playler() ).buyEvent(name, 1);
    }


GLObject *WorkerBehavior::owner() const{
    return m_owner;
    }
