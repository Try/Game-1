#ifndef VIRTUALTEXTURINGPASS_H
#define VIRTUALTEXTURINGPASS_H

#include "graphis/abstractuserpass.h"

namespace MyGL{
  class ITextureRectangle;
  class MainPass;
  }

class VirtualTexturingPass:public AbstractUserPass{
  public:
    VirtualTexturingPass( MyGL::IScene &s,
                          MyGL::MainPass *mp,
                          MyGL::ITextureRectangle &mpb );
    ~VirtualTexturingPass();

    void exec();
    Pass::Type type() const{ return (Pass::Type)UPass::VirtualTexturigPass; }

    static void setMapSize(int x, int y, int tw, int th);
  private:
    MyGL::ITextureRectangle *screen, *preScreen, *mpassBuf;
    MyGL::MainPass    *mpass;

    void resizeFrame();

    class Data;
    Data *data;

    void paintLand();
    static VirtualTexturingPass* inst;
  };

#endif // VIRTUALTEXTURINGPASS_H

