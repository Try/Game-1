#include "glwidget.h"

#include <MyGL/Color>

#include <MyGL/Texture2d>
#include <MyGL/Model>
#include <MyGL/DataLoader>
#include <MyGL/Data>

#include <MyGL/IUniform1f>
#include <MyGL/IUniform4f>
#include <MyGL/UniformSampler>

#include <MyGL/Texture2d>
#include <MyGL/IRenderState>

#include <MyGL/ObjectMatrix>
#include <MyGL/StdMaterial>

#include <MyGL/Light>
#include <MyGL/ILightsCollection>

#include <QtGui/QImage>
#include <QtGui/QMouseEvent>
#include <QtCore/QElapsedTimer>
#include <MyGL/IErrorControl>

#include <MyGL/Types>

#include <QTime>
#include <QTimer>

#include <cmath>

#include <MyGL_XmlData/MyGL_XmlData>
#include <MyGL/IOModel>
#include <MyGL/IShaderEnvironment>

#include <fstream>

#include "mainwindow.h"

#include "runtime/cxmlbind.h"
#include "game/abstractbehavior.h"
#include "dialogs/saveloaddialog.h"

#include "fun/bmpmap.h"

#include <QMessageBox>
#include <QPushButton>

#include "graphis/gamescenegraph.h"
#include "settingswidget.h"

#include "game/playler.h"

// #define DEBUG

#include "log.h"

#include <QStyleOptionFrame>
#include <MyGL/DataStream>

GLWidget *GLWidget::inst = 0;

GLWidget::GLWidget( MainWindow *w, QWidget *parent) :
					QGLWidget(
#ifdef DEBUG
											QGLFormat( QGL::SampleBuffers ),
#endif //DEBUG
											parent ),
					hudRender( scene ),
					textureFactory( scene ),
					game( scene, 0 ),
					materials( scene ){
		inst = this;

		shAngle = M_PI - M_PI/4.0;
		mainWindow = w;

		timer      = new QTimer();
		paintTimer = new QTimer();

		connect(timer, SIGNAL(timeout()),
						this,  SLOT(gameTick()) );

		connect(paintTimer, SIGNAL(timeout()),
						this,  SLOT(updateGL()) );

		scene.render().gl().errorCtrl()->setOutputStream( Log::outStream() );

		currKey    = 0;
		isRotation = 0;
		isMousePressed = 0;

		CXMLBind gameClasses;
		gameClasses.load("./game/game.xml");
		setMouseTracking( 1 );

		useSnap(1);
		setAutoFillBackground(0);

		curIdePl = 0;
		setAutoBufferSwap(0);
/*
		MyGL::IOModel m;
		m.load("./data/tree1/_particle.m");

		for(int i=0; i<m.size(); ++i){
			m.point(i).z += 2.5;
			}

		m.save("./data/tree1/particle.m");*/

		mouseCoords2d[0] = 0;
		mouseCoords2d[1] = 0;
		setAutoBufferSwap(0);
		}

GLWidget::~GLWidget(){
		makeCurrent();

		// AbstractBehavior::free();

		delete timer;
		delete paintTimer;

		if( scene.render().isActive() ){
			game.freeGPUData();
			scene.finitGL();
			}
		}

GLWidget *GLWidget::instance(){
		return inst;
		}

void GLWidget::setLayCtrl( QLayout *l ){
		game.setCtrlLayout(l);
		}

void GLWidget::initializeGL(){
		if( scene.render().wasInit() )
			return;


		if( !scene.initGL() ) {
			QMessageBox m;
			m.setText("OpenGL 2.1 need");
			m.exec();

			mainWindow->close();
			return;
			}

		setFocus();

		scene.textureLoader().setLoadFileCallBack( loadTexture );
		scene.shaderLoader() .setEnvironment( &shaderEnv );

		MyGL::DataLoader::IAllocator<MyGL::IShader> *allocator =
				new MyGL::DataLoader::Allocator<QtShader, MyGL::IShader>;
		scene.loader().setShaderAllocator( allocator );

		scene.render().clearColor( MyGL::Color(0.0, 0.6, 0.8, 0.0) );

		MyGL::MyGL_XmlData xml(scene);
		// scene.shaderLoader().enviroment()->push("LIGHT_DEBUG", "");

		xml.load("./data/data.xml");
		scene.createRenderAlgo();

		game.initializeGL();
		hudRender.initGl();
		ShowHint::instance().background
				= QPixmap::fromImage( *Pixmaps::get("infoPanel") );

		scene.render().setZRange(0.1, 500);
		scene.render().setCamera( camera );

		camera.setPos(0, 0, 1);
		camera.setAngles( -35, 180);
		//camera.setAngles( -75, 180);

		camera.setDistance( 20 );

		MyGL::Light *l = new MyGL::Light( scene.lights() );
		l->setShadowCast(1);
		l->setDirection(1, 1, -3);

		checkErrors();

    timer->setInterval(1);
    timer->start();

    paintTimer->setInterval(15);
    paintTimer->start();
    }

void GLWidget::gameTick(){
		//makeCurrent();
		//checkGL();

		/*int steps = */
		game.ticks();

		/*
		for(int i = 0; i<steps; ++i){
			moveCamera();
			}*/

    //if( steps && ( steps<=2 || steps>8 ) )
      //update();
    }

void GLWidget::ideEvents(){
    Log() << "[GLWidget::ideEvents] pure virtual function call";
    }

void GLWidget::paintGL(){
		if( !mainWindow->isInGame() )
			return;

		makeCurrent();
		checkGL();

		if( !scene.render().wasInit() )
			return;

		setFocus();

		updateMouseCoords(mouseCoords2d[0], mouseCoords2d[1]);
		updateMouseCoords(0,       0, scene.getSceneGraph()->gameViewRect[0]);
		updateMouseCoords(width(), 0, scene.getSceneGraph()->gameViewRect[1]);
		updateMouseCoords(width(), height(),
											scene.getSceneGraph()->gameViewRect[2]);
		updateMouseCoords(0,       height(),
											scene.getSceneGraph()->gameViewRect[3]);

		if( GLObject::ideObject ){
			GLObject::ideObject->
					setPosition( mouseCoords[0], mouseCoords[1], mouseCoords[2] );
			}

		ideEvents();

		//scene.lights().at(0).setDirection( 0, 0, -2 );
		scene.lights().at(0).setDirection( sin(shAngle), cos(shAngle), -2.0);
		//shAngle+=M_PI*2.0/180.0;

		QElapsedTimer timer;
		scene.render().resetCounters();
		timer.start();

    scene.render().clear( MyGL::IRender::clearDepthBit );
    scene.draw();

    if( selRect.isStarted() ){
      hudRender.drawSelRect( selRect.rect( mouseCoords2d ),
                             width(), height() );
      selRect.rect( mouseCoords2d );
      // p.drawRect( selRect.rect( mouseCoords2d ) );
      }

    paint2d();
    checkErrors();

		if( mainWindow )
			moveCamera();

		swapBuffers();

    //qDebug() << "dips = " << scene.render().dipCount();
    displayDipCount( scene.render().dipCount(),
                     timer.elapsed(),
                     scene.render().batchCount() );
    }

void GLWidget::paint2d(){
    QPainter p(this);

    if( ShowHint::instance().text().size() ){
      QPixmap & back = ShowHint::instance().background;
      int wy = height() - back.height()-225;
      p.drawPixmap(width()  - back.width(),
                   wy,
                   back);

      {QPen pen;
        pen.setColor( QColor(255, 255, 255) );
        pen.setWidth(2);
        p.setPen( pen );
        }

      p.drawText( QRect(width()  - back.width()+10,
                        wy+5,
                        2000, 200),
                  Qt::AlignLeft | Qt::TextWordWrap,
                  ShowHint::instance().text() );//ShowHint
      }


    if( ShowHint::instance().messages().size() ){
      {QPen pen;
        pen.setColor( QColor(255, 255, 255) );
        pen.setWidth(2);
        p.setPen( pen );
        }
      {
        QFont f;
        f.setPixelSize(20);
        f.setBold(1);

        p.setFont(f);
        }

      int sy = height() - ShowHint::instance().messages().size()*32 - 225;
      for(int i=0; i<ShowHint::instance().messages().size(); ++i){
        ShowHint::Message &msg = ShowHint::instance().messages()[i];
        p.drawPixmap( 0, sy-msg.icon.height(), msg.icon );
        p.drawText  (32, sy-6,                 msg.msg  );
        sy+=32;
        }

      ShowHint::instance().tick();
      }

    {
      QStyleOptionFrame option;
      option.initFrom(this);
      option.rect = QRect(width()/2-100, 0, 200, 30);

      style()->drawPrimitive( QStyle::PE_Frame, &option, &p, this);

      Game::PlInfo info = game.getPlInfo();

      {
        QFont f;
        f.setPixelSize(16);

        p.setFont(f);
        }

      QString g =
          tr("Gold: ")+QString::number(info.gold) +
          tr("    Lim: ")+
          QString::number(info.lim)+"/"+QString::number(info.maxLim);

      option.rect.setX( option.rect.x()+10 );
      p.drawText(option.rect, Qt::AlignCenter, g );
      }
    }

void GLWidget::debugPaint(){
		//#ifdef DEBUG
		QPainter p(this);
/*
		for(int i=0; i<game.objects().size(); ++i)
			if( game.objects()[i].isSel() ){
				int x = game.objects()[i].screenCoords()[0]*width();
				int y = game.objects()[i].screenCoords()[1]*height();

				p.drawRect( x-15, y-15, 30, 30 );
				}*/

		p.drawRect(0, 0, 40, 40);
		//#endif //DEBUG
		}

void GLWidget::resizeGL( int width, int height ){
		scene.render().setViewport(0, 0 ,width, height);
		}

void GLWidget::checkErrors(){
		std::string lastError = scene.render().getError();

		while( lastError.size() ){
			qDebug() <<"error: " << lastError.data();
			lastError = scene.render().getError();
			}
		}

void GLWidget::loadTexture( MyGL::ITexture2d& tex,
														const std::string& file,
														bool *ok ){
		QImage image;
		bool imgOk = image.load( file.data() );
		image      = image.rgbSwapped();

		if( !imgOk ){
			Log() <<"image \'"<< file << "\' not loaded";
			}

		if( ok )
			(*ok) = imgOk;

		if( imgOk ){
			tex.loadMipMaps
							 ( image.bits(),
								 MyGL::ITexture::InputFormat::RGBA8,
								 image.width(), image.height(),
								 MyGL::ITexture::Format::RGBA_DXT5 );
			}

		}

void GLWidget::startGame(){
		game.start( 2 );
		}

void GLWidget::mousePressEvent(QMouseEvent *event){
		if( event->button() == Qt::RightButton )
			isRotation = 2;

		if( event->button() == Qt::LeftButton ){
			isRotation = 1;
			selRect.start( event->x(), event->y() );
			}

		oldAngles[0] = event->x();
		oldAngles[1] = event->y();

		isMousePressed = 1;
		}

void GLWidget::mouseMoveEvent( QMouseEvent *event ){/*
		if( isRotation==2 ){
			camera.setAngles( camera.rotXY() - oldAngles[1] + event->y(),
												camera.rotXZ() - oldAngles[0] + event->x() );

			oldAngles[0] = event->x();
			oldAngles[1] = event->y();
			}*/

		mouseCoords2d[0] = event->x();
		mouseCoords2d[1] = event->y();

		selRect.rect( mouseCoords2d );
		if( !selRect.isStarted() ){
			//GLObject *obj = game.objects().unitAt(mouseCoords[0], mouseCoords[1]);
			if( game.map.resCountf(mouseCoords[0], mouseCoords[1]) ){
				setCursor( Cursors::instance().getMinerals );
				} else {
				setCursor( Cursors::instance().main );
				}
			} else {
			setCursor( Cursors::instance().main );
			}
		}

void GLWidget::mouseReleaseEvent(QMouseEvent *event){
		isMousePressed = 0;

		if( isRotation==1 ){
			if( GLObject::ideObject ){
				const std::string& s = GLObject::ideObject->getClass()->name;
				GLObject::ideObject = 0;
				addObject( s );
				} else {
				if( selRect.isStarted() &&
						!selRect.isSmall(event->x(), event->y()) ){
					QRectF r( selRect.rect( event->x(), event->y() ) );
					r.setX( r.x()/width() );
					r.setY( r.y()/height() );
					r.setWidth( r.width()/width() );
					r.setHeight( r.height()/height() );

					if( game.controller() )
						game.controller()->rectEvent(r); else
						game.select(r);
					} else {
					if( game.controller() )
						game.controller()->mouseLClick( mouseCoordsF[0], mouseCoordsF[1] ); else
						game.select( mouseCoordsF[0], mouseCoordsF[1] );
					}
				}
			} else {
			if( GLObject::ideObject ){
				delObject( GLObject::ideObject );
				} else
			if( game.controller() )
				game.controller()->mouseRClick( mouseCoordsF[0], mouseCoordsF[1] );
			}

		isRotation = 0;
		selRect.finish();
		}

void GLWidget::wheelEvent ( QWheelEvent * event ){
		if( GLObject::ideObject ){
			float dR = event->delta()*0.2;
			GLObject::ideObject->getObject().setRotateZ(
						int( (GLObject::ideObject->getObject().zRotation()+dR)/10.0)*10.0 );
			return;
			}

		float d = event->delta()*0.001*camera.distance();

		if( camera.distance()-d >0 )
			camera.setDistance( camera.distance() - d );
		//update();
		}

void GLWidget::keyReleaseEvent(QKeyEvent *event){
		currKey = 0;

		if( event->key()==Qt::Key_F6 )
			load();//game.serialize("./test.sav", 1);

		if( event->key()==Qt::Key_F5 )
			save();//game.serialize("./test.sav", 0);

		if( event->key()==Qt::Key_F11 )
			BmpMap::load(game, "./bmp/map.png");
		}

void GLWidget::keyPressEvent(QKeyEvent *event){
		currKey = event->key();
		HotKeys::keyEvent( event );

		if( event->key() == Qt::Key_Home)
			camera.setAngles( camera.rotXY(), camera.rotXZ()+5);
		if( event->key() == Qt::Key_Delete)
			camera.setAngles( camera.rotXY(), camera.rotXZ()-5);

		if( event->key() == Qt::Key_PageUp)
			camera.setAngles( camera.rotXY()+5, camera.rotXZ());
		if( event->key() == Qt::Key_PageDown)
			camera.setAngles( camera.rotXY()-5, camera.rotXZ());
		}

void GLWidget::moveCamera(){
		if( selRect.isStarted() ){
			return;
			}

		float camV = 0.1* SettingsWidget::settings.cameraSpeed * camera.distance();
		const int dRect = 8;

		if( currKey == Qt::Key_Up )
			camera.move( camV, 0);
		if( currKey == Qt::Key_Down )
			camera.move(-camV, 0);

		if( currKey == Qt::Key_Left )
			camera.move( 0, -camV);
		if( currKey == Qt::Key_Right )
			camera.move( 0,  camV);


		QPoint pos = -mainWindow->pos();
		if( pos.x() < 0 )
			pos.setX(0);
		if( pos.y() < 0 )
			pos.setY(0);

		if( pos.x() + QCursor::pos().x() < dRect )
			camera.move( 0, -camV);

		if( pos.x() + QCursor::pos().x() > mainWindow->width()-dRect )
			camera.move( 0,  camV);

		if( pos.y() + QCursor::pos().y() < dRect )
			camera.move( camV, 0);

		if( pos.y() + QCursor::pos().y() > mainWindow->height()-dRect )
			camera.move(-camV, 0);

		if( camera.x() < 0)
			camera.setPos(0, camera.y(), camera.z() );
		if( camera.y() < 0)
			camera.setPos(camera.x(), 0, camera.z() );

		if( camera.x() > game.map.widthf() )
			camera.setPos(game.map.widthf(), camera.y(), camera.z() );
		if( camera.y() > game.map.heightf() )
			camera.setPos(camera.x(), game.map.heightf(), camera.z() );

		for(int i=0; i<scene.lights().size(); ++i){
			scene.lights().at(i).
					setPosition( camera.x(), camera.y(), camera.z() );
			}
		}

void GLWidget::updateMouseCoords(int mx, int my, double *out){
    GLint    viewport[4] = {0, 0, width(), height()};
    GLdouble mvMatrix[16], ProjMatrix[16];
    GLint    RealY;

  //    int mx = mouseCoords2d[0],
  //        my = mouseCoords2d[1];

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

    RealY = viewport[3] - my - 1;

    GLdouble vec1[3] = {},
             vec2[3] = {};
    gluUnProject (mx, RealY, 0.0,
                  mvMatrix, ProjMatrix, viewport,
                  &vec1[0], &vec1[1], &vec1[2]);
    gluUnProject (mx, RealY, 1.0,
                  mvMatrix, ProjMatrix, viewport,
                  &vec2[0], &vec2[1], &vec2[2]);

    for(int i=0; i<3; ++i){
      vec2[i] = vec1[i]-vec2[i];
      }

    if( vec2[2]==0.0 ){
      qDebug() << "mouseCoords invalid to project";
      return;
      }

    for(int i=0; i<3; ++i){
      vec2[i]/=vec2[2];
      }

    for(int i=0; i<3; ++i){
      vec1[i] = vec1[i] - vec2[i]*vec1[2];
      }

    out[0] = vec1[0];
    out[1] = vec1[1];
    out[2] = 0.0;

    if( useSnapLayout ){
      for(int i=0; i<3; ++i){
        out[i]*=2.0;
        out[i]+=0.5;
        out[i] = (int)out[i];
        out[i]/=2.0;
        }
      }
    }

void GLWidget::updateMouseCoords(int mx, int my){
    updateMouseCoords(mx, my, mouseCoords);
    game.mouseMoveEvent(mouseCoords[0], mouseCoords[1], mouseCoords[2]);

    bool s = useSnapLayout;
    useSnapLayout = 0;
    updateMouseCoords(mx, my, mouseCoordsF);
    useSnapLayout = s;
    }

GLObject* GLWidget::addObject( const std::string &s ){
    delObject( GLObject::ideObject );

    if( s.size() ){
      GLObject::ideObject = new GLObject( scene, s );
      game.add( GLObject::ideObject );
      GLObject::ideObject->setPlayler( curIdePl );

			GLObject::ideObject->
					setPosition( mouseCoords[0], mouseCoords[1], mouseCoords[2] );
			return GLObject::ideObject;
			}

		return 0;
		}

void GLWidget:: delObject(GLObject *& obj){
    game.del(obj);
    }

void GLWidget::upsetObjectData(float x, float y, float z,
                               float sx, float sy, float sz, float rotation){
    if( GLObject::ideObject ){
      GLObject::ideObject->setPosition(x,y,z);
      GLObject::ideObject->setSize(sx, sy, sz);
      GLObject::ideObject->getObject().setRotateZ(rotation);
      }
    }

void GLWidget::useSnap(bool use){
    useSnapLayout = use;
    }

void GLWidget::checkGL(){
		if( scene.render().wasInit() )
			return;
		glInit();
		}

bool GLWidget::load(){
    timer->stop();
    checkGL();
    makeCurrent();

    //releaseKeyboard();
    bool ok = SaveLoadDialog::load();

		timer->start();
		setFocus();
		return ok;
		//grabKeyboard();
		}

void GLWidget::startDemo( QString file,
                          std::vector<StartFFAWidget::PlInfo>& info){
    timer->stop();
    checkGL();
    makeCurrent();

    game.finish();
    game.start(2);

    for(size_t i=0; i<info.size(); ++i){
      game.playler(i+1).setDrived( info[i].isHuman );
      game.playler(i+1).setActive( info[i].exist   );
      game.playler(i+1).setLevel ( info[i].level   );
      }

    BmpMap::load(game, file.toStdString() );

		game.findCameraPosition( camera );
		timer->start();
		}

bool GLWidget::save(){
    timer->stop();
    checkGL();
    makeCurrent();

    //releaseKeyboard();
    bool ok = SaveLoadDialog::save();

		timer->start();
		setFocus();
		return ok;
		//grabKeyboard();
		}
