#include "globject.h"

#include <MyGL/ShaderLoader>
#include <MyGL/TextureLoader>
#include <MyGL/ModelLoader>

#include <MyGL/IData>
#include <MyGL/IScene>
#include <MyGL/ITechnique>
#include <MyGL/IRender>

#include <MyGL/IModelInfo>

#include "dataCtrl/materials.h"

#include <QDebug>
#include <GL/glu.h>

#include <cmath>

#include "game/abstractbehavior.h"
#include "game/game.h"
#include "hud/cyrcle.h"
#include "game/playler.h"

#include "dataCtrl/filestream.h"
#include "runtime/texturefactory.h"
#include "settingswidget.h"

#include "graphis/bulletobject.h"
#include "game/unitbehavior.h"
#include "game/warriorbehavior.h"

#include "graphis/deathanimation.h"

GLObject* GLObject::ideObject = 0;

GLObject::GLObject( MyGL::IScene &s,
										const std::string &src )
					:GameObject( src.data() ),
					 GraphicsObject(s, src) {
		selection = 0;
		setMinSelSize(0.25);

		selected = 0;

		buildable_icon = 0;
		complete       = 1;

		initFromSrc( this );
		createBehaviors();
		setLandEnable( false );
		}


GLObject::~GLObject(){
		if( !complete )
			Game::instance().playler( playler() ).buyEvent( getClass()->name, 0);

		if( buildable_icon )
			playlerPtr().addUnitEvent( (GLObject*)this );


    for(size_t i = 0; i<bullets.size(); ++i){
      delete bullets[i];
      }

    setLandEnable( true );

    /// object.setMaterial(0);

    delete selection;

		if( ideObject==this )
			ideObject = 0;
		}

void GLObject::deathEvent(){
		if( getBehavior("unit") )
			new DeathAnimation( scene, this, getClass()->name );
		}

float GLObject::maxHeight(){
		if( object.model() ){
			return getClass()->size[2]*object.model()->cullInfo().maxZ();
			} else
			return 0;
		}

void GLObject::setCompleteBuilding(){
		behaviors.clear();
		createBehaviors();

		if( isSel() )
			Game::instance().createController();

		if( !complete ){
			playlerPtr().delIncompleteUnitEvent( this );
			playlerPtr().addUnitEvent( this );
			}

		complete = 1;
		}

void GLObject::setIncompleteBuilding(){
		behaviors.clear();
		behaviors.add( AbstractBehavior::create(this, "incomplete_building" ) );

		if( complete ){
			playlerPtr().addIncompleteUnitEvent( this );
			playlerPtr().delUnitEvent( this );
			}

		complete = 0;
		}

void GLObject::createBehaviors(){
		for(unsigned i=0; i<getClass()->behaviors.size(); ++i)
			behaviors.add( AbstractBehavior::create(this, getClass()->behaviors[i] ));

		if( isSel() )
			behaviors.selectEvent(1);
		}

void GLObject::setBuildable(){
    buildable_icon = 1;

    object.material(0)->setGlowTexture    (  scene.dataControl()->texture("blue") );
    object.material(0)->useGlow(1);

    setLandEnable( true );
    playlerPtr().delUnitEvent( (GLObject*)this );
    }

bool GLObject::validateLand( float x, float y,
														 const std::string &cclass, int offset){
		const GameObjectClass *objClass = getClass(cclass);

		if( objClass->mvLock ){
			int mvLock = objClass->mvLock;
			int r  = (mvLock/2)+offset,
					r2 = (mvLock+1)/2+offset;

			Game &game = Game::instance();

			for(int i=-r; i<r2; ++i )
				for(int j=-r; j<r2; ++j )
					if( game.map.exist( Map::coordX( x )+i,
															Map::coordY( y )+j ) ){
						int lx = Map::coordX( x )+i,
								ly = Map::coordY( y )+j;

						if( !(game.map.isEnable( lx, ly ) &&
									game.map.resCount( lx, ly )==0 ) ){
							return 0;
							}
						} else {
						return 0;
						}
			}

    return 1;
    }

bool GLObject::validateLand(){
		if( validateLand( x(), y(), getClass()->name ) ){
			object.material(0)->setGlowTexture(  scene.dataControl()->texture("blue") );
			return 1;
			}else {
			object.material(0)->setGlowTexture(  scene.dataControl()->texture("red") );
			return 0;
			}
		}

void GLObject::setLandEnable(bool e){
		if( getClass()->mvLock && !buildable_icon ){
			int r  = (getClass()->mvLock/2),
					r2 = (getClass()->mvLock+1)/2;

			for(int i=-r; i<r2; ++i )
				for(int j=-r; j<r2; ++j )
					if( game().map.exist( Map::coordX( x() )+i,
																Map::coordY( y() )+j ) ){
						game().map.editEnable( Map::coordX( x() )+i,
																	 Map::coordY( y() )+j, e );
						}

			// game().map.calcGroups();
			}

		}

void GLObject::setPosition(float nx, float ny, float z){
		bool fill = !(x()==nx && y()==ny);

		if( game().map.existf(nx, ny) ){
			z += calcZ( nx, ny );
			}

		if( fill ){
			setLandEnable( true );

			behaviors.positionEvent(nx, ny);

			setPositionF(nx, ny, z);
			if( selection )
				selection->setPos(nx, ny, calcZ( nx, ny ) );

			setLandEnable( false );
			} else {
			behaviors.positionEvent(nx, ny);

			setPositionF(nx, ny, z);
			if( selection )
				selection->setPos(nx, ny, calcZ( nx, ny ));
			}
		}

float GLObject::calcZ(float x, float y){
		int ix = int(x),
				iy = int(y);
		float dx = x - int(x),
					dy = y - int(y);

		float C = game().map.heightf( ix+1, iy ),
					B = game().map.heightf( ix,   iy+1 ),
					A = game().map.heightf( ix, iy ),
					D = game().map.heightf( ix+1, iy+1 );

		float uz[2] = {
			 (1.0-dx)*A + dx*C,
			 (1.0-dx)*B + dx*D
			 };

		return (1.0-dy)*uz[0] + dy*uz[1];
		}

void GLObject::setMinSelSize(float s){
		minSelSize = s;
		}

void GLObject::setSelSize(float s){
		selSize = s;
		}

void GLObject::setPlaylerEvent(){
    extractTextures( this );

    if( getClass()->atack.isUpgrade ){
      playlerPtr().makeGrade( getClass()->atack, getClass()->atkType );
      }
    }

bool GLObject::canSel(double rx, double ry){
    float ss = std::max(selSize, minSelSize);
    return (x()-rx)*(x()-rx) + ( y()-ry )*( y()-ry ) < 4*ss*ss;
    }

void GLObject::computeSel(double x, double y){
    setSel( canSel(x,y) );
    }

void GLObject::computeSel(float rx, float ry, float rw, float rh){/*
    MyGL::ObjectMatrix mat, p;

    //scene.render().getModeViewlMatrix(mat);
    //scene.render().getProjectionMatrix(p);

    //mat.mul(p);
    scene.render().getTransformMatrix( mat );

    float x,y,z,w;
    mat.project( object.x(), object.y(), object.z(), 1,
                 x, y, z, w);
    x/=w;
    y/=w;

    //x = x*0.5+0.5;
    //y = 1.0- (y*0.5+0.5);

    screenCoord[0] = x;
    screenCoord[1] = y;

    selected = (rx <= x && x<= rx+rw)&&(ry <=y && y<=ry+rh );
    */
    GLdouble mvMatrix[16], ProjMatrix[16];

    {
      MyGL::Float getM[16];
      scene.render().getModeViewlMatrix(getM);
      for(int i=0; i<16; ++i){
        mvMatrix[i] = getM[i];
        }

      scene.render().getProjectionMatrix(getM);
      for(int i=0; i<16; ++i){
        ProjMatrix[i] = getM[i];
        }
      }

    GLint view[] = {0,0, 1,1};

    GLdouble x,y,z;
    gluProject(object.x(), object.y(), object.z(),
               mvMatrix, ProjMatrix, view,
               &x, &y, &z);

    y = 1.0- y;
    screenCoord[0] = x;
    screenCoord[1] = y;

    setSel( (rx <= x && x<= rw)&&(ry <=y && y<=rh ) );
    }

void GLObject::setSel(bool s){
    if( !getClass()->selectable )
      return;

    selected = s;

    if( !s ){
      delete selection;
      selection = 0;
      }

    if( s && (selection==0) ){
      selection = new Cyrcle(scene);
      selection->setPos( x(), y(), 0 );
      selection->setSize( selSize );
      }

    behaviors.selectEvent(s);
    }

bool GLObject::isSel() const{
    return selected;
    }

float *GLObject::screenCoords(){
    return screenCoord;
    }

void  GLObject::command( GLObject* tg ){
    behaviors.command( tg );
    }

void GLObject::command(float x, float y, int sq, bool fake){
    //behaviorsCommand(x, y);
    behaviors.command(x,y, sq, fake);
    }

void GLObject::deleteUnitEvent( const GLObject*obj ){
    behaviors.deleteUnitEvent(obj);
    }

void GLObject::setSize(float x, float y, float z){
		setSize( x, y, z, getClass()->size );
		}

void GLObject::tick(){
    behaviors.tick();

    for(size_t i = 0; i<bullets.size();/* ++i*/){
      if( !bullets[i]->isLife()){
        hp( hp() - bullets[i]->damage() );

        delete bullets[i];
        bullets[i] = bullets.back();
        bullets.pop_back();
        } else {
        bullets[i]->tick();
        ++i;
        }
      }

    }

int GLObject::buildQueueSize(){
    return behaviors.buildQueueSize();
    }

float GLObject::viewSize() const{
    return selSize*4;
    }

bool GLObject::collision(GLObject & obj){
    float vx = obj.x()-x();
    float vy = obj.y()-y();
    if( object.model() ){
      //object.model()->cullInfo().radius();
      return ( vx*vx + vy*vy ) < viewSize()*obj.viewSize();
      } else
      return 0;
    }

bool GLObject::needToMoveDisplace(){
    return behaviors.needToMoveDisplace();
    }

void GLObject::setMoveDisplace( GLObject & obj ){
    float vx = x()-obj.x(),
          vy = y()-obj.y();

//    bool nMove = 1;
//    UnitBehavior* u    = ((UnitBehavior*)getBehavior("unit")),
//                * uObj = ((UnitBehavior*)obj.getBehavior("unit"));
//    if( u && u->isMove() )
//      nMove = 0;

//    bool hashCmp = obj.getHashCode() > this->getHashCode();
//    if( u && uObj &&
//        u->sqrDistanceToTaget() < uObj->sqrDistanceToTaget() )
//      hashCmp = 0;

//    if( obj.getClass()->speed > 0 &&
//        ( hashCmp || nMove || u->getWarrior()->isAtack() ) )
//      setMoveDisplace(vx, vy);
    setMoveDisplace(vx, vy);
    }

void GLObject::setMoveDisplace( float vx, float vy ){
    float l = sqrt(vx*vx+vy*vy);
    //qDebug() << "l = " << l;

    static const float randVec[8][2] = {
      { 1, 0},
      {-1, 0},
      { 0, 1},
      { 0,-1},

      { 1, 1},
      { 1,-1},
      {-1, 1},
      {-1,-1}
      };

    if( l>0.0000001 ){
      behaviors.setMoveDisplace( vx/l, vy/l );
      } else{
      int id = game().rand()%8;
      behaviors.setMoveDisplace( randVec[id][0], randVec[id][1] );
      }
    }

IController* GLObject::createController(){
    return behaviors.createController();
    }

int  GLObject::gridNum(){
    return Map::coordX( x() )*Game::instance().map.height() +
           Map::coordY( y() );
    }

void GLObject::updateZCoord(){
    setPosition( x(), y(), 0 );
    }

void GLObject::serializeMap(FileStream &f){
    if( f.isIn() ){
      float x,y,z, a, sx, sy, sz;
      int pl;

      f >> x >> y  >> z >>
           a >> pl >>
           sx >> sy >> sz;
      setPosition(x, y, z);
      object.setRotateZ(a);
      object.setSize(sx, sy, sz);

      setPlayler( pl );

      if( getBehavior("unit") )
        ((UnitBehavior*)getBehavior("unit"))->setRAngle(a);
      } else {
      f << object.x() << object.y() << object.z()
        << object.zRotation() << playler()
        << object.xSize() << object.ySize() << object.zSize();
      }

    f + selected;
    if( f.isIn() ){
      if( selected )
        setSel(1);
      }

    if( f.isIn() ){
      int mhp;
      f >> mhp;
      hp(mhp);
      } else {
      f << hp();
      }
    }

void GLObject::serialize(FileStream &f){
    f + complete;
    if( f.isIn() ){
      float x,y,z, a;

      f >> x >> y >> z >> a;
      setPosition(x, y, z);
      object.setRotateZ(a);

      int pl;
      f >> pl;
      setPlayler( pl );
      } else {
      f << object.x() << object.y() << object.z()
        << object.zRotation() << playler();
      }

    f + selected;
    if( f.isIn() ){
      if( selected )
        setSel(1);
      }

    behaviors.serialize(f, this);
    if( f.isIn() ){
      int mhp;
      f >> mhp;
      hp(mhp);
      } else {
      f << hp();
      }
    // setPlayler( playler() );
    }

BulletObject* GLObject::reciveBullet( const std::string& s){
    BulletObject *re = new BulletObject(scene, this, s);
    reciveBullet( re );

    return re;
    }

void GLObject::reciveBullet( BulletObject * bul ){
    bullets.push_back( bul );
    }
