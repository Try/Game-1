#include "buildingbehavior.h"

#include "../globject.h"
#include "playler.h"

#include "control/castlecontrol.h"

#include "runtime/gameclasses.h"

#include "dataCtrl/filestream.h"
#include "hud/showhint.h"

#include "globject.h"

const AbstractBehavior::Registrator<BuildingBehavior>
  BuildingBehavior::registration( "building" );

BuildingBehavior::BuildingBehavior( GLObject *obj ):FalagOwnerBahavior(obj){
    buildTime = 0;
    isDelay   = 0;

    move.tgPos[0] = -1;
    move.tgPos[1] = -1;

    Game::instance().playler( obj->playler() ).
        addLim( -obj->getClass()->cost.lim );

    Game::instance().playler( owner()->playler() ).addBuildingsEvent( this );
    }

BuildingBehavior::~BuildingBehavior(){
    Game::instance().playler( owner()->playler() ).
        addLim( owner()->getClass()->cost.lim );
    Game::instance().playler( owner()->playler() ).delBuildingsEvent( this );
    }

void BuildingBehavior::upsetPointFlagPos(){
    if( point_flag ){
      if( move.taget ){
        if( move.taget!=owner() )
          point_flag->setPosition( move.taget->x(), move.taget->y(), 0 );  else
          point_flag->setPosition(0, 0, -100);
        } else
        point_flag->setPosition( move.tgPos[0],   move.tgPos[1], 0 );
      }
    }

void BuildingBehavior::setPlaylerEvent(int Old, int New){
    Game::instance().playler( Old ).
        addLim( owner()->getClass()->cost.lim );
    Game::instance().playler( Old ).delBuildingsEvent( this );

    Game::instance().playler( New ).
        addLim( -owner()->getClass()->cost.lim );
    Game::instance().playler( New ).addBuildingsEvent( this );
    }

int BuildingBehavior::x(){
    return Map::coordX(owner()->x());
    }

int BuildingBehavior::y(){
    return Map::coordY(owner()->y());
    }

float BuildingBehavior::worldX(){
    return owner()->x();
    }

float BuildingBehavior::worldY(){
    return owner()->y();
    }

IController* BuildingBehavior::createController(){
    return new CastleControl::Controller( this );
    }

int BuildingBehavior::buildQueueSize(){
    return queue.size();
    }

void BuildingBehavior::buildByController( const std::string &s ){
    GLObject *taget = 0;
    for( unsigned i=0; i<Game::instance().selected().size(); ++i ){

      if( Game::instance().selected()[i]->getClass()==owner()->getClass() ){
        int queue = Game::instance().selected()[i]->buildQueueSize();

        if( taget==0 || (taget->buildQueueSize() > queue ) ){
          taget = Game::instance().selected()[i];
          }
        }

      }

    if( taget ){
      BuildingBehavior* b = (BuildingBehavior*)taget->getBehavior( name() );

      if(b)
        b->build(s);
      }
    }

void BuildingBehavior::build( const std::string &s ){
    if( !Game::instance().playler( owner()->playler() ).canBuy(s) ){
      if( owner()->playlerPtr().isDrived() ){
        const GameObjectClass* str =
            Game::instance().playler( owner()->playler() ).canBuyMsg(s);
        ShowHint::instance().addMessage( str );
        }
      return;
      }

    {
      bool ok = 0;
      for(unsigned i=0; i<owner()->getClass()->recruts.size(); ++i){
        if( owner()->getClass()->recruts[i].name==s )
          ok = 1;
        }

      if( !ok )
        return;
      }

    if( queue.size() < 6 ){
      queue.push_back( s );//FIXME
      Game::instance().playler( owner()->playler() ).buyEvent(s, 1);
      }

    if(queue.size()==1){
      maxBuildTime = GameClasses::get( queue[0] )->buildTime;
      buildTime = maxBuildTime;
      }
    }

void BuildingBehavior::createObject( const std::string &name ){
    GLObject *obj = Game::instance().add( name );

    float wx = owner()->x(),
          wy = owner()->y();

    Game::instance().map.findNearestf( wx, wy,
                                       move.tgPos[0], move.tgPos[1] );

    obj->setPosition( wx, wy, 0 );

    if( move.taget ){
      obj->command( move.taget );
      } else

    if( move.tgPos[0]>=0 && move.tgPos[1]>=0 ){
      obj->command(move.tgPos[0], move.tgPos[1], 0, 0);
      }

    obj->setPlayler( owner()->playler() );
    }

void BuildingBehavior::tick(){
    upsetPointFlagPos();

    if( !isDelay && buildTime ){
      --buildTime;
      } else
    if( queue.size() ){
      if( !isDelay ){
        createObject( queue.front() );
        queue.erase( queue.begin() );
        }

      if( queue.size() ){
        isDelay = !Game::instance().playler(owner()->playler()).
                   canBuyByLim( queue.front() );

        maxBuildTime = GameClasses::get( queue[0] )->buildTime;
        buildTime = maxBuildTime;
        } else {
        isDelay = 0;
        }

      }
    }

float BuildingBehavior::progressBar(){
    if( queue.size() )
      return 1.0 - buildTime/(float)maxBuildTime; else
      return 0.0;
    }

void BuildingBehavior::command(float x, float y, int, bool){
    move.tgPos[0] = std::max(x, 0.0f);
    move.tgPos[1] = std::max(y, 0.0f);
    move.taget    = 0;

    if( point_flag )
      point_flag->setPosition( move.tgPos[0], move.tgPos[1], 0 );
    }

void BuildingBehavior::positionEvent(float x, float y){
    move.tgPos[0] = x;
    move.tgPos[1] = y;
    }

std::vector< std::string >& BuildingBehavior::buildQueue(){
    return queue;
    }

void BuildingBehavior::removeFromQueue(int id){
    Game::instance().playler( owner()->playler() ).buyEvent(queue[id], 0);

    queue.erase( queue.begin()+id );
    if(id==0){
      if( queue.size() ){
        maxBuildTime = GameClasses::get( queue[0] )->buildTime;
        buildTime = maxBuildTime;
        }
      }
    }

const GameObjectClass& BuildingBehavior::ownerClass(){
    return *owner()->getClass();
    }

void BuildingBehavior::serialize(FileStream &f){
    f + buildTime  +
        maxBuildTime  + isDelay;
    serialize_flag(f);

    if( f.isIn() ){
      int size;
      f >> size;
      queue.resize(size);
      } else {
      int size = queue.size();
      f << size;
      }

    for(unsigned i=0; i<queue.size(); ++i)
      f + queue[i];
    }
