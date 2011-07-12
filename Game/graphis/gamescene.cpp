#include "gamescene.h"

#include <MyGL/CGL>
#include <MyGL/SceneGraph>

#include "gamescenegraph.h"
#include "renderalgo.h"

#include "adapter.h"

#include <MyGL/ForwardRender/Adapter>

GameScene::GameScene(): Scene( new MyGL::CGL() ){
    graph = 0;
    }

MyGL::ISceneGraph* GameScene::allocSceneGraph(){
    graph = new GameSceneGraph(*this);
    return graph;
    }

GameSceneGraph * GameScene::getSceneGraph(){
    return graph;
    }

MyGL::IRenderAlgo* GameScene::allocRenderAlgo(){
    return new RenderAlgo( *this, ::Adapter( *this ) );
    }
