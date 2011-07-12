#ifndef PLAYLER_H
#define PLAYLER_H

#include <vector>
#include <string>

class Game;
class BuildingBehavior;
class CentralBuildingBehavior;

#include <QColor>
#include "game/utils/unitscounter.h"
#include "runtime/atacktypes.h"

class FileStream;

class Bot;
class GLObject;

class WorkerBehavior;

class Playler {
  public:
    Playler( Game &game, int id );
    ~Playler();

    void addCentralBuilding(CentralBuildingBehavior &);
    void delCentralBuilding(CentralBuildingBehavior &);

    CentralBuildingBehavior* getCastle(int x, int y);

    void ourTroopsIsUnderAttack( GLObject * obj );

    void addGold(int v);
    int  gold();

    void addLim(int v);
    int  lim();
    int  maxLim();

    bool canBuy( const std::string &name );
    const GameObjectClass* canBuyMsg( const std::string &name );
    bool canBuyByLim( const std::string &name );

    void buyEvent( const std::string &name, bool ok );

    void setDrived(bool );
    bool isDrived();

    void setLevel(int l);
    int  level();

    void setActive(bool );
    bool isActive();

    QColor color();
    void serialize(FileStream &f);

    void tick();

    void addUnitEvent( GLObject * obj );
    void delUnitEvent( GLObject * obj );

    void addIncompleteUnitEvent( GLObject * obj );
    void delIncompleteUnitEvent( GLObject * obj );

    void addWorkerEvent( WorkerBehavior * obj );
    void delWorkerEvent( WorkerBehavior * obj );

    void addBuildingsEvent( BuildingBehavior * obj );
    void delBuildingsEvent( BuildingBehavior * obj );

    void addCastleEvent( CentralBuildingBehavior * obj );
    void delCastleEvent( CentralBuildingBehavior * obj );

    int countOf( const std::string &cName );
    int countOfIncom( const std::string &cName );
    int countOfall( const std::string &cName );

    const AtackTypes::AtkTypeSet<int>& grades();
    void makeGrade( const GameObjectClass::Atack& val,
                    const AtackTypes::AtkType& t);

  protected:
    virtual void tickDrived();
    virtual void tickBot();
  private:
    std::vector<CentralBuildingBehavior*> cas;
    int m_gold, m_lim;
    int id;

    QColor m_color;
    Bot *bot;

    static const QColor plColors[];

    UnitsCounter counter, halfCounter;

    bool drived, active;
    int  showAtkTime;
    AtackTypes::AtkTypeSet<int> m_grades;
  };

#endif // PLAYLER_H
