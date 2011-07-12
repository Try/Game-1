#ifndef MATERIALS_H
#define MATERIALS_H

#include <string>

#include <map>
#include <set>

#include <MyGL/IShader>
#include <MyGL/IScene>

class Materials{
  public:
    Materials( MyGL::IScene &s );
    ~Materials();

    static Materials& instance();

    typedef std::set<std::string> Macro;

    MyGL::IShader* get( Macro & macro, bool shadow = 1 );
    MyGL::IShader* getShadowShader( Macro & macro );
    MyGL::IShader* getShadowShader();
  private:
    typedef std::map<std::string, MyGL::IShader*>  Data;
    Data data;
    MyGL::IScene &scene;

    static Materials* inst;

    MyGL::IShader* get( Macro & macro,
                        const std::string& vs,
                        const std::string& fs,
                        const std::string& name);
  };

#endif // MATERIALS_H
