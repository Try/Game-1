uniform sampler2D diffuse_texture;

vec4 getColor( in vec2 coord ){
    return texture2D(diffuse_texture, coord);
    }

void main (void){
    
    gl_FragColor = vec4(getColor( gl_TexCoord[0].xy ).rgb, 1.0);
    }









