#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect mainPass;
uniform sampler2DRect glowPass;

#ifdef BLOOM
uniform sampler2DRect bloomPass;
#endif

uniform sampler2DRect depthBuffer;

#define dc 0.75

float getDepth( in vec2 coord ){
    return texture2DRect(depthBuffer, coord).r/ gl_DepthRange.diff; 
    }

vec4 getColor( in vec2 coord ){
    return texture2DRect(mainPass, coord); 
    }

#ifdef BLOOM
vec3 getBloom( in vec2 coord ){
    return texture2DRect(bloomPass, coord ).rgb;
    }
#endif

vec3 getGlow( in vec2 coord ){
    return texture2DRect(glowPass, coord ).rgb;
/*
    vec3 re;
    re = texture2DRect(glowPass, coord+vec2( 0.5, 0.0) ).rgb;
    re+= texture2DRect(glowPass, coord+vec2(-0.5, 0.0) ).rgb;
    re+= texture2DRect(glowPass, coord+vec2( 0.0, 0.5) ).rgb;
    re+= texture2DRect(glowPass, coord+vec2( 0.0,-0.5) ).rgb;

    return (re*0.5);*/
    }

vec3 calcColor(in vec2 coord){
    //vec3 cl = vec3(0.0);

    vec3 cl = getColor( coord ).rgb;

    cl += getGlow ( coord/4.0 )*0.5;

#ifdef BLOOM
    cl += getBloom( coord/8.0 )*0.075;
#endif

#ifdef FOG
    float fog = min( max( pow(getDepth(coord), 32.0)-0.9, 0.0)*3.0, 1.0);
    cl = mix(cl, vec3(0.0, 0.5, 1.0), fog);
#endif

    return cl;
    //return getGlow ( coord/8.0 );
    //return vec3(fog);//cl;
    }

void main (void){
    
    gl_FragColor = vec4( calcColor( gl_TexCoord[0].xy ), 1.0);
    }









