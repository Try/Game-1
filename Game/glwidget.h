#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <MyGL/Render>
#include <MyGL/CGL>

#include <MyGL/ITexture2d>
#include <MyGL/IModel>

#include <MyGL/IUniformSampler>

#include <MyGL/ShaderLoader>
#include <MyGL/TextureLoader>
#include <MyGL/ModelLoader>
#include <MyGL/IData>

#include <MyGL/FBO>
#include <MyGL/ShaderEnvironment>
#include <MyGL/Camera>
#include <MyGL/GraphicsObject>

#include "qtshader.h"

#include "globject.h"
#include "clandobject.h"
#include <QtOpenGL/QGLWidget>

#include "runtime/gameclasses.h"
#include "dataCtrl/materials.h"

#include "game/selectrect.h"
#include "game/objectcollection.h"
#include "game/game.h"

#include "runtime/hotkeys.h"

#include "graphis/gamescene.h"
#include "dataCtrl/pixmaps.h"
#include "runtime/texturefactory.h"
#include "hud/screenhudrender.h"
#include "hud/showhint.h"

#include "widgets/startffawidget.h"

class MainWindow;

class GLWidget : public QGLWidget {
		Q_OBJECT

	public:
		explicit GLWidget(MainWindow *w, QWidget *parent = 0);
		~GLWidget();

		GLObject* addObject( const std::string &s );
		void delObject(GLObject *&);

		void upsetObjectData(float x, float y, float z,
												 float sx, float sy, float sz, float rotation);

		static GLWidget *instance();
		int curIdePl;

	protected:
		void setLayCtrl( QLayout* );
		virtual void displayDipCount( size_t, size_t, size_t  ){}
	public slots:
		void useSnap(bool use);
		void startGame();

		bool load();
		bool save();

		void startDemo( QString file,
										std::vector<StartFFAWidget::PlInfo>& info );

		void gameTick();
	private:
		void initializeGL();
		void paintGL();
		void paint2d();
		void resizeGL( int width, int height );

		void checkGL();

		ShowHint hintObject;

		MyGL::Camera      camera;
		GameScene         scene;
		ScreenHudRender   hudRender;
		TextureFactory    textureFactory;

		Pixmaps pixmaps;

		MyGL::ShaderEnvironment shaderEnv;

		GameClasses classes;
	protected:
		Game game;
	private:

		SelectRect   selRect;
		// CLandObject *land;

		static void loadTexture( MyGL::ITexture2d &tex,
														 const std::string& file, bool *ok );
		void checkErrors();

		Materials   materials;
		MainWindow *mainWindow;

		bool useSnapLayout;

		void debugPaint();
		//void unProject();
		static GLWidget *inst;
	protected:
		void mousePressEvent(QMouseEvent *);
		void mouseMoveEvent(QMouseEvent *);
		void mouseReleaseEvent(QMouseEvent *);
		void wheelEvent ( QWheelEvent * event );

		void keyPressEvent  (QKeyEvent *);
		void keyReleaseEvent(QKeyEvent *);

		virtual void ideEvents();

		void moveCamera();
		void updateMouseCoords(int mx, int my);
		void updateMouseCoords(int mx, int my, double *out);

		int isRotation;
		int oldAngles[2];

		double mouseCoords[3], mouseCoordsF[3];
		int  mouseCoords2d[2];
		bool isMousePressed;

		float shAngle;

		QTimer *timer, *paintTimer;
		int currKey;
	};

#endif // GLWIDGET_H
