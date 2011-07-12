#ifndef GAME_H
#define GAME_H

#include "objectcollection.h"
#include "map.h"
#include "control/icontroller.h"
#include "utils/randomgen.h"

#include <QElapsedTimer>

namespace MyGL{
  class IScene;
  class ICamera;
  }

class Playler;

class Game{
  public:
    Game( MyGL::IScene&,
          QLayout * gui );
    ~Game();

    void start(int plCount);
    void finish();

    void findCameraPosition( MyGL::ICamera &c );
    void setCameraPosition( GLObject* );
    void setCameraPosition( float mapX, float mapY );

    void tick();
    int  ticks();
    void tick(int count);

		void add(GLObject * );
		GLObject* add(const std::string& );
		void del(GLObject *&);

		void select( QRectF selRect );
		void select( GLObject* );
		void select( double x, double y );
		void unSelect();

		void command(float x, float y);
		void command( GLObject * taget );
		void aClick (float x, float y);
		void holdPosition();
		void stopMove();

		void mouseMoveEvent(float x, float y, float z);

		void initializeGL();
		void freeGPUData();

		const std::vector<GLObject*>& selected() const;
		std::vector<GLObject*>& interactive();

		static Game& instance();
		MyGL::IScene& getScene();

		Map      map;
		unsigned rand();
		double   rand(double, double);

		Playler& playler(int id);
		int playlersCount();
		IController* controller();

		ObjectCollection& objects();

		bool serialize(const std::string &file, bool in);
		bool serializeMap(const std::string &file, bool in);

    int  find(GLObject *);
    void setPause(bool );
    GLObject* getObject(int id);

    struct PlInfo{
      int gold;
      int lim, maxLim;
      };
    PlInfo getPlInfo();

    void createController();
    void setDHeight(float x, float y, float d, float r);

    void setCtrlLayout( QLayout* );
  private:
    bool pause;

    ObjectCollection object;
    MyGL::IScene &scene;
    IController * ctrl;

    std::vector< Playler* > playlers;

		void reposition();
		static Game *inst;

		RandomGen rrand;
		QLayout * layControl;

		void setController(IController * ctrl);
		void playlersTick();

		QElapsedTimer  stime;
		unsigned ticksCount;

		void finishLoad();

		class MapHead;
	};

#endif // GAME_H
