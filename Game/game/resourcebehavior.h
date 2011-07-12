#ifndef RESOURCEBEHAVIOR_H
#define RESOURCEBEHAVIOR_H

#include "abstractbehavior.h"
#include "movealgo.h"

class GLObject;

#include <vector>

class ResourceBehavior:public AbstractBehavior{
  public:
    ResourceBehavior( GLObject * obj );
    ~ResourceBehavior();

    static const Registrator<ResourceBehavior> registration;

    void positionEvent(float x, float y);

    float x();
    float y();

    static std::vector< ResourceBehavior* >& items();

    enum Using{
      NoUsing,
      WorkerGo,
      WorkerJob
      } isUsed;
    IController* createController();

    void serialize(FileStream &f);
    void setPlaylerEvent(int , int ){}
    GLObject * owner();

    static GLObject* resAt(float x, float y);
  private:
    GLObject * ow;
    int count, lx, ly;
    float fx,fy;
    static std::vector< ResourceBehavior* > m_items;
  };

#endif // RESOURCEBEHAVIOR_H
