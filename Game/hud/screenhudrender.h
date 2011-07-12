#ifndef SCREENHUDRENDER_H
#define SCREENHUDRENDER_H

#include <QImage>

namespace MyGL{
  class IScene;
  class IShader;
  class IModel;
  class IUniform4f;
  }

class ScreenHudRender{
  public:
    ScreenHudRender( MyGL::IScene &s);

    const QImage& getImage();

    void drawSelRect( const QRect &r, float w, float h );
    void initGl();
  private:
    MyGL::IScene &scene;
    MyGL::IShader *sh;
    MyGL::IModel  *quad;
    MyGL::IUniform4f *rect;

    QImage image;
  };

#endif // SCREENHUDRENDER_H
