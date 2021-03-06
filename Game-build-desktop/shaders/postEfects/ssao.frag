#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect mainPass;
uniform sampler2DRect depthBuffer;
uniform sampler2DRect rand4x4;

#define eps 0.0001

float z;

vec2 random( in vec2 coord ){
    return texture2DRect(rand4x4, coord).rg; 
    }

vec2 randomVec;

float getDepth( in vec2 coord ){
    return texture2DRect(depthBuffer, coord).r; 
    }

vec4 getColor( in vec2 coord ){
    return texture2DRect(mainPass, coord); 
    }

float calcAO(in vec2 coord, float x, float y){
    vec2 ray = reflect(randomVec, vec2(x, y) );

    float a = z - getDepth( coord+vec2( x,y) );

    if( a > eps )
      return 1.0; else
      return 0.0;
    }

float loop4F(in vec2 coord, float i){
    float sao = 0.0;

    sao += calcAO(coord,   i, 0.0);
    sao += calcAO(coord,  -i, 0.0);

    sao += calcAO(coord, 0.0,   i);
    sao += calcAO(coord, 0.0,  -i);

    return sao;
    }

float loopF(in vec2 coord, float i){
    float sao = 0.0;
    float j = 1.414213*i;

    sao += calcAO(coord,   i, 0.0);
    sao += calcAO(coord,  -i, 0.0);

    sao += calcAO(coord, 0.0,   i);
    sao += calcAO(coord, 0.0,  -i);

    sao += calcAO(coord,   j,   j);
    sao += calcAO(coord,  -j,   j);

    sao += calcAO(coord,   j,  -j);
    sao += calcAO(coord,  -j,  -j);

    return sao;
    }

float loop(in vec2 coord, int i){
    return loopF(coord, float(i));
    }

float loop4(in vec2 coord, int i){
    return loop4F(coord, float(i));
    }

vec3 calcColor(in vec2 coord){
    float ao = 0.0;
    z = getDepth( coord );
    randomVec = random( coord );

    const int rPeek = 64;
  /*
    ao  += loop(coord, 0);
    ao  += loop(coord, 1);
    ao  += loop(coord, 2);
*/
    ao  += loop(coord, 3);
  
    ao  += loop(coord, 4);

    ao  += loop4(coord, 5);
    //ao  += loop4(coord, 6);
    //ao  += loop4(coord, 7);

    ao  += loop4(coord, 8);
    ao  += loop4(coord, 16);
    //ao  += loop4(coord, 20);
    //ao  += loop4(coord, 64);

    float chanel = 1.0 - ao/float(rPeek);
    return vec3( chanel );
   // return vec3( (chanel-0.75)*4.0 );
    }

void main (void){
    gl_FragColor = vec4( calcColor( gl_TexCoord[0].xy ), 1.0);
    }









