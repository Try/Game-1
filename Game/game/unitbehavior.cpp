#include "unitbehavior.h"

#include <cmath>
#include "../globject.h"

#include "movealgo.h"

#include <QDebug>

#include "control/unitctrl.h"
#include "game/playler.h"
#include "game/warriorbehavior.h"

using namespace std;

#include "dataCtrl/filestream.h"

const AbstractBehavior::Registrator<UnitBehavior>
  UnitBehavior::registration( "unit" );

UnitBehavior::UnitBehavior(GLObject *obj)
             :owner(obj), moveSpeed(obj->getClass()->speed){
    setName("unit");

    moveVec[0] = 0;
    moveVec[1] = 0;

    taget.unit = 0;
    taget.pos[0] = 0;
    taget.pos[1] = 0;

    wasMoveDisplace = 0;

    dAngle     = owner->rotateAngle();

    rotateSpeed = 25;

    m_isMove    = 0;
    wayLen      = 0;

    wayErrors   = 0;
    isMoveDelay = 0;
    isFake  = 0;

    Game::instance().playler( owner->playler() ).
        addLim( -owner->getClass()->cost.lim );

    warrior = new WarriorBehavior( obj, this );
    owner->addBehaviorRef(warrior);
    }

UnitBehavior::~UnitBehavior(){
    Game::instance().playler( owner->playler() ).
        addLim( owner->getClass()->cost.lim );

    owner->delBehaviorRef(warrior);
    delete warrior;
    }

void UnitBehavior::setPlaylerEvent(int Old, int New){
    Game::instance().playler( Old ).
        addLim( owner->getClass()->cost.lim );

    Game::instance().playler( New ).
        addLim( -owner->getClass()->cost.lim );
    }

WarriorBehavior *UnitBehavior::getWarrior(){
    return warrior;
    }

void UnitBehavior::rotateTo(float x, float y){
    dAngle = 180.0*atan2( y-owner->y(), x-owner->x() )/M_PI;
    }

void UnitBehavior::setRAngle(float a){
    dAngle = a;
    }

void UnitBehavior::rotate(){
    if( fabs(owner->rotateAngle()-dAngle) > rotateSpeed ){
      float a;
      if( sin( M_PI*(owner->rotateAngle() - dAngle)/180.0 ) < 0.0 )
        a = ( owner->rotateAngle() + rotateSpeed ); else
        a = ( owner->rotateAngle() - rotateSpeed );

      if( a>=180 )
        a = ( a - 360 );
      if( a<-180 )
        a = ( a + 360 );

      owner->setRotate( a );
      } else {
      if( owner->rotateAngle() != dAngle )
        owner->setRotate( dAngle );
      }
    }

bool UnitBehavior::canMove(float x, float y){
    float ox = owner->x(),
          oy = owner->y();
    if( !(Game::instance().map.existf   ( ox,oy ) &&
          Game::instance().map.isEnablef( ox,oy) ) ){
      return 1;
      }

    return Game::instance().map.existf   ( x,y ) &&
           Game::instance().map.isEnablef( x,y);
    }

bool UnitBehavior::calcNextPos(float &x, float &y, float l){
    if( !wasMoveDisplace ){
      float qspeed = moveVec[0]*moveVec[0]+moveVec[1]*moveVec[1];
      if( sqrDistanceToTaget() <= l*qspeed ){
        x = taget.pos[0];
        y = taget.pos[1];

        if( nextStep() && wayLen ){
          float nl = l - sqrt( sqrDistanceToTaget()/qspeed );
          if( nl<1.0 && nl > 0.0 )
            return calcNextPos(x,y, nl); else
            return 1;
          } else
          return 1;
        }
      }

    x = x/*owner->x()*/ + l*moveVec[0];
    y = y/*owner->y()*/ + l*moveVec[1];
    return 0;//(wayLen>moveSpeed ) || way.size();
    }

void UnitBehavior::reposition(){
    if( way.size()==1 )
      return;

    MoveAlgo( Game::instance().map ).releace(way);

    int x = Map::coordX( owner->x() ),
        y = Map::coordY( owner->y() );

    Game::instance().map.findNearest(x, y);

    way.push_back( MoveAlgo::Point(x, y) );
    wayPach();
    }

void UnitBehavior::tick(){
    warrior->tick();

    {
      float ox = owner->x(),
            oy = owner->y();
      if( !(Game::instance().map.existf   ( ox,oy ) &&
            Game::instance().map.isEnablef( ox,oy) ) ){
        reposition();
        }
      }

    rotate();

    if( wasMoveDisplace ){
      taget.pos[0] = owner->x()+moveVec[0];
      taget.pos[1] = owner->y()+moveVec[1];

      normalize( moveVec[0], moveVec[1], moveSpeed );

      float nx = owner->x(), ny = owner->y();
      calcNextPos(nx, ny);

      if( canMove(nx, ny) ){
        calcAngle();
        wayLen   = 0;
        m_isMove = 1;
        } else {
        moveVec[0] = 0;
        moveVec[1] = 0;
        }
      }

    if( isMove() ){
      const float prdV[2] = { moveVec[0],
                              moveVec[1] };

      float nx = owner->x(), ny = owner->y();
      bool ns = calcNextPos(nx, ny);

      if( !isMoveDelay ){
        if( canMove(nx, ny) ){
          wayLen -= ( fabs(owner->x()-nx)+fabs(owner->y()-ny) );
          owner->setPosition( nx, ny, 0);

          if( ns ){
            m_isMove = nextStep();
            } else {
            m_isMove = (wayLen>moveSpeed ) || way.size();
            }

          if( wayErrors )
            --wayErrors;

          } else {
          if( wayErrors<16 ){
            correctWay();
            } else {
            wayErrors = 0;
            MoveAlgo( Game::instance().map ).releace(way);

            m_isMove = 0;
            moveVec[0] = 0;
            moveVec[1] = 0;
            qDebug() << "Way Error";
            }
          qDebug() << "Way Recalc "<< moveVec[0]  <<" "<<moveVec[1] << " "
                   << wayErrors;
          wayErrors += 2;
          }
        }

      if( isMoveDelay ){
        moveVec[0] = prdV[0];
        moveVec[1] = prdV[1];
        isMoveDelay = 0;
        }
      } else {
      moveToTagetUnit();
      }


    if( wasMoveDisplace ){
      wasMoveDisplace = 0;
      m_isMove = 0;//way.size();

      moveVec[0] = 0;
      moveVec[1] = 0;

      taget.pos[0] = owner->x();
      taget.pos[1] = owner->y();
      }
    }

void UnitBehavior::correctWay(){
    //bool w = warrior->isAtack();
    if( way.size() )
      moveCommand( way[0].x/2.0,  way[0].y/2.0, 0, 0 ); else
      moveCommand( taget.pos[0],  taget.pos[1], 0, 0 );
    //warrior->setAtack(w);
    }

bool UnitBehavior::nextStep(){
    if( taget.unit ){
      return moveToTagetUnit();
      }

    if( way.size() ){
      wayPach();
      return 1;
      } else {
      moveVec[0] = 0;
      moveVec[1] = 0;
      wayLen     = 0;
      return 0;
      }
    }

bool UnitBehavior::moveToTagetUnit(){
    if( taget.unit ){
      if( sqr(taget.unit->x() - owner->x())+
          sqr(taget.unit->y() - owner->y()) >
          sqr( (taget.unit->viewSize() + owner->viewSize())*2.0 ) )
        if( !warrior->isAtack() ){
          moveCommand( taget.unit->x(), taget.unit->y(), 1, 0);
          if( way.size() )
            warrior->setAClick( 1, Map::coordWX(way[0].x),
                                   Map::coordWY(way[0].y) );
          return way.size();
          }

      }

    return 0;
    }

void UnitBehavior::normalize(float &x, float &y, float w){
    float l = sqrt( x*x+y*y );

    if( l>0.0000001 ){
      x/=l;
      y/=l;

      x*=w;
      y*=w;
      }
    }

void UnitBehavior::wayPach(float x, float y){
    taget.pos[0] = x;
    taget.pos[1] = y;

    wasMoveDisplace = 0;
    m_isMove        = 1;

    moveVec[0] = x - owner->x();
    moveVec[1] = y - owner->y();

    wayLen = (fabs(moveVec[0])+fabs(moveVec[1]));

    normalize( moveVec[0], moveVec[1], moveSpeed );

    calcAngle();
    }

void UnitBehavior::wayPach(){
    if( way.size() ) {
      wayLen = 0;
      int mx = Map::coordX( owner->x() ),
          my = Map::coordY( owner->y() );

      bool loop = 1;
      while( way.size() &&
             loop ){
        loop = mx==way.back().x &&
               my==way.back().y;
        wayPach( Map::coordWX(way.back().x),
                 Map::coordWY(way.back().y) );
        way.pop_back();
        }

      }
    }

void UnitBehavior::moveCommand(float x, float y, int sq, bool fake, bool user){
    isFake = fake;

    if( user ){
      taget.unit = 0;
      }
/*
    if( way.size() &&
        abs(way[0].x - Map::coordX(x)) +
        abs(way[0].y - Map::coordY(y)) < 3 ){
      qDebug() << "way already calculated";
      if( !isMove() ){
        m_isMove = 1;
        wayPach();
        }
      } else */{
      warrior->moveCommand(x, y, sq, fake, user);

      if( fake ){
        int rx = Map::coordX(x),
            ry = Map::coordY(y);
        MoveAlgo algo( Game::instance().map );
        algo.releace(way);

        if( Game::instance().map.isEnablef(x, y) ){
          way.push_back( MoveAlgo::Point(x, y) );
          } else {
          algo.correctInput(rx, ry);
          way.push_back( MoveAlgo::Point( Map::coordWX(rx),
                                          Map::coordWY(ry) ) );
          }

        wayPach();
        m_isMove = 1;
        } else {
        MoveAlgo move( Game::instance().map );

        if( Game::instance().map.groupf(x,y)==
            Game::instance().map.groupf(owner->x(), owner->y() )){
          move.releace(way);
          //way.push_back( MoveAlgo::Point(owner->x(), owner->y()) );
          way.push_back( MoveAlgo::Point(x,y) );
          wayPach();
          m_isMove = 1;
          } else {
          move.wayf( x, y, owner->x(), owner->y(), sq );
          move.getWayf(way, owner->x(), owner->y() );

          wayPach();
          m_isMove = 1;
          }
        }

      if( way.size() ){
        way.front().x = Map::coordX(x);
        way.front().y = Map::coordY(y);
        }
      }


    isMoveDelay = 0;
    wasMoveDisplace = 0;
    }

void UnitBehavior::command(float x, float y, int sq, bool fake){
    moveCommand(x, y, sq, fake, true);
    }

void UnitBehavior::command( GLObject* obj ){
    if( obj ){
      moveCommand( obj->x(), obj->y(), 1, 0, true);
      }
    taget.unit = obj;
    }

void UnitBehavior::deleteUnitEvent( const GLObject * obj ){
    if( taget.unit==obj )
      taget.unit = 0;
    }

bool UnitBehavior::isMvDisplace(){
    return wasMoveDisplace;
    }

MoveAlgo::Point UnitBehavior::getTagetPoint(){
    if( !isMove() )
      return MoveAlgo::Point( owner->x(), owner->y() );

    if( way.size() )
      return way[0];

    return MoveAlgo::Point(taget.pos[0], taget.pos[1]);
    }

void UnitBehavior::calcAngle(){
    if( warrior->isFight() )
      return;

    if( moveVec[0]!=0 || moveVec[1] !=0 )
      dAngle = 180.0*atan2(moveVec[1], moveVec[0])/M_PI;
    }

bool UnitBehavior::needToMoveDisplace(){
    return (!isMove() || warrior->isAtack() ) && !wasMoveDisplace;
    }

float UnitBehavior::sqrDistanceToTaget() const{
    return sqr(taget.pos[0] - owner->x() ) + sqr(taget.pos[1] - owner->y() );
    }

void UnitBehavior::setMoveDisplace(float x, float y){
    if( needToMoveDisplace() ){
      moveVec[0] = x*moveSpeed;
      moveVec[1] = y*moveSpeed;

      if( isMove() && !wasMoveDisplace ){
        int mx = Map::coordX( taget.pos[0] ),
            my = Map::coordY( taget.pos[1] );
        way.push_back( MoveAlgo::Point(mx, my) );
        wayLen = sqrt(x*x+y*y)*moveSpeed;
        }

      wasMoveDisplace = 1;
      }
    }

float UnitBehavior::sqr(float x){
    return x*x;
    }

bool UnitBehavior::isMove(){
    return m_isMove;
    }

IController* UnitBehavior::createController(){
    return new UnitCtrl::Controller();
    }

void UnitBehavior::serialize(FileStream &f){
    f + moveVec[0] +
        moveVec[1] +
        taget.pos[0] +
        taget.pos[1] +
        dAngle +
        wayLen +
        wasMoveDisplace + m_isMove + isMoveDelay +
        wayErrors +
        rotateSpeed;

    if( f.isIn() ){
      int size;
      f >> size;
      way.resize(size, MoveAlgo::Point(0,0) );
      } else {
      int size = way.size();
      f << size;
      }

    for(unsigned i=0; i<way.size(); ++i)
      f + way[i].x + way[i].y;
    }

void UnitBehavior::holdPosition(){

    }

void UnitBehavior::stopMove(){
    MoveAlgo( Game::instance().map ).releace(way);

    taget.pos[0] = owner->x();
    taget.pos[1] = owner->y();

    moveVec[0] = 0;
    moveVec[1] = 0;

    m_isMove = 0;
    wasMoveDisplace = 0;
    }
