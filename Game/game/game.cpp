#include "game.h"

#include "globject.h"
#include "playler.h"

#include "control/unitctrl.h"

#include "ui_mainwindow.h"

Game *Game::inst = 0;

#include "dataCtrl/filestream.h"

#include "glwidget.h"
#include "movealgo.h"

#include "game/utils/spatialindex.h"
#include "game/unitbehavior.h"
#include "game/warriorbehavior.h"

#include <cmath>
#include "log.h"


#include "graphis/deathanimation.h"

struct Game::MapHead{
    char   fType[4];
    int    version;
    //bool   hasPriviewImage;
    //int    priviewSize[2];
    //size_t extInfoSize;
    };

Game::Game(MyGL::IScene& s, QLayout * lay):scene(s){
    layControl = lay;

    inst  = this;

    ctrl  = 0;
    // setController( new UnitCtrl::Controller() );
    setPause(0);

    ticksCount = 0;
    stime.start();
    }

Game::~Game(){
    finish();
    }

Game& Game::instance(){
    return *inst;
    }

void Game::setController(IController * c){
    delete ctrl;
    ctrl = c;

    if( ctrl )
      ctrl->createGUI( layControl );
    }

void Game::start( int plCount ){
    finish();

    stime.start();
    ticksCount = 0;

    map.resize(64, 64);

    rrand.reset();

    for(int i=-1; i<plCount; ++i){
      playlers.push_back( new Playler( *this, i+1 ) );
      }

    playler(1).setDrived(1);

    object.updateGUI();
    }

void Game::findCameraPosition( MyGL::ICamera &c ){
    for(int i=0; i<object.size(); ++i){
      if( object[i].getClass()->name=="castle" &&
          object[i].playlerPtr().isDrived() ){
        c.setPos( object[i].x(), object[i].y(), 0 );
        return;
        }
      }

    for(int i=0; i<object.size(); ++i){
      if( object[i].getClass()->name=="castle" ){
        c.setPos( object[i].x(), object[i].y(), 0 );
        return;
        }
      }
    }

void Game::setCameraPosition( float mapX, float mapY ){
    scene.render().camera().setPos( Map::coordWX(mapX), Map::coordWY(mapY), 0 );
    }

void Game::setCameraPosition( GLObject *obj ){
    scene.render().camera().setPos( obj->x(), obj->y(), 0 );
    }

void Game::finish(){
    setController(0);

    object.clear();

    for(unsigned i=0; i<playlers.size(); ++i){
      delete playlers[i];
      }
    playlers.clear();

    DeathAnimation::releace();
    }

void Game::playlersTick(){
    for(size_t i=0; i<playlers.size(); ++i)
      playlers[i]->tick();
    }

MyGL::IScene& Game::getScene(){
    return scene;
    }

Playler& Game::playler(int id){
    while( (int)playlers.size() <= id ){
      playlers.push_back( new Playler( *this, playlers.size() ) );
      if( id>=20 )
        throw "bad playler index";
      }

    return *playlers[ id];
    }

int Game::playlersCount(){
    return playlers.size();
    }

IController* Game::controller(){
    return ctrl;
    }

const std::vector<GLObject*>& Game::selected() const{
    return object.selected();
    }

std::vector<GLObject*>& Game::interactive(){
    return object.interactive();
    }

void Game::initializeGL(){
    map.initializeGL( scene );

    start(1);
    }

void Game::freeGPUData(){
    map.freeGPUData();
    }

int Game::ticks(){
    qint64 t = stime.elapsed();

    //qDebug() << "t = " << t;

    t /= 60;

    int r = t-ticksCount;
    //qDebug() << "steps = " << r;

    int oldR = r;
    r = std::min(10, std::max(0, r));

    for(int i=0; i<r; ++i){
      tick();
      }

    ticksCount += (oldR-r);//drop ticks
    map.refreshMiniMap();
    return oldR;
    }

void Game::tick(int count){
    for(; count>0; --count)
      tick();
    map.refreshMiniMap();
    }

void Game::tick(){
    ++ticksCount;

    if( pause )
      return;

    QElapsedTimer timer;
    timer.start();

    SpatialIndex index;
    index.clear( map.widthf(), map.heightf() );

    for(size_t i=0; i<interactive().size(); ++i){
      index.add( interactive()[i] );
      }
    //qDebug() << "index pass: " << timer.elapsed();
    //timer.restart();

    reposition();
    object.tick();
    //qDebug() << "objects pass: " << timer.elapsed();
    //timer.restart();

    playlersTick();
    MoveAlgo::tick();
    DeathAnimation::tickAll();
    //qDebug() << "playler pass: " << timer.elapsed();

    //qDebug() << "-----";
    }

void Game::select( QRectF selRect ){
    object.select( selRect );
    createController();
    }

void Game::select( double x, double y ){
    object.select( x,y );
    createController();
    }

void Game::select( GLObject * obj ){
    object.select( obj );
    createController();
    }

void Game::setCtrlLayout( QLayout *l ){
    layControl = l;
    }

void Game::createController(){
    setController(0);

    if( !object.isGroupControlled() )
      return;

    for(unsigned i=0; i<object.selected().size(); ++i){
      IController *c = object.selected()[i]->createController() ;
      if( c ){
        setController( c );
        return;
        }
      }
    }

void Game::setPause(bool p){
    pause = p;
    }

void Game::unSelect(){
    object.unSelect();
    }

void Game::command(float x, float y){
    object.command(x, y);
    }

void Game::command( GLObject * taget ){
    object.command(taget);
    }

void Game::aClick (float x, float y){
    object.aClick(x, y);
    }

void Game::holdPosition(){
    for(int i=0; i<object.size(); ++i){
      GLObject *obj = &object[i];
      {

        UnitBehavior *war = (UnitBehavior*)obj->getBehavior("unit");

        if( war ){
          war->holdPosition();
          }
        }
      }

    }

void Game::stopMove(){
    for(int i=0; i<object.size(); ++i){
      GLObject *obj = &object[i];
      {

        UnitBehavior *war = (UnitBehavior*)obj->getBehavior("unit");

        if( war ){
          war->stopMove();
          }
        }
      }
    }

GLObject* Game::add(const std::string& src){
    GLObject* obj = new GLObject(scene, src);
    add( obj );

    return obj;
    }

void Game::add(GLObject * x){
    object.add(x);
    }

void Game::del(GLObject *&x){
    bool ctrl = object.selected().size() && (x==object.selected()[0] );
    object.del(x);

    if( ctrl ){
      createController();
      }
    }

unsigned Game::rand(){
    return rrand();
    }

double  Game::rand(double x, double y){
    double k = rrand();
    k /= RandomGen::Max;

    //qDebug() << "k = " << k;

    return x + (y - x)*k;
    }

void Game::reposition(){
    for(unsigned i=0; i<object.moviable().size(); ++i)
      if( object.moviable()[i]->needToMoveDisplace() ){
        GLObject* tmp =
            SpatialIndex::instance()->findNearest( object.moviable()[i]);

        if( tmp && object.moviable()[i]->collision( *tmp ) ){
          object.moviable()[i]->setMoveDisplace( *tmp );
          tmp->setMoveDisplace( *object.moviable()[i] );
          }
        }
    }

bool Game::serializeMap(const std::string &file, bool in){
    FileStream::openMode mode = FileStream::in;
    if( !in ){
      mode = FileStream::out;
      } else {
      finish();
      start(1);
      }

    FileStream f(file, mode);

    if( !f.isOpen() )
      return 0;

    MapHead head;
    memcpy( head.fType, "Map", 4);
    head.version = 0;

    if( f.isIn() )
      f.read ( head ); else
      f.write( head );

    if( std::string(head.fType)!="Map" ){
      Log() << "Error while load map file: file format is not valid";
      Log() << "\"" << file <<"\"";
      return 0;
      }

    if( f.isOut() ){
      f << map.width() << map.height();
      } else {
      int w,h;
      f >> w >> h;

      map.resize(w/2, h/2);
      map.rebuildPaintData();
      }

    for(unsigned i=0; i<playlers.size(); ++i)
      playlers[i]->serialize( f );

    object.serialize( f, 1);
    rrand. serialize( f );

    finishLoad();
    return 1;
    }

bool Game::serialize(const std::string &file, bool in){
    FileStream::openMode mode = FileStream::in;
    if( !in ){
      mode = FileStream::out;
      } else {
      finish();
      start(1);
      }

    FileStream f(file, mode);

    if( !f.isOpen() )
      return 0;

    int plS = playlers.size();
    f + plS;
    if( f.isIn() ){
      start( plS-1 );
      float x,y;
      f >> x >> y;
      scene.render().camera().setPos(x,y,0);
      } else {
      float x = scene.render().camera().x(),
            y = scene.render().camera().y();
      f << x << y;
      }

    if( f.isOut() ){
      f << map.width() << map.height();
      } else {
      int w,h;
      f >> w >> h;

      map.resize(w/2, h/2);
      }

    for(unsigned i=0; i<playlers.size(); ++i)
      playlers[i]->serialize( f );

    object.serialize( f );
    rrand. serialize( f );

    if( f.isIn() ){
      createController();
      }

    map.serialize( f );
    //map.rebuildPaintData();

    finishLoad();
    return 1;
    }

void Game::finishLoad(){
    MoveAlgo::resetCash();
    ticksCount = 0;
    stime.start();
    }


int Game::find(GLObject *obj){
    return object.find(obj);
    }

GLObject* Game::getObject(int id){
    return &object[id];
    }

void Game::mouseMoveEvent(float x, float y, float z){
    if( controller() )
      controller()->mouseMoveEvent(x,y,z);
    }

Game::PlInfo Game::getPlInfo(){
    Game::PlInfo re;

    re.gold   = 0;
    re.lim    = 0;
    re.maxLim = 0;

    for( size_t i=0; i<playlers.size(); ++i){
      if( playler(i).isDrived() ){
        re.gold   = playlers[i]->gold();
        re.maxLim = playlers[i]->maxLim();
        re.lim    = re.maxLim - playlers[i]->lim();
        }
      }

    return re;
    }

ObjectCollection& Game::objects(){
    return object;
    }

void Game::setDHeight(float x, float y, float d, float r){
    x = Map::coordX(x);
    y = Map::coordY(y);
    for(int i= -r; i<=r; ++i)
      for(int j = -r; j<=r; ++j){
        float dH = d*std::max(r - sqrt(i*i+j*j), 0.0 );
        if( map.exist( x+i, y+j )){
          map.setHeight(x+i, y+j, map.height(x+i, y+j)+dH);
          }
        }

    map.rebuildPaintData();

    for(int i=0; i<object.size(); ++i){
      object[i].updateZCoord();
      }

    }
