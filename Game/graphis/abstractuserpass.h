#ifndef ABSTRACTUSERPASS_H
#define ABSTRACTUSERPASS_H

#include <MyGL/ForwardRender/AbstractPass>

class AbstractUserPass: public MyGL::AbstractPass {
  public:
    AbstractUserPass( MyGL::IScene &s );
    virtual Pass::Type type() const{ return Pass::User; }

    class UPass{
      public:
      enum Type{
        VirtualTexturigPass = Pass::User+1,
        Count
        };
      };
  };

#endif // ABSTRACTUSERPASS_H
