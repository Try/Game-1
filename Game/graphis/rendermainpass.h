#ifndef RENDERMAINPASS_H
#define RENDERMAINPASS_H

#include <MyGL/ForwardRender/MainPass>

class RenderMainPass:public MyGL::MainPass{
  public:
    RenderMainPass( MyGL::IScene &s, MyGL::IModel *quad,
                    const MyGL::Adapter &adapter  );

  private:
    using MainPass::makeAlgo;
    void makeAlgo( std::vector< MyGL::IRenderPass* > &out,
                   const MyGL::Adapter &adapter );
  };

#endif // RENDERMAINPASS_H
