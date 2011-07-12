#include "virtualtexturingpass.h"

#include <MyGL/ITexture2d>
#include <MyGL/TextureRectangle>

#include <MyGL/FBO>
#include <MyGL/IData>
#include <MyGL/ForwardRender/MainPass>

#include <MyGL/Filter>
#include <MyGL/IUniform4f>
#include <MyGL/IShader>

#include "clandobject.h"

using namespace MyGL;

class VirtualTexturingPass::Data{
    public:
      Data( IScene &scene ):postProcess(scene){
        }

      Filter postProcess;
      IUniformSampler *texture, *mask;
      IUniform4f      *scale;
    };

VirtualTexturingPass* VirtualTexturingPass::inst = 0;

VirtualTexturingPass::VirtualTexturingPass( MyGL::IScene   &s,
                                            MyGL::MainPass *mp,
                                            MyGL::ITextureRectangle &mpb ):
                      AbstractUserPass(s){
    data = new Data( scene() );
    inst = this;

    screen    = new TextureRectangle( scene().render() );
    preScreen = new TextureRectangle( scene().render() );

    mpassBuf = &mpb;
    mpass    = mp;

    screen->load(0,    MyGL::ITexture::InputFormat::RGB8,
                 0, 0, MyGL::ITexture::Format::RGBA16 );

    data->postProcess.
        setShader( scene().dataControl()->shader("virtualTexturing") );
    data->scale = data->postProcess.shader()->uniform4f("scale");
    if( data->scale )
      data->scale->set(16);

    data->postProcess.renderState().setAlphaTestRef(0.001);
    data->postProcess.renderState().
        setAlphaTestMode( IRenderState::AlphaTestMode::Greater );

    data->postProcess.renderState().
        setBlendMode( IRenderState::AlphaBlendMode::one,
                      IRenderState::AlphaBlendMode::one );

    data->postProcess.setInput( "uv_texture", screen );
    data->postProcess.setQuadModel( mp->quadModel() );
    data->postProcess.setInput( "rand",
                                scene().dataControl()->texture("rand32") );

    data->texture = data->postProcess.setInput( "texture", 0 );
    data->mask    = data->postProcess.setInput( "mask",    0 );
    }

VirtualTexturingPass::~VirtualTexturingPass(){
    delete preScreen;
    delete screen;
    delete data;
    }

void VirtualTexturingPass::resizeFrame(){
    if( screen->width()  != mpass->frameBuffer()->width() ||
        screen->height() != mpass->frameBuffer()->height() ){
      screen->load(0, MyGL::ITexture::InputFormat::RGB8,
                   mpass->frameBuffer()->width(),
                   mpass->frameBuffer()->height(),
                   MyGL::ITexture::Format::RGBA16 );

      preScreen->load(0, MyGL::ITexture::InputFormat::RGB8,
                      mpass->frameBuffer()->width(),
                      mpass->frameBuffer()->height(),
                      MyGL::ITexture::Format::RGBA16 );
      }
    }

void VirtualTexturingPass::exec(){
    resizeFrame();

    mpass->frameBuffer()->attachColorTexture( screen );
    //mpass->frameBuffer()->attachColorTexture( mpassBuf );

//    scene().render().clear( MyGL::Color(0.0),
//                            MyGL::IRender::clearColorBit );

    scene().render().begin();

    MyGL::ISceneGraph::Visibles obj( scene().graph() );

    for( int i = 0; i<obj.size(); ++i ){
      drawObject<VirtualTexturingPass>( *obj[i] );
      }

    scene().render().end();

    mpass->frameBuffer()->attachColorTexture( mpassBuf );
    paintLand();
    }

void VirtualTexturingPass::paintLand(){/*
    data->postProcess.renderState().setBlend(0);
    data->postProcess.renderState().setAlphaTestRef(0.99);
    data->postProcess.renderState().
        setAlphaTestMode( IRenderState::AlphaTestMode::Always );

    for(size_t i=0; i<CLandObject::tailMask().size(); ++i){
      data->postProcess.setInput( data->texture,
                                  CLandObject::tailMask()[i].texture );
      data->postProcess.setInput( data->mask,
                                  CLandObject::tailMask()[i].mask );
      data->postProcess.exec();
      data->postProcess.renderState().
          setAlphaTestMode( IRenderState::AlphaTestMode::GEqual );
      }


    data->postProcess.renderState().setBlend(1);
    data->postProcess.renderState().
        setAlphaTestMode( IRenderState::AlphaTestMode::Less );

    for(size_t i=1; i<CLandObject::tailMask().size(); ++i){
      data->postProcess.setInput( data->texture,
                                  CLandObject::tailMask()[i].texture );
      data->postProcess.setInput( data->mask,
                                  CLandObject::tailMask()[i].mask );
      data->postProcess.exec();

      }*/
    data->postProcess.renderState().setBlend(0);
    data->postProcess.renderState().setAlphaTestRef(0.0);
    data->postProcess.renderState().
        setAlphaTestMode( IRenderState::AlphaTestMode::Always );

    for(size_t i=0; i<CLandObject::tailMask().size(); ++i){
      data->postProcess.setInput( data->texture,
                                  CLandObject::tailMask()[i].texture );
      data->postProcess.setInput( data->mask,
                                  CLandObject::tailMask()[i].mask );
      data->postProcess.exec();
      data->postProcess.renderState().
          setAlphaTestMode( IRenderState::AlphaTestMode::GEqual );
      data->postProcess.renderState().setBlend(1);
      }
    }

void VirtualTexturingPass::setMapSize(int x, int y, int tw, int th){
    if( inst->data->scale )
      inst->data->scale->set(x/4.0, y/4.0, tw, th);
    }
