#ifndef BEHAVIORCOLLECTION_H
#define BEHAVIORCOLLECTION_H

#include "abstractbehavior.h"

#include <vector>

class BehaviorCollection:public AbstractBehavior{
  public:
    BehaviorCollection();
    ~BehaviorCollection();

    void add(AbstractBehavior* );
    void del(AbstractBehavior* );

    AbstractBehavior* getBehavior( const std::string& );

    void tick();
    void command(float , float , int sq, bool);
    void command( GLObject* );
    void deleteUnitEvent( const GLObject* );

    bool needToMoveDisplace();
    void setMoveDisplace(float , float );

    void selectEvent( bool /*s*/ );

    void positionEvent(float, float);
    IController* createController();

    void serialize(FileStream &f);
    void serialize(FileStream &f, GLObject *owner);
    void clear();

    void setPlaylerEvent(int Old, int New);
    int buildQueueSize();

  private:
    std::vector<AbstractBehavior*> behaviors;
  };

#endif // BEHAVIORCOLLECTION_H
