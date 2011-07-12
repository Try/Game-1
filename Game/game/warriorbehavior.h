#ifndef WARRIORBEHAVIOR_H
#define WARRIORBEHAVIOR_H

#include "abstractbehavior.h"
#include "movealgo.h"
#include "runtime/gameobjectclass.h"

class GLObject;
class UnitBehavior;

#include <vector>

class WarriorBehavior:public AbstractBehavior{
  public:
    WarriorBehavior( GLObject * obj,
                     UnitBehavior *unit = 0 );
    ~WarriorBehavior();

    static const Registrator<WarriorBehavior> registration;

    void tick();
    void deleteUnitEvent(const GLObject *);

    void command(const GLObject *);
    void command(float, float, int, bool);
    void moveCommand(float x, float y, int sq, bool, bool user = false);

    IController* createController();

    void serialize(FileStream &f);
    void setPlaylerEvent(int , int ){}

    bool isFight();

    bool isAtack();
    void setAtack(bool);

    bool isAClick();
    void setAClick(bool, float x, float y);
  private:
     GLObject * owner;
     float atkRange;
     UnitBehavior *unit;

     struct Taget{
       GLObject * unit;
       } taget;

     GameObjectClass::Atack atkVal;

     bool m_isAtack, m_isAclick, m_isFight;
     int atackDelay;

     int atkReclcTime;

     bool checkAtack( float dist, const GLObject* obj );
     bool canAtack( const GLObject& obj );
     float distance( const GLObject& obj );

     void atack( GLObject& obj );

     static bool filterFunc(GLObject* tst, GLObject *caller);
     static bool filterFuncWrk (GLObject* tst, GLObject *caller);
     static bool filterFuncUnit(GLObject* tst, GLObject *caller);

     class AClickStoreBuf{
      public:
       float x,y;
       bool size;

       AClickStoreBuf();
       void push();
       void pop();
      } aClickStk;

     void moveToAtack( GLObject *d );
     void standAndFight( GLObject *dest );

     GLObject *findEnemy();

     void moveTo(float, float, bool fake = 1 );
  };

#endif // WARRIORBEHAVIOR_H
