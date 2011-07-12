#ifndef VIEW_H
#define VIEW_H

#include <vector>

namespace MyGL{
  class GraphicsObject;
  class IScene;
  class IModel;
  class StdMaterial;
  }

class View{
  public:
    View( MyGL::IScene &s );
    ~View();

		void setPosition(float x, float y, float z);
		void setSize    (float x, float y, float z);

		float x() const;
		float y() const;
		float z() const;

		float xSize() const;
		float ySize() const;
		float zSize() const;

		void setRotateZ(float r);
		void setRotateXY(float r);
		float zRotation() const;

		MyGL::IModel* model();

		MyGL::GraphicsObject& view(int id);
		MyGL::GraphicsObject& operator[](int id);

		void setVisible(bool v);

		void setViewsCount( int c );
		MyGL::StdMaterial* material(int i);
	private:
		std::vector<MyGL::GraphicsObject*> m_view;
		MyGL::IScene &scene;
	};

#endif // VIEW_H
