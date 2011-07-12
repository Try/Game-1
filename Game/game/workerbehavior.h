#ifndef WORKERBEHAVIOR_H
#define WORKERBEHAVIOR_H

#include "abstractbehavior.h"
#include "movealgo.h"

class GLObject;

class UnitBehavior;
class ResourceBehavior;

class WorkerBehavior:public AbstractBehavior{
  public:
    WorkerBehavior( GLObject * obj );
    ~WorkerBehavior();

    static const Registrator<WorkerBehavior> registration;

    void tick();

    void command(float x, float y, int sq, bool);
    void command( GLObject * );
    void deleteUnitEvent(const GLObject *);

    void setMoveDisplace(float x, float y);
    bool needToMoveDisplace();

    IController* createController();

    void serialize(FileStream &f);
    void setPlaylerEvent(int Old, int New);

    void setBuild(float x, float y, const std::string &name);

    void goToWork();

    bool isBusy();
    bool isBuilder();
    GLObject *owner() const;
  private:

    UnitBehavior *unitBehavior;
    GLObject *m_owner;

    void resetResource();

    void m_goToWork();

    struct ResInfo{
      enum State{
        sNo,
        sToCastle,
        sToResource,
        sWork
        } state;

      bool  resCollector;
      float taget[2];
      ResourceBehavior *tg;
      int wrkTime;
      } resInfo;

    struct BuildInfo{
      enum State{
        Null,
        GoToBuild,
        Work
        } state;
      float taget[2];
      std::string name;
      } buildInfo;

    //int wrkTime;

    static const int maxWrkRadius;

    void getRes(ResourceBehavior *);

    ResourceBehavior* findRes(bool ckUsed);
    ResourceBehavior* findResRange(bool ckUsed);
    ResourceBehavior* findRes(ResourceBehavior *);
    bool validate(ResourceBehavior*);

    void moveToCastle();

    void startBuild();
    void canselBuild();
  };

#endif // WORKERBEHAVIOR_H
