#ifndef __ADAPTER_H
#define __ADAPTER_H

#include <MyGL/ForwardRender/Adapter>

class Adapter:public MyGL::Adapter {
  public:
    Adapter( MyGL::IScene& s );

    MyGL::IShader* getLincShader() const;

    bool isBloom() const;
    bool isShadowMapping() const;

  private:
    static MyGL::IShader *bloom;
  };

#endif // ADAPTER_H
