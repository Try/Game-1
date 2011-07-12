#include "screenhudrender.h"

#include <MyGL/IScene>
#include <MyGL/IRender>
#include <MyGL/IData>

#include <MyGL/IRenderState>
#include <MyGL/IShader>
#include <MyGL/IUniform4f>

using namespace MyGL;

ScreenHudRender::ScreenHudRender(MyGL::IScene &s):scene(s){
    sh = 0;
    }

void ScreenHudRender::initGl(){
    sh   = scene.dataControl()->shader("selRect");
    quad = scene.dataControl()->model ("quad");

    rect = sh->uniform4f("rect");
    }

void ScreenHudRender::drawSelRect( const QRect & r, float w, float h){
    scene.render().renderState()->setZTest(0);
    scene.render().renderState()->
        setBlendMode( MyGL::IRenderState::AlphaBlendMode::one,
                      MyGL::IRenderState::AlphaBlendMode::one );
    scene.render().renderState()->setBlend(1);
    scene.render().renderState()->
        setCullFaceMode( IRenderState::CullMode::noCull );

    if( rect )
      rect->set(r.x()/w, 1.0-r.y()/h, r.width()/w, -r.height()/h);

    scene.render().begin();

    scene.render().useShader( sh );
    scene.render().drawModel( quad );

    scene.render().end();
    }
