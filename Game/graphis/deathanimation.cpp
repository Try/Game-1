#include "deathanimation.h"

#include "globject.h"

std::vector<DeathAnimation*> DeathAnimation::instance;

DeathAnimation::DeathAnimation( MyGL::IScene &s,
                                GLObject *ow,
                                const std::string & src)
             :GameObject(src.data()), GraphicsObject(s, src){
    time = 100;
    declaySpeed = ow->maxHeight()/time;

    setPlayler( ow->playler() );
    initFromSrc(this);

    setPositionF( ow->x(), ow->y(), ow->z() );
    setRotate( ow->rotateAngle() );
    setRotateXY( 0 );

    instance.push_back(this);
    }

DeathAnimation::~DeathAnimation(){
    //instance.erase(this);
    }

void DeathAnimation::tick(){
    --time;
    setRotateXY( std::min((100-time)*7, 90) );
    //setRotate( time );
    setPositionF( x(), y(), z()-declaySpeed );
    }

void DeathAnimation::releace(){
    for( size_t i = 0; i<instance.size(); ++i)
      delete instance[i];
    instance.clear();
    }

void DeathAnimation::tickAll(){
    for( size_t i = 0; i<instance.size(); ){
      instance[i]->tick();
      if( instance[i]->time <=0 ){
        delete instance[i];
        instance[i] = instance.back();
        instance.pop_back();
        } else {
        ++i;
        }
      }

    }
