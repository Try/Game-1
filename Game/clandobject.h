#ifndef CLANDOBJECT_H
#define CLANDOBJECT_H

#include <MyGL/GraphicsObject>
#include <MyGL/StdMaterial>

#include <MyGL/ITexture2d>
#include <MyGL/IVBO>

#include <QImage>

namespace MyGL{
  class IScene;
  class Model;

  class ITexture2d;
  class TextureRectangle;
  }

#include <vector>

class CLandObject {
  public:
    CLandObject( MyGL::IScene &scene, const std::string &src );
    ~CLandObject();

		void setPosition(float x, float y, float z);
		void resize(int x, int y);

		void build();

		class Tail{
			public:
				MyGL::ITexture2d*       texture;
				MyGL::TextureRectangle *mask;
			};

		static std::vector<Tail>& tailMask();

		void drawTail(int id, int x, int y, float size);
	private:
		MyGL::StdMaterial   *material;
		MyGL::GraphicsObject object;

		MyGL::Model      *model;

    static void setPoint(float *p, float x, float y);
    static void setPoint(float *p, float x, float y, float z);

    void allock(int w, int h);
    void setPoint(int px, int py, float x, float y, float z);
    void setVertex(MyGL::IVBO &vbo,
                   int px, int py, int c,
                   float x, float y, float z);

    int w,h;

    float getHeight(float x, float y);

    static std::vector<Tail> m_tailMask;
    static std::vector<QImage> m_tailData;

    void normalize(int id);

    static int tailMapResolution;
  };

#endif // CLANDOBJECT_H
