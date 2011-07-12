#include "landtechnicue.h"

#include <MyGL/IRenderPass>
#include <QDebug>

#include "graphis/abstractuserpass.h"
#include "graphis/virtualtexturingpass.h"

using namespace MyGL;

LandTechnicue::LandTechnicue( MyGL::IScene &s ): StdTechnique(s){

    }

bool LandTechnicue::passEvent   ( const MyGL::ColorPass* ){
    return 0;
    }

bool LandTechnicue::passEvent   ( const MyGL::IRenderPass* pass ){
    if( pass->type() ==
        (IRenderPass::Pass::Type)AbstractUserPass::UPass::VirtualTexturigPass ){
      return virtualTexturePass(
               static_cast<const VirtualTexturingPass*>(pass) );
      }

    return 0;
    }

bool LandTechnicue::virtualTexturePass( const VirtualTexturingPass*  ){
    storeRenderState();
    setCurrentShader( colorShader() );

    renderState().setZTest( 1 );

    if( useDepthPass() )
      renderState().setZTestMode( IRenderState::ZTestMode::Equal ); else
      renderState().setZTestMode( IRenderState::ZTestMode::Less );

    return currentShader();
    }

void LandTechnicue::completeDraw( const MyGL::IRenderPass* ){
    restoreRenderState();
    }
