#include "warriorbehavior.h"

#include "game.h"

#include "dataCtrl/filestream.h"
#include "globject.h"

#include "game/game.h"
#include "game/unitbehavior.h"
#include "globject.h"

#include "runtime/atacktypes.h"
#include "game/utils/spatialindex.h"
#include "graphis/bulletobject.h"

#include "game/playler.h"

#include <cmath>

using namespace std;

const AbstractBehavior::Registrator<WarriorBehavior>
  WarriorBehavior::registration( "warrior" );

WarriorBehavior::WarriorBehavior( GLObject * obj,
                                  UnitBehavior *u ){
    setName("warrior");

    taget.unit = 0;

    owner = obj;
    owner->addBehaviorRef(this);

    unit  = u;

    atkRange = 10;
    atkRange*=atkRange;

    m_isAtack  = 0;
    atackDelay = 0;

    atkReclcTime = 0;
    m_isAclick   = 0;

    m_isFight = 0;

    atkVal = owner->getClass()->atack;
    }

WarriorBehavior::~WarriorBehavior(){
    owner->delBehaviorRef(this);

    }

void WarriorBehavior::deleteUnitEvent( const GLObject *obj ){
    if( taget.unit==obj )
      taget.unit = 0;
    }

bool WarriorBehavior::isAtack(){
    return m_isAtack;
    }

bool WarriorBehavior::filterFunc(GLObject* tst, GLObject *caller){
    return tst->playler()!=caller->playler();
    }

bool WarriorBehavior::filterFuncWrk(GLObject* tst, GLObject *caller){
    return tst->playler()!=caller->playler() &&
           (tst->getClass()->speed > 0);
    }

bool WarriorBehavior::filterFuncUnit(GLObject* tst, GLObject *caller){
    return tst->playler()!=caller->playler() &&
           tst->getClass()->atack.isAgressor;
    }

bool WarriorBehavior::isAClick(){
    return m_isAclick;
    }

void WarriorBehavior::setAClick(bool a, float x, float y){
    m_isAclick = a;

    aClickStk.x = x;
    aClickStk.y = y;
    }

void WarriorBehavior::moveTo(float x, float y, bool fake ){
    int s = aClickStk.size;
    bool pA  = m_isAtack;
    bool pAc = m_isAclick;

    if( unit )
      unit->moveCommand( x, y, 0, fake, 0 );

    aClickStk.size = s;
    m_isAtack  = pA;
    m_isAclick = pAc;
    }

void WarriorBehavior::moveToAtack( GLObject *dest ){/*
    float vec[2] = {dest->x() - owner->x(),
                    dest->y() - owner->y() };
    float l  = sqrt(vec[0]*vec[0] + vec[1]*vec[1]);
    float l1 = l - owner->getClass()->atack.land_land.atackRange;
    l = l1/l;
    vec[0] *= l;
    vec[1] *= l;

    if( isAClick() && unit )
      aClickStk.push();

    moveTo( owner->x()+vec[0],
            owner->y()+vec[1] );*/

    if( isAClick() && unit )
      aClickStk.push();
    moveTo( dest->x(),
            dest->y(), 0 );

    atkReclcTime = 5;
    }

void WarriorBehavior::standAndFight( GLObject *dest ){/*
    if( unit==0 || !unit->isMvDisplace() ){
      if( unit && !unit->isMove() ){
        aClickStk.push();
        }

      }*/
    atack( *dest );

    if( unit ){
      aClickStk.push();
      unit->rotateTo( dest->x(), dest->y() );
      unit->stopMove();
      }
    }

GLObject *WarriorBehavior::findEnemy(){
    GLObject * dest = 0;
    dest = SpatialIndex::instance()->findNearest(owner, filterFuncUnit);

    if( !(dest && canAtack( *dest )) ){
      dest = SpatialIndex::instance()->findNearest(owner, filterFuncWrk );
      }

    if( !(dest && canAtack( *dest )) ){
      dest = SpatialIndex::instance()->findNearest(owner, filterFunc);
      }

    return dest;
    }

void WarriorBehavior::tick(){
    if( !owner->getClass()->atack.isAgressor &&
        !(isAClick() || isAtack() ) )
      return;

    if( atackDelay )
      --atackDelay;

    if( atackDelay )
      return;

    if( atkReclcTime )
      --atkReclcTime;

    if( ( !isAClick() || !isAtack() ) &&
        (unit && unit->isMove() && atkReclcTime) ){
      return;
      }

    m_isFight = 0;

    GLObject * dest = findEnemy();
    float dist = 0;

    if( dest && dest->playler() != owner->playler() ){
      dist = distance( *dest );
      } else {
      dest = 0;
      }

    if(  dest && canAtack( *dest ) &&
         (!unit || (!unit->isMove() || isAtack() || isAClick() )) ){
      if( checkAtack( dist, dest) ){
        moveToAtack(dest);
        } else  {
        standAndFight( dest );
        m_isFight = 1;
        }

      m_isAtack = 1;
      } else {
      if( isAClick() && unit && aClickStk.size ){
        moveTo( aClickStk.x, aClickStk.y, false );
        aClickStk.pop();
        }
      m_isAtack = 0;
      }

    }

void WarriorBehavior::command(const GLObject *){
    m_isAtack  = 0;
    m_isAclick = 0;
    aClickStk.size = 0;
    }

void WarriorBehavior::command(float, float, int, bool){
    command(0);
    }

void WarriorBehavior::moveCommand(float x, float y, int sq, bool f, bool user){
    if( user ){
      command(x, y, sq, f);
      } else {
      m_isAtack  = 0;
      }
    }

void WarriorBehavior::setAtack(bool a){
    m_isAtack = a;
    atkReclcTime = 5;
    }

bool WarriorBehavior::isFight(){
    return m_isFight;
    }

bool WarriorBehavior::checkAtack( float dist, const GLObject* dest ){
    double atkRange = 1+atkVal.land_land.atackRange;

    if( dest->getClass()->mvLock ){
      return (dist > (owner->viewSize()+dest->viewSize())//*1.4
                     + atkRange*atkRange);
      }

    return (dist > (owner->viewSize()+dest->viewSize())*0.9
                   + atkRange*atkRange);
    }

IController* WarriorBehavior::createController(){
    return 0;
    }

void WarriorBehavior::serialize(FileStream &f){
    f + atkRange + m_isAtack + atackDelay + m_isAclick +
        aClickStk.x + aClickStk.y + aClickStk.size;
    }

bool WarriorBehavior::canAtack( const GLObject& obj ){
    float d = distance(obj);

    return d<=atkRange;
    }

float WarriorBehavior::distance( const GLObject& obj ){
    float dx = obj.x() - owner->x(),
          dy = obj.y() - owner->y();

    return dx*dx + dy*dy;
    }

void WarriorBehavior::atack( GLObject& obj ){
    obj.playlerPtr().ourTroopsIsUnderAttack( &obj );

    float k = AtackTypes::get( owner->getClass()->atkType,
                               obj.getClass()   ->armoType );

    float myAtack = atkVal.land_land.damage +
                    owner->playlerPtr().grades()[owner->getClass()->atkType];
    myAtack*=k;

    double atkRange = atkVal.land_land.atackRange;

    if( atkRange > owner->viewSize()+1 ){
      obj.reciveBullet( atkVal.land_land.bullet )->
          setEmitter( owner   ).
          setDamage ( myAtack );
      } else {
      obj.hp( obj.hp() - myAtack );
      }

    atackDelay = atkVal.land_land.time;
    }

WarriorBehavior::AClickStoreBuf::AClickStoreBuf(){
    size = 0;
    }

void WarriorBehavior::AClickStoreBuf::push(){
    size = 1;
    }

void WarriorBehavior::AClickStoreBuf::pop(){
    size = 0;
    }
