#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect input_texture;
const int radius = 5;

vec4 getColor( in vec2 coord ){
    return texture2DRect(input_texture, coord);
    }

vec4 calcColor(in vec2 coord){
  /*  vec4 re;

    vec2 dCoord;
    dCoord = vec2(1.0, 0.0);

    for(int i=-radius; i<=radius; ++i){
      float k = 1.0;//( 1.0 - pow(abs(i)/radius, 2.0) );
      re+=getColor( coord+float(i)*dCoord*k );
      }
    return re/(2.0*radius+1.0);
*/
    vec2 blurSize;
    blurSize = vec2(1.0, 0.0);

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
    
    gl_FragColor = vec4( calcColor( gl_TexCoord[0].xy ).rgb, 1.0);
    }









