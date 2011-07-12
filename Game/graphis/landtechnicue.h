#ifndef LANDTECHNICUE_H
#define LANDTECHNICUE_H

#include <MyGL/StdTechnique>

class VirtualTexturingPass;

class LandTechnicue : public MyGL::StdTechnique{
  public:
    LandTechnicue( MyGL::IScene &s );

  private:
    bool passEvent   ( const MyGL::IRenderPass* );
    void completeDraw( const MyGL::IRenderPass* );


    bool passEvent   ( const MyGL::ColorPass* );

    bool virtualTexturePass( const VirtualTexturingPass* pass );
  };

#endif // LANDTECHNICUE_H
