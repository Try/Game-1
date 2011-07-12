#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect colorBuffer;
uniform sampler2DRect depthBuffer;
uniform sampler2D shadowMap;

// uniform mat4  lMatrix;

float getDepth( in vec2 coord ){
    return texture2DRect(depthBuffer, coord).r/ gl_DepthRange.diff; 
    }

vec3 calcColor(in vec2 coord){
    return texture2DRect(colorBuffer, coord).rgb*
           texture2D(shadowMap,   coord).rgb * vec3(1.0, 0.0, 0.0);
    }

void main (void){
    
    gl_FragColor = vec4( calcColor( gl_TexCoord[0].xy ), 1.0);
    }









