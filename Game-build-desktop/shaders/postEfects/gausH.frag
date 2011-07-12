#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect input_texture;
const int radius = 5;

vec4 getColor( in vec2 coord ){
    return texture2DRect(input_texture, coord);
    }

vec4 calcColor(in vec2 coord){
    vec2 blurSize;
    blurSize = vec2(0.0, 1.0);

    vec4 sum;
    sum  = getColor( coord - 4.0*blurSize) * 0.05;
    sum += getColor( coord - 3.0*blurSize) * 0.09;
    sum += getColor( coord - 2.0*blurSize) * 0.12;
    sum += getColor( coord -     blurSize) * 0.15;
    sum += getColor( coord               ) * 0.16;
    sum += getColor( coord +     blurSize) * 0.15;
    sum += getColor( coord + 2.0*blurSize) * 0.12;
    sum += getColor( coord + 3.0*blurSize) * 0.09;
    sum += getColor( coord + 4.0*blurSize) * 0.05;
    return sum;
    }

void main (void){
    vec3 color = calcColor( gl_TexCoord[0].xy ).rgb;
    float l = color.r + color.g + color.b;
    
    gl_FragColor = vec4( 4.0*color, l);
    }









