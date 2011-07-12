#include "rendermainpass.h"


#include <MyGL/ForwardRender/ColorPass>
#include <MyGL/ForwardRender/AddBlendPass>
#include <MyGL/ForwardRender/TransparentPass>
#include <MyGL/ForwardRender/ShadowPass>
#include <MyGL/ForwardRender/DepthPass>
#include <MyGL/ForwardRender/SSAO>

#include "graphis/virtualtexturingpass.h"

#include "settingswidget.h"

using namespace MyGL;

RenderMainPass::RenderMainPass(IScene &s, IModel *quad,
                               const Adapter &adapter ):
                MainPass(s, adapter, quad, 0){
    makeAlgo( adapter );
    }

void RenderMainPass::makeAlgo( std::vector< MyGL::IRenderPass* > &passes,
                               const Adapter &adapter ){

    passes.push_back( new VirtualTexturingPass( scene(),
                                                this,
                                                output() ) );

    passes.push_back( new DepthPass      ( scene() ) );
    passes.push_back( new ColorPass      ( scene() ) );


    passes.push_back( new AddBlendPass   ( scene() ) );
    passes.push_back( new TransparentPass( scene() ) );

    if( SettingsWidget::settings.ssao )
      passes.push_back( new SSAOpass( scene(), adapter, this) );
    }
