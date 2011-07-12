#ifndef UNITBEHAVIOR_H
#define UNITBEHAVIOR_H

#include "abstractbehavior.h"
#include "movealgo.h"

class GLObject;
class WarriorBehavior;

class UnitBehavior: public AbstractBehavior{
  public:
    UnitBehavior( GLObject * obj );
    ~UnitBehavior();

    static const Registrator<UnitBehavior> registration;

    void tick();

    void command( GLObject* );
    void command(float x, float y, int sq, bool);
    void deleteUnitEvent(const GLObject *);

    bool needToMoveDisplace();
    void setMoveDisplace(float x, float y);

    void holdPosition();
    void stopMove();

    bool isMove();
    IController* createController();

    void serialize(FileStream &f);
    void setPlaylerEvent(int Old, int New);

    void rotateTo(float x, float y);

    bool isMvDisplace();
    WarriorBehavior *getWarrior();

    MoveAlgo::Point getTagetPoint();
    void moveCommand(float x, float y, int sq, bool, bool user = false);

    void setRAngle(float a);

    float sqrDistanceToTaget() const;
  private:
    WarriorBehavior *warrior;
    void rotate();

    GLObject *owner;
    float moveVec[2], dAngle;
    struct Taget{
      float pos[2];
      GLObject * unit;
      } taget;

    float wayLen;
    bool  wasMoveDisplace, m_isMove, isMoveDelay, isFake;

    int wayErrors;

    const double &moveSpeed;
    float rotateSpeed;

    void normalize(float &x, float &y, float w);
    void calcAngle();

    MoveAlgo::WayType way;

    void wayPach(float x, float y);
    void wayPach();

    void reposition();

    bool nextStep();

    bool canMove(float x, float y);

    static float sqr(float x);

    bool calcNextPos(float &x, float &y, float l = 1.0);

    void correctWay();
    bool moveToTagetUnit();
  };

#endif // UNITBEHAVIOR_H
