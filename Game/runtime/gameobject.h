#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>

#include "gameobjectclass.h"
#include "../game/game.h"

class CentralBuildingBehavior;
class BuildingBehavior;
class WorkerBehavior;
class Playler;

#include "../game/behaviorcollection.h"

class GameObject {
  public:
    GameObject(const char* pattern);
    ~GameObject();

    const GameObjectClass * getClass() const;
    static const GameObjectClass * getClass( const std::string &);
    const std::string className() const;

    virtual void  command(float , float ){}
    virtual void  tick(){}
    virtual void  setSel(bool ){}
    virtual void  setSelSize(float){}

    Game& game();

    int   playler() const;
    void setPlayler(int pl);

    Playler& playlerPtr() ;

    int hp() const;
    void  hp(int );

    class HashCompare{
      public:
        bool operator() ( const BuildingBehavior* const& a,
                          const BuildingBehavior* const& b );

        bool operator() ( const CentralBuildingBehavior* const& a,
                          const CentralBuildingBehavior* const& b );

        bool operator() ( const WorkerBehavior* const& a,
                          const WorkerBehavior* const& b );

        bool operator() ( const GameObject* const& a,
                          const GameObject* const& b );
      };

    void addBehaviorRef( AbstractBehavior* );
    void delBehaviorRef( AbstractBehavior* );

    AbstractBehavior* getBehavior( const std::string& );
  protected:
    BehaviorCollection behaviors;
    virtual void setPlaylerEvent(){}

    // bool setClass(const std::string &s);
    unsigned long long getHashCode();
  private:
    const GameObjectClass *pat;

    std::vector< AbstractBehavior* > refs;
    int pl;

    int m_hp;

    unsigned long long hashCode;
    static unsigned long long newHash;
  };

#endif // GAMEOBJECT_H
