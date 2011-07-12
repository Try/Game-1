#ifndef DEATHANIMATION_H
#define DEATHANIMATION_H

#include "graphicsobject.h"
#include "runtime/gameobject.h"

#include <vector>

class GLObject;

class DeathAnimation :public GameObject,
                      public GraphicsObject{
  public:
    DeathAnimation( MyGL::IScene &s,
                    GLObject *owner,
                    const std::string & );
    ~DeathAnimation();

    void tick();
    static void tickAll();
    static void releace();
  private:
    int time;

    float declaySpeed;
    static std::vector<DeathAnimation*> instance;
  };

#endif // DEATHANIMATION_H
