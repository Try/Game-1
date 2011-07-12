#include "bulletobject.h"

#include "globject.h"

#include <cmath>
#include <QDebug>

BulletObject::BulletObject( MyGL::IScene &s,
                            GLObject *ow,
                            const std::string & src)
             :GameObject(src.data()), GraphicsObject(s, src){
    owner = ow;
    initFromSrc(this);
    t    = 1.0;
    setDamage(0);
    }

float BulletObject::mix(float a, float b, float t){
    return a*t+b*(1.0-t);
    }

void BulletObject::tick(){
    setPositionF( mix(spos[0], owner->x(), t),
                  mix(spos[1], owner->y(), t),
                  mix(spos[2], owner->z() + owner->maxHeight()*0.5, t) );
    t -= dt;
    }

BulletObject& BulletObject::setEmitter( GLObject *e ){
    spos[0] = e->x();
    spos[1] = e->y();
    spos[2] = e->z() + e->maxHeight()*0.5;

    float d[3] = { e->x()-spos[0],
                   e->y()-spos[1],
                   e->z()-spos[2] };

    dt = 1.0/(sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]));
    //qDebug() << dt;

    dt/= 10.0;

    setPositionF( spos[0], spos[1], spos[2]);
    setRotate ( e->rotateAngle() );
    setPlayler( e->playler() );

    extractTextures(this);

    return *this;
    }

bool BulletObject::isLife() const{
    return t>0;
    }

BulletObject& BulletObject::setDamage(float d){
    m_damage = d;
    return *this;
    }

float BulletObject::damage(){
    return m_damage;
    }
