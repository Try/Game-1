#include "playler.h"

#include "centralbuildingbehavior.h"

#include "globject.h"
#include "dataCtrl/filestream.h"

#include "game/ai/bot.h"

#include "runtime/gameclasses.h"
#include "hud/showhint.h"

#include <QDebug>

const QColor Playler::plColors[] = {
    QColor(128, 128, 128), //[0]
    QColor(255, 255,   0), //[1]
    QColor(  0, 255,   0), //[2]
    QColor(  0,   0, 255), //[3]
    QColor(255,   0,   0), //[4]
    QColor(255,   0, 255), //[5]
    QColor(  0, 255, 255), //[6]
    QColor(255, 255, 255), //[7]
    QColor( 25,  25,  25), //[8]
    };

Playler::Playler( Game & , int game_id ){
    m_gold = 50;
    m_lim  = 0;
    id = game_id;

    drived = 0;
    active = 1;
    showAtkTime = 0;

    m_color = plColors[game_id];

    bot = new Bot( *this );

    // qDebug() << m_color;
    memset(&m_grades, 0x0, sizeof(m_grades) );

    m_grades.resize();
    }

Playler::~Playler(){
    delete bot;
    }

void Playler::addCentralBuilding(CentralBuildingBehavior & x){
    cas.push_back( &x );
    }

void Playler::delCentralBuilding(CentralBuildingBehavior & x){
    for(size_t i = 0; i<cas.size(); ++i){
      if( cas[i]==&x ){
        cas[i] = cas.back();
        cas.pop_back();
        return;
        }
      }
    }

void Playler::addBuildingsEvent( BuildingBehavior * obj ){
    if( !isDrived() )
      bot->addBuildingsEvent(obj);
    }

void Playler::delBuildingsEvent( BuildingBehavior * obj ){
    if( !isDrived() )
      bot->delBuildingsEvent(obj);
    }

const AtackTypes::AtkTypeSet<int>& Playler::grades(){
    return m_grades;
    }

CentralBuildingBehavior* Playler::getCastle(int x, int y){
    int rx, ry, rl = 0;
    CentralBuildingBehavior *ret = 0;

    for(size_t i=0; i<cas.size(); ++i){
      int l = abs( x-cas[i]->x() ) + abs( y-cas[i]->y() );
      if( ret==0 || l<rl ){
        rx = cas[i]->x();
        ry = cas[i]->y();
        rl = l;
        ret = cas[i];
        }
      }

    return ret;
    }

void Playler::addGold(int v){
    m_gold += v;
    }

int  Playler::gold(){
    return m_gold;
    }

void Playler::addLim(int v){
    m_lim += v;
    }

int  Playler::lim(){
    return m_lim;
    }

bool Playler::canBuyByLim( const std::string &s ){
    return GLObject::getClass(s)->cost.lim <=  lim();
    }

bool Playler::canBuy( const std::string &s ){
    const GameObjectClass *c = GLObject::getClass(s);

    for( size_t i=0; i<c->needs.size(); ++i ){
      if( counter.countOf( c->needs[i] )==0 )
        return 0;
      }

    return  ( c->cost.gold <= gold() &&
             (c->cost.lim <=0 ||
              c->cost.lim <=  lim()) );
    }

const GameObjectClass* Playler::canBuyMsg( const std::string &s ){
    const GameObjectClass *c = GLObject::getClass(s);

    const GameObjectClass *result = 0;
    for( size_t i=0; i<c->needs.size(); ++i ){
      if( counter.countOf( c->needs[i] )==0 )
        result = GameClasses::get("no_conditions"); //return 0;
      }

    if( !result && !(c->cost.gold <= gold()) ){
      result = GameClasses::get("no_minerals");
      }

    if( !result && !(c->cost.lim <=0 || c->cost.lim <=  lim()) ) {
      result = GameClasses::get("no_pilons");
      }

    if( !result ) {
      result = GameClasses::get("no_place");
      }

    if( result ){
      return result;
      }

    {
      return 0;
      }
    }

void Playler::buyEvent( const std::string &s, bool ok ){
    int m = 1;
    if( ok )
      m = -1;

    addGold( m*GLObject::getClass(s)->cost.gold );
    // addLim ( m*GLObject::getClass(s)->cost.lim  );
    }

bool Playler::isDrived(){
    return drived;//id==1;
    }

void Playler::setDrived(bool d){
    drived = d;
    }

void Playler::setActive(bool a){
    active = a;
    }

void Playler::setLevel(int l){
    if( !isDrived() )
      bot->setSkil(l);
    }

int  Playler::level(){
    if( isDrived() )
      return 2; else
      return bot->skilLevel();
    }

bool Playler::isActive(){
    return active;
    }

QColor Playler::color(){
    return m_color;
    }

void Playler::serialize(FileStream &f){
    f + m_gold + drived + active;

    m_grades.serialize(f);
    if( !isDrived() )
      bot->serialize(f);
    }

void Playler::tick(){
    if( isDrived() )
      tickDrived(); else
      tickBot();
    }

void Playler::tickDrived(){
    if(showAtkTime)
      --showAtkTime;
    }

void Playler::tickBot(){
    bot->tick();
    }


void Playler::addIncompleteUnitEvent( GLObject * obj ){
    halfCounter.add( obj->getClass() );
    }

void Playler::delIncompleteUnitEvent( GLObject * obj ){
    halfCounter.del( obj->getClass() );
    }

void Playler::addUnitEvent( GLObject * obj ){
    if( !isDrived() )
      bot->addUnitEvent(obj);

    counter.add( obj->getClass() );
    }

void Playler::delUnitEvent( GLObject * obj ){
    if( !isDrived() )
      bot->delUnitEvent(obj);

    counter.del( obj->getClass() );
    }

int Playler::countOfIncom( const std::string &cName ){
    return halfCounter.countOf( GameClasses::get( cName) );
    }

int Playler::countOf( const std::string &cName ){
    return counter.countOf( GameClasses::get( cName) );
    }

int Playler::countOfall( const std::string &s ){
    return countOf(s)+countOfIncom(s);
    }


void Playler::addWorkerEvent( WorkerBehavior * obj ){
    if( !isDrived() )
      bot->addWorkerEvent(obj);
    }

void Playler::delWorkerEvent( WorkerBehavior * obj ){
    if( !isDrived() )
      bot->delWorkerEvent(obj);
    }

void Playler::addCastleEvent( CentralBuildingBehavior * obj ){
    if( !isDrived() )
      bot->addCastleEvent(obj);
    }

void Playler::delCastleEvent( CentralBuildingBehavior * obj ){
    if( !isDrived() )
      bot->delCastleEvent(obj);
    }

void Playler::ourTroopsIsUnderAttack( GLObject * obj ){
    if( isDrived() ){
      if( showAtkTime==0 ){
        ShowHint::instance().addMessage( GameClasses::get("atackEvent" ) );
        showAtkTime = 50;
        }
      } else {
      bot->atackEvent( obj );
      }
    }


void Playler::makeGrade( const GameObjectClass::Atack& val,
                         const AtackTypes::AtkType& t ){
    m_grades[t] += val.land_land.damage;
    }

int  Playler::maxLim(){
    return -(countOf("house") *GameClasses::get("house" )->cost.lim+
             countOf("castle")*GameClasses::get("castle")->cost.lim);
    }
