#include "adapter.h"

#include <MyGL/IScene>
#include <MyGL/IData>
#include <MyGL/IShaderLoader>
#include <MyGL/IShaderEnvironment>

#include "settingswidget.h"

MyGL::IShader *Adapter::bloom = 0;

Adapter::Adapter( MyGL::IScene& s ): MyGL::Adapter(s){
  bloom = 0;
  }

MyGL::IShader* Adapter::getLincShader() const{
    if( bloom )
      return bloom;

    if( isBloom() )
      scene().shaderLoader().enviroment()->push("BLOOM", "");

    if( SettingsWidget::settings.fog )
      scene().shaderLoader().enviroment()->push("FOG", "");

    MyGL::IShader * s =
      scene().dataControl()->addShader( "MyGL::LincShader",
                                        "./shaders/postEfects/linc.vert",
                                        "./shaders/postEfects/linc.frag" );

    if( isBloom() )
      scene().shaderLoader().enviroment()->pop("BLOOM");

    if( SettingsWidget::settings.fog )
      scene().shaderLoader().enviroment()->pop("FOG");

    bloom = s;
    return s;
    }

bool Adapter::isBloom() const{
    return SettingsWidget::settings.bloom;
    }

bool Adapter::isShadowMapping() const{
    return SettingsWidget::settings.shadows;
    }
