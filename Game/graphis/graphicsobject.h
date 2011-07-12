#ifndef _GRAPHICSOBJECT_H
#define _GRAPHICSOBJECT_H

#include <MyGL/GraphicsObject>
#include <MyGL/StdMaterial>

#include <MyGL/ITexture2d>
#include <MyGL/IModel>

#include "graphis/view.h"
#include "runtime/gameobjectclass.h"

namespace MyGL{
  class IScene;
  }

class GameObject;

class GraphicsObject {
  public:
    GraphicsObject( MyGL::IScene &scene, const std::string &src );
    ~GraphicsObject();

    View& getObject();

		void setPositionF(float x, float y, float z);
		void setSize    (float x, float y, float z, const double *base);

		void  setRotate  (float r);
		void  setRotateXY  (float r);
		float rotateAngle() const;

		float x() const;
		float y() const;
		float z() const;

	protected:
		MyGL::IScene        &scene;
		//MyGL::GraphicsObject object;
		View object;
		// MyGL::IModel        *model;

		MyGL::IShader* extractTextures( GameObject* obj );

		MyGL::IShader* extractTextures( const GameObjectClass::View&,
																		GameObject* obj,
																		MyGL::StdMaterial *material,
																		MyGL::IModel      *model );

		MyGL::ITexture2d* textureFromData( const std::string &view,
																			 const char * postFix,
																			 bool mode, GameObject* obj);

		void initFromSrc( MyGL::GraphicsObject&,
											const GameObjectClass::View&,
											GameObject* gameObj );

		void initFromSrc( GameObject* obj );

		void setModelEvent( GameObject* obj );

		MyGL::IShader *getShadowShader( MyGL::GraphicsObject& obj,
																		const GameObjectClass::View& );
	};

#endif // _GRAPHICSOBJECT_H
