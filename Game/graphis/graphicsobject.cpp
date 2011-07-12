#include "graphicsobject.h"
#include "game/game.h"

#include "dataCtrl/materials.h"
#include "settingswidget.h"
#include "runtime/texturefactory.h"

#include <MyGL/IData>
#include <MyGL/IModelInfo>

#include "runtime/gameobject.h"
#include "game/playler.h"

#include "log.h"
#include <QDebug>

GraphicsObject::GraphicsObject(MyGL::IScene &s, const std::string &)
               :scene(s), object(s){
  // material = 0;
  }

GraphicsObject::~GraphicsObject(){
	// delete material;
	}

void GraphicsObject::setPositionF(float nx, float ny, float z){
		object.setPosition(nx, ny, z);
		}

void GraphicsObject::setSize(float x, float y, float z, const double *size){
		object.setSize( size[0]*x,
										size[1]*y,
										size[2]*z );
		}

float GraphicsObject::x() const{
    return object.x();
    }

float GraphicsObject::y() const{
    return object.y();
    }

float GraphicsObject::z() const{
    return object.z();
    }

void GraphicsObject::setRotate(float r){
    object.setRotateZ( r );
    }

void  GraphicsObject::setRotateXY  (float r){
    object.setRotateXY( r );
    }

float GraphicsObject::rotateAngle() const{
    return object.zRotation();
    }

View& GraphicsObject::getObject(){
		return object;
		}

MyGL::IShader* GraphicsObject::extractTextures( GameObject* obj ){
		return extractTextures( obj->getClass()->view, obj,
														(MyGL::StdMaterial*)object[0].material(),
														object[0].model() );
		}

MyGL::IShader* GraphicsObject::
								 extractTextures( const GameObjectClass::View& view,
																	GameObject* obj,
																	MyGL::StdMaterial *material,
																	MyGL::IModel      *model ){
		MyGL::ITexture2d  *tmp = 0;

		Materials::Macro macro;
		// macro.insert( "NO_SHADOWS" );

    tmp = textureFromData( view.data, ".diff",
                           view.generate_texture.diff,
                           obj );

    material->setDiffuseTexture ( tmp );
    macro.insert( "LAMBERT" );

    tmp = textureFromData( view.data, ".spec",
                           view.generate_texture.spec,
                           obj );
    material->setSpecularTexture( tmp);
    if( tmp ){
      macro.insert( "SPECULAR" );
      }

    tmp = textureFromData( view.data, ".norm",
                           view.generate_texture.norm,
                           obj );
    material->setNormalTexture  ( tmp );
    if( tmp ){
      macro.insert( "NORMAL" );
      } else {
      tmp = textureFromData( view.data, ".parallax",
                             view.generate_texture.norm,
                             obj );
      material->setNormalTexture  ( tmp );
      if( tmp ){
        macro.insert( "NORMAL" );
        macro.insert( "PARALLAX" );
        }
      }

    if( view.surface_scerting ){
      macro.insert( "SCERTING" );
      }

    tmp = textureFromData( view.data, ".glow",
                           view.generate_texture.glow,
                           obj );
    material->setGlowTexture    ( tmp );
    material->useGlow( tmp );

    bool doShadow = 1;
    if( SettingsWidget::settings.shadowQuality<1 )
      doShadow = 0;

    if( model &&
        model->primitiveType()==MyGL::IVBO::PrimitiveType::Quads ){
      macro.insert("PARTICLE");
      }

    return Materials::instance().get( macro, doShadow );
    }

MyGL::ITexture2d* GraphicsObject::textureFromData( const std::string &view,
																									 const char * postFix,
																									 bool mode,
																									 GameObject* obj  ){
		MyGL::ITexture2d *tmp = 0;

		if( mode ){
			std::string idx = "[*]";
			idx[1] = obj->playler()+'0';
			tmp = TextureFactory::genTexture( view+idx+postFix,
																				view + postFix,
																				view + ".mask",
																				obj->playlerPtr().color() );
			} else{
			tmp = scene.dataControl()->texture( view + postFix);
			}

		return tmp;
		}

void GraphicsObject::initFromSrc( MyGL::GraphicsObject& obj,
																	const GameObjectClass::View& view,
																	GameObject* gameObj ){
		obj.setModel( scene.dataControl()->model( view.data ) );
		setModelEvent( gameObj );

		MyGL::StdMaterial  *m = new MyGL::StdMaterial( scene );
		m->setShadowTexture(
					scene.dataControl()->texture("MyGL::shadow_map_texture") );

		m->setShader( extractTextures( view, gameObj, m, obj.model() ) );

    m->setDepthShader ( scene.dataControl()->shader ("depth")   );
    m->setGlowShader  ( scene.dataControl()->shader ("glow")    );

    m->useDepthPass(0);

    obj.setMaterial( m );

		if( gameObj->getClass()->rand_rotate )
			obj.setRotateZ( 360.0*Game::instance().rand()/(float)RAND_MAX ); else
			obj.setRotateZ( 180 );

		m->useCullFace( view.useCullFace );

		if( view.blend==GameObjectClass::Blend::add ){
			obj.material()->renderState().setBlend(1);
			obj.material()->renderState().
					setBlendMode( MyGL::IRenderState::AlphaBlendMode::one,
												MyGL::IRenderState::AlphaBlendMode::one );
			}

		if( view.blend==GameObjectClass::Blend::alpha ){
			obj.material()->renderState().setBlend(1);
			obj.material()->renderState().setBlendMode();
			obj.material()->renderState().
					setAlphaTestMode( MyGL::IRenderState::AlphaTestMode::Always );
			}

		m->setShadowShader( getShadowShader(obj, view) );

		if( view.data == "grass" ){
			m->useCullFace(0);
			m->useDepthPass(0);
			m->setShadowShader( 0 );
			m->setShader      ( scene.dataControl()->shader ("grass") );
			obj.material()->renderState().setAlphaCoverage(1);

			if( !SettingsWidget::settings.grass )
				obj.setVisible(0);
			}

		}

void GraphicsObject::initFromSrc( GameObject* obj ){
		if( obj->getClass()==0 )
			return;

		initFromSrc(object[0], obj->getClass()->view, obj);

		if( obj->getClass()->view1.data!="no_view" ){
			object.setViewsCount(2);
			initFromSrc(object[1], obj->getClass()->view1, obj);
			}


		double rsize[3];

		if( !obj->getClass()->rand_size.proportional ){
			for(int i=0; i<3; ++i){
				rsize[i] = Game::instance().rand( obj->getClass()->rand_size.min[i],
																					obj->getClass()->rand_size.max[i]);
				}
			} else {
			double k = Game::instance().rand(0, 1);
			for(int i=0; i<3; ++i){
				rsize[i] = obj->getClass()->rand_size.min[i] +
									 k*(   obj->getClass()->rand_size.max[i]
											 - obj->getClass()->rand_size.min[i]);
				}
			}

		object.setSize( obj->getClass()->size[0]*rsize[0],
										obj->getClass()->size[1]*rsize[1],
										obj->getClass()->size[2]*rsize[2] );
		}

MyGL::IShader *GraphicsObject::
							 getShadowShader( MyGL::GraphicsObject& obj,
																const GameObjectClass::View& view ){
		Materials::Macro macro;

		if( view.atest_shadow ){
			//return scene.dataControl()->shader ("shadow_at");
			macro.insert("ALPHA_TEST");
			}

		if( obj.model()->primitiveType()==MyGL::IVBO::PrimitiveType::Quads )
			macro.insert("PARTICLE");

		if( SettingsWidget::settings.shadowQuality>1 ||
				obj.model()->cullInfo().radius()> 5 )
			return Materials::instance().getShadowShader(macro); else
			return 0;
		}

void GraphicsObject::setModelEvent( GameObject* obj ){
		//model    = m;
		//object[0].setModel( model );
		if( object.model() ){
			float sx = object.model()->cullInfo().maxX()
							 - object.model()->cullInfo().minX();
			float sy = object.model()->cullInfo().maxY()
							 - object.model()->cullInfo().minY();

			sx *= obj->getClass()->size[0];
			sy *= obj->getClass()->size[1];

			obj->setSelSize( std::max(sx, sy)*0.25 );
			} else {
			obj->setSelSize(0);
			}
		}
