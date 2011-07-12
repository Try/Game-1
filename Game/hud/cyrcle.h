#ifndef CYRCLE_H
#define CYRCLE_H

#include <MyGL/GraphicsObject>
#include <MyGL/StdMaterial>

#include <MyGL/ITexture2d>
#include <MyGL/IModel>

namespace MyGL{
  class IScene;
  };

class Cyrcle{
  public:
    Cyrcle( MyGL::IScene & );
    ~Cyrcle();

    void setPos(float x, float y, float z);
    void setVisible(bool v);

    void setSize(float s);
  private:
    MyGL::IScene &scene;
    MyGL::StdMaterial   *material;
    MyGL::GraphicsObject object;
  };

#endif // CYRCLE_H
