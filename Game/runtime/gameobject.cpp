#include "gameobject.h"

#include "gameclasses.h"
#include "gameobjectclass.h"

#include <QDebug>

#include "../game/abstractbehavior.h"

#include "game/playler.h"

#include "game/centralbuildingbehavior.h"
#include "game/workerbehavior.h"

#include "globject.h"

unsigned long long GameObject::newHash = 0;

GameObject::GameObject(const char* pattern){
    const GameObjectClass * c = GameClasses::get( pattern );
    pat = c;

    if( c==0 ){
      qDebug() << "warning: no pattern to " << pattern;
      return;
      }

    // copy( *c );

    Game::instance().playler(0).addUnitEvent( (GLObject*)this );
    pl = 0;

    setPlayler(0);
    m_hp = 1;
    hp( getClass()->maxHp );

    hashCode = newHash;
    ++newHash;
    }

GameObject::~GameObject(){
    Game::instance().playler( pl ).delUnitEvent( (GLObject*)this );
    behaviors.clear();
    }

const GameObjectClass * GameObject::getClass( const std::string &n){
    return GameClasses::get( n );
    }

const GameObjectClass* GameObject::getClass() const{
    return pat;
    }

const std::string GameObject::className() const{
    if( pat )
      return pat->name; else
      return "null_class";
    }

Game& GameObject::game(){
    return Game::instance();
    }

unsigned long long GameObject::getHashCode(){
    return hashCode;
    }

int GameObject::playler() const{
    return pl;
    }

void GameObject::setPlayler(int p){

    Game::instance().playler(pl).delUnitEvent( (GLObject*)this );
    behaviors.setPlaylerEvent(pl, p);
    Game::instance().playler(p ).addUnitEvent( (GLObject*)this );

    pl = p;
    setPlaylerEvent();
    }

Playler& GameObject::playlerPtr() {
    return game().playler( pl );
    }

int GameObject::hp() const{
    return m_hp;
    }

void GameObject::hp(int x) {
    //if( m_hp >=0 ){
      m_hp = x;
    //  }
    }

bool GameObject::HashCompare::operator() ( const BuildingBehavior* const& a,
                                           const BuildingBehavior* const& b ){
    return (*this)( a->owner(), b->owner() );
    }

bool GameObject::HashCompare::operator()
                            ( const CentralBuildingBehavior* const& a,
                              const CentralBuildingBehavior* const& b ){
  return (*this)( a->owner(), b->owner() );
  }

bool GameObject::HashCompare::operator()
                            ( const WorkerBehavior* const& a,
                              const WorkerBehavior* const& b ){
  return (*this)(a->owner(), b->owner() );
  }

bool GameObject::HashCompare::operator()
                            ( const GameObject* const& a,
                              const GameObject* const& b ){
  return ( a->hashCode > b->hashCode );
  }

AbstractBehavior* GameObject::getBehavior( const std::string& n){
    for( size_t i=0; i<refs.size(); ++i)
      if( refs[i]->name()==n ){
        return refs[i];
        }
    return behaviors.getBehavior(n);
    }

void GameObject::addBehaviorRef( AbstractBehavior* b){
    refs.push_back( b );
    }

void GameObject::delBehaviorRef( AbstractBehavior* b){
    for( size_t i=0; i<refs.size(); ++i)
      if( refs[i]==b ){
        refs[i] = refs.back();
        refs.pop_back();
        }
    }
