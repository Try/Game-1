#include "materials.h"

#include <MyGL/StdMaterial>
#include <MyGL/IData>

#include "../runtime/gameclasses.h"
#include "../runtime/gameobjectclass.h"

#include <QDebug>

#include <MyGL/IShaderLoader>
#include <MyGL/IShaderEnvironment>

#include "settingswidget.h"

Materials* Materials::inst = 0;

Materials::Materials(MyGL::IScene &s):scene(s){
    inst = this;
    }

Materials::~Materials(){
    Data::iterator i;
    for(i = data.begin(); i!=data.end(); ++i){
      delete i->second;
      }
    inst = 0;
    //data.clear();
    }

MyGL::IShader* Materials::get( Macro & macro, bool shadow ){
    if( !(SettingsWidget::settings.shadows && shadow)  ){
      macro.insert("NO_SHADOWS");
      }

    return get(  macro,
                 "./shaders/model/ffp.vert",
                 "./shaders/model/ffp.frag",
                 "shader");
    }
MyGL::IShader* Materials::getShadowShader(){
    Macro m;
    return getShadowShader(m);
    }

MyGL::IShader* Materials::getShadowShader( Macro & macro ){
    std::string name = "shadow_shader";
    return get(  macro,
                 "./shaders/model/shadow_uber.vert",
                 "./shaders/model/shadow_uber.frag",
                 name);
    }

MyGL::IShader* Materials::get(  Macro & macro,
                                const std::string& vs,
                                const std::string& fs,
                                const std::string& _name){
    std::string name = _name;
    for( std::set<std::string>::iterator i = macro.begin();
         i!=macro.end(); ++i){
      name+="[" + *i +"]";
      }

    //qDebug() << name.data();
    MyGL::IShader* sh = scene.dataControl()->shader( name );

    if( sh==0 ){
      for( std::set<std::string>::iterator i = macro.begin();
           i!=macro.end(); ++i){
        scene.shaderLoader().enviroment()->push( *i, "1");
        }

      sh =
        scene.dataControl()->addShader( name.data(),
                                        vs.data(),
                                        fs.data() );

      for( std::set<std::string>::iterator i = macro.begin();
           i!=macro.end(); ++i){
        scene.shaderLoader().enviroment()->pop( *i);
        }

      return sh;
      } else {
      return sh;
      }
    }

Materials& Materials::instance(){
    return *inst;
    }
