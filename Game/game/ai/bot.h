#ifndef BOT_H
#define BOT_H

class Playler;
class GLObject;

#include <vector>
#include <set>
#include <string>

class WorkerBehavior;
class BuildingBehavior;
class CentralBuildingBehavior;

#include "runtime/gameobject.h"
#include "game/utils/stableset.h"

class Bot{
  public:
    Bot(Playler &pl);

    void tick();

    void addUnitEvent( GLObject * obj );
    void delUnitEvent( GLObject * obj );

    void addWorkerEvent( WorkerBehavior * obj );
    void delWorkerEvent( WorkerBehavior * obj );

    void addBuildingsEvent( BuildingBehavior * obj );
    void delBuildingsEvent( BuildingBehavior * obj );

    void addCastleEvent( CentralBuildingBehavior * obj );
    void delCastleEvent( CentralBuildingBehavior * obj );

    void serialize(FileStream &f);

    void setSkil(int level/*0..2*/);
    int  skilLevel();

    void atackEvent( GLObject * obj );
  private:
    void assignWorkers();
    void recrutWorkers();

    void recrutMarines();
    void recrut(BuildingBehavior*, const char* );

    void tryToBuild( const std::string &name );

    void moveToCastle( bool enemy );
    void atack();
    void goHome();

    Playler &playler;
    bool needToUpRange;

    StableSet<GLObject*>       units;
    StableSet<WorkerBehavior*> workers;
    StableSet<CentralBuildingBehavior*> castles;
    StableSet<BuildingBehavior*> barracks;

    struct BuildCoord{
      int x, y;
      int maxCoord;
      } buildCoord;

    int wrkId;
    int atkLim;
    int skil;

    int atkRecalc;

    enum State{
      Defence,
      Atack,
      StateCount
      } state;

    int distanceToMinerals(int x, int y);

    CentralBuildingBehavior* tgCastle;
    CentralBuildingBehavior* findTgCastle( bool enemy );

    void atackTo(float x, float y);
  };

#endif // BOT_H
