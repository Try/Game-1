#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <MyGL/Scene>

class GameSceneGraph;

class GameScene:public MyGL::Scene{
  public:
    GameScene();

    MyGL::ISceneGraph* allocSceneGraph();
    GameSceneGraph * getSceneGraph();
  private:
    GameSceneGraph *graph;
    MyGL::IRenderAlgo* allocRenderAlgo();
  };

#endif // GAMESCENE_H
