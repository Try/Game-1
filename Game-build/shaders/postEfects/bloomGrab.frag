#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect mainPass;

vec3 getColor( in vec2 coord ){
    vec3 re;
    float dx = 1.0;

    re = texture2DRect(mainPass, coord+vec2( 0.0, 0.0) ).rgb;
    re+= texture2DRect(mainPass, coord+vec2( 0.0, dx) ).rgb;
    re+= texture2DRect(mainPass, coord+vec2(  dx, 0.0) ).rgb;
    re+= texture2DRect(mainPass, coord+vec2(  dx, dx) ).rgb;

    return (re*0.25);
    }

vec3 calcColor(in vec2 coord){
    vec3 cl = getColor( coord*2.0 );

    if( length(cl)<0.8 )
      return vec3(0.0); else
      return cl;
    }

void main (void){
    
    gl_FragColor = vec4( calcColor( gl_TexCoord[0].xy ).rgb, 1.0);
    }









