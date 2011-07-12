#ifndef GLOBJECT_H
#define GLOBJECT_H

#include "runtime/gameobject.h"
#include "graphis/graphicsobject.h"

class Cyrcle;
class FileStream;
class BulletObject;

class GLObject:public GameObject,
               public GraphicsObject{
  public:
    GLObject( MyGL::IScene &scene, const std::string &src );
    ~GLObject();

		void setPosition(float x, float y, float z);
		void setSize    (float x, float y, float z);
		using GraphicsObject::setSize;

		bool isSel() const;
		void setSel(bool );
		void computeSel(float x, float y, float w, float h);
		void computeSel(double x, double y);
		bool canSel(double x, double y);

		float *screenCoords();

		void  command(float x, float y, int sq, bool fake);
		void  command( GLObject* tg );
		void  deleteUnitEvent( const GLObject* );
		void  tick();
		int buildQueueSize();

		bool collision(GLObject & obj);

		bool needToMoveDisplace();
		void setMoveDisplace( GLObject & obj );
		void setMoveDisplace( float x, float y );

		IController* createController();

		void serialize(FileStream &f);
		void serializeMap(FileStream &f);

		int  gridNum();

		bool validateLand();
		static bool validateLand( float x, float y,
															const std::string &cclass, int offset = 0);

		void setBuildable();
		void setIncompleteBuilding();
		void setCompleteBuilding();

		float maxHeight();
		float viewSize() const;

		static GLObject* ideObject;

		void updateZCoord();
		BulletObject* reciveBullet( const std::string& );
		void reciveBullet( BulletObject * bul );

		void setMinSelSize(float);

		void deathEvent();
	private:
		void setPlaylerEvent();
		float calcZ(float x, float y);

		Cyrcle * selection;

		bool selected, buildable_icon, complete;

		float screenCoord[2];
		float selSize, minSelSize;

		void setLandEnable(bool e);
		void createBehaviors();
		void setSelSize(float);

		std::vector<BulletObject*> bullets;
	};

#endif // GLOBJECT_H
