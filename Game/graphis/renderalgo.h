#ifndef RENDERALGO_H
#define RENDERALGO_H

#include <MyGL/ForwardRender/RenderAlgo>

class Adapter;

class RenderAlgo: public MyGL::ForwardRenderAlgo{
  public:
    RenderAlgo( MyGL::IScene &s, const ::Adapter& adapter );

  private:
    MyGL::MainPass* allockMainPass( const MyGL::Adapter &adapter );
  };

#endif // RENDERALGO_H
