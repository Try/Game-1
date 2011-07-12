#include "gamescenegraph.h"

#include <MyGL/IGraphicsObject>
#include <MyGL/IModelInfo>

#include <MyGL/IScene>
#include <MyGL/IRender>
#include <MyGL/ICamera>

#include <MyGL/IObjectCollection>
#include <MyGL/IRenderPass>

#include <cmath>
#include <cstdlib>
#include <cstring>

#include <QElapsedTimer>
#include <QDebug>

#include <algorithm>

using namespace std;

GameSceneGraph* GameSceneGraph::inst = 0;

GameSceneGraph::GameSceneGraph( MyGL::IScene &s ):
                graph(s), scene(s){
    inst = this;
    memset( gameViewRect, 0, sizeof(gameViewRect) );
    }

GameSceneGraph* GameSceneGraph::instance(){
    return inst;
    }

void GameSceneGraph::addObjectEvent(MyGL::IGraphicsObject &obj){
    graph.addObjectEvent(obj);
    }

void GameSceneGraph::delObjectEvent(MyGL::IGraphicsObject &obj){
    graph.delObjectEvent(obj);
    }

bool GameSceneGraph::isObjectVisible( const MyGL::IGraphicsObject &obj){
    if( obj.isAlvaysVisible() )
      return 1;

//    if( obj.x() < testRect[0][0] && obj.x() > testRect[1][0] &&
//        obj.y() < testRect[0][1] && obj.y() > testRect[1][1] )
//      return 1;

    float d = obj.modelInfo().radius();
    if( obj.x() > testRect[0][0]-d && obj.x() < testRect[1][0]+d &&
        obj.y() > testRect[0][1]-d && obj.y() < testRect[1][1]+d )
      return 1; else
      return 0;
    }

void GameSceneGraph::beginFrame( MyGL::IRenderPass&  p ){
    if( p.type()==MyGL::IRenderPass::Pass::Shadow )
      beginFrame( Shadow ); else
      beginFrame( Forward );
    }

void GameSceneGraph::beginFrame(){
    beginFrame( Forward );
    }

void GameSceneGraph::beginFrame( Mode m ){
    x = scene.render().camera().x();
    y = scene.render().camera().y();
    z = scene.render().camera().z();

    for(int i=0; i<2; ++i){
      testRect[i][0] = gameViewRect[0][0];
      testRect[i][1] = gameViewRect[0][1];
      }

    for(int i=0; i<4; ++i){
      testRect[0][0] = min(gameViewRect[i][0], testRect[0][0]);
      testRect[0][1] = min(gameViewRect[i][1], testRect[0][1]);

      testRect[1][0] = max(gameViewRect[i][0], testRect[1][0]);
      testRect[1][1] = max(gameViewRect[i][1], testRect[1][1]);
      }

    graph.beginFrame();
    updateVisible(m);
    }

void GameSceneGraph::endFrame(){
    graph.endFrame();
    }

void GameSceneGraph::updateVisible( ){
    qDebug() << "GameSceneGraph::updateVisible";
    }

void GameSceneGraph::updateVisible( Mode m ){
    size_t nsize = 0;

    size_t objSize = scene.objects().size();
    for(size_t i=0; i<objSize; ++i){
      if( isObjectVisible( scene.objects()[i] ) &&
          graph.isObjectVisible( scene.objects()[i] ) ){
        if( nsize <= visObj.size() ){
          visObj.push_back(0);
          }

        visObj[nsize] = &scene.objects()[i];
        ++nsize;
        }
      }

    visObj.resize( nsize );

    if( m==Forward ){
      sort( visObj.begin(),
            visObj.end(),
            compare );
      } else {
      sort( visObj.begin(),
            visObj.end(),
            compareSh );
      }

    // visObj.resize( nsize/2 );
    }

bool GameSceneGraph::compare( const MyGL::IGraphicsObject *ag,
                              const MyGL::IGraphicsObject *bg ){
    static const float k = 0.01;

    int s1 = k*size(ag)*int(bg->isAlvaysVisible()==0),
        s2 = k*size(bg)*int(ag->isAlvaysVisible()==0);

    return s1 > s2;
    }

bool GameSceneGraph::compareSh( const MyGL::IGraphicsObject *ag,
                                const MyGL::IGraphicsObject *bg ){
    int s1 = size(ag),
        s2 = size(bg);

    return s1 > s2;
    }

float GameSceneGraph::size(const MyGL::IGraphicsObject *ag){
    const MyGL::IModelInfo &a = ag->modelInfo();

    return  (a.maxX()-a.minX())*
            (a.maxY()-a.minY())*
            (a.maxZ()-a.minZ());

    }

std::vector< MyGL::IGraphicsObject*>& GameSceneGraph::visible(){
    return visObj;
    }

MyGL::IGraphicsObject* GameSceneGraph::visible(int num){
    return visObj[num];
    }

int GameSceneGraph::visiblesCount(){
    return visObj.size();
    }
