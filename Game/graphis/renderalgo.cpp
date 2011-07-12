#include "renderalgo.h"

#include <MyGL/ForwardRender/MainPass>
#include "graphis/rendermainpass.h"

#include "adapter.h"

using namespace MyGL;

RenderAlgo::RenderAlgo(IScene &s, const ::Adapter& a):
            MyGL::ForwardRenderAlgo( s, a, 0){
    makeAlgo(a);

    setBloom( a.isBloom() );
    setShadowPass( a.isShadowMapping() );
    }

MainPass* RenderAlgo::allockMainPass( const MyGL::Adapter &adapter ){
    RenderMainPass *r =  new RenderMainPass( scene(), quad, adapter );

    return r;
    }
