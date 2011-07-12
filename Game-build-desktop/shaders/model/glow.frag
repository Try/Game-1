uniform sampler2D glow_texture;

vec4 calcColor(){
    return texture2D(glow_texture, gl_TexCoord[0].xy );
    }

void main (void){
    
    gl_FragColor = vec4(calcColor().rgb, 1.0);//length(calcColor().rgb) );
    }









