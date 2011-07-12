#include "cyrcle.h"

#include <MyGL/IScene>
#include <MyGL/IData>

#include "dataCtrl/materials.h"

Cyrcle::Cyrcle( MyGL::IScene& s):
        scene(s),
        object(s){
    material  = new MyGL::StdMaterial( scene );

    material->setShadowTexture(
          scene.dataControl()->texture("MyGL::shadow_map_texture") );

    Materials::Macro macro;

    material->setShader      ( Materials::instance().get(macro) );
    material->setDepthShader ( 0 );
    material->setGlowShader  ( 0 );

		material->useDepthPass(0);
		material->useCullFace( 0 );

		object.setModel( scene.dataControl()->model( "selection" ) );
		object.setMaterial( material );

    material->setDiffuseTexture ( scene.dataControl()->
                                 texture( "selection.diff") );

    object.material()->renderState().setBlend(1);
    object.material()->renderState().
        setBlendMode( MyGL::IRenderState::AlphaBlendMode::one,
                      MyGL::IRenderState::AlphaBlendMode::one );

    object.setRotateZ(0);

    setSize( 0.115 );
    }

Cyrcle::~Cyrcle(){
		object.setMaterial(0);
		delete material;
		}

void Cyrcle::setPos(float x, float y, float z){
    object.setPosition(x,y,z + 0.01);
    }

void Cyrcle::setVisible(bool v){
    object.setVisible(v);
    }

void Cyrcle::setSize(float s){
    object.setSize(s, s, 0);
    }
