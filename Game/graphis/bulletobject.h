#ifndef BULLETOBJECT_H
#define BULLETOBJECT_H

#include "graphicsobject.h"
#include "runtime/gameobject.h"

class GLObject;

class BulletObject :public GameObject,
                    public GraphicsObject{
  public:
    BulletObject( MyGL::IScene &s,
                  GLObject *owner,
                  const std::string & );

    void tick();
    BulletObject& setEmitter( GLObject *emitter );

    bool isLife() const;

    BulletObject& setDamage(float d);
    float damage();
  private:
    GLObject *owner;
    float t, dt, spos[3];
    float m_damage;

    float mix(float a, float b, float t);
  };

#endif // BULLETOBJECT_H
