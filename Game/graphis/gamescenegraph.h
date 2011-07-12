#ifndef GAMESCENEGRAPH_H
#define GAMESCENEGRAPH_H

#include <MyGL/SceneGraph>

class GameSceneGraph:public MyGL::ISceneGraph{
  public:
    GameSceneGraph( MyGL::IScene &s );

    void addObjectEvent(MyGL::IGraphicsObject &obj);
    void delObjectEvent(MyGL::IGraphicsObject &obj);

    bool isObjectVisible( const MyGL::IGraphicsObject &obj);

    void beginFrame();
    void beginFrame( MyGL::IRenderPass&  );
    void endFrame();

    double gameViewRect[4][3];

    static GameSceneGraph* instance();

    void updateVisible();
    std::vector<MyGL::IGraphicsObject*>& visible();

    MyGL::IGraphicsObject* visible(int num);
    int visiblesCount();
  private:
    MyGL::SceneGraph graph;
    MyGL::IScene    &scene;

    static GameSceneGraph *inst;

    float x,y,z;
    double testRect[2][2];

    std::vector<MyGL::IGraphicsObject*> visObj;

    static bool compare( const MyGL::IGraphicsObject *,
                         const MyGL::IGraphicsObject * );
    static bool compareSh( const MyGL::IGraphicsObject *,
                           const MyGL::IGraphicsObject * );

    static float size(const MyGL::IGraphicsObject *);

    enum Mode{
      Shadow,
      Forward
      };

    void beginFrame(Mode);
    void updateVisible(Mode m);
  };

#endif // GAMESCENEGRAPH_H
