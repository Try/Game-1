#ifndef INCOMPLETEBUILDINGBEHAVIOR_H
#define INCOMPLETEBUILDINGBEHAVIOR_H

#include "abstractbehavior.h"
#include "game/falagownerbahavior.h"

class IncompleteBuildingBehavior:public FalagOwnerBahavior{
  public:
    IncompleteBuildingBehavior( GLObject *obj );
    ~IncompleteBuildingBehavior();
    void setPlaylerEvent(int Old, int New);

    static const Registrator<IncompleteBuildingBehavior> registration;

    void tick();
    void serialize(FileStream &f);

    IController* createController();

    float progress();
    void cansel();

    void command(float x, float y, int sq, bool);
    void deleteUnitEvent(const GLObject *);

  private:
    int time, maxTime;

    int calcHp(int time);
    void upsetPointFlagPos();
  };

#endif // INCOMPLETEBUILDINGBEHAVIOR_H
