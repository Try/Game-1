#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect uv_texture;
//uniform sampler2DRect depth;
uniform sampler2D texture;
uniform sampler2DRect mask;
uniform sampler2D rand;

uniform vec4    scale;

vec2 random(in vec2 uv){
    vec4 d = (texture2DLod(rand, uv.xy*scale.xy*6.0, 1.0 )*2.0-vec4(1.0));

    //float l = 1.9*length(d.xy);
    return 0.01*d.xy;//0.005*d.xy*pow(l,10.0)/(l+0.001);
    }

vec3 calcDiff(in vec4 base, float l){
    vec3 diff  = vec3(1.0);
    vec3 ablim = vec3(0.5, 0.5, 0.6);

    return mix(ablim, diff, l )*base.rgb;
    }

vec4 getDiff(in vec2 uv){
    return texture2D(texture, uv.xy*scale.xy );
    }

 vec2 tail;

float calcMask( in vec2 dcoord ){
    return texture2DRect(mask, 0.5*dcoord + (tail+random(tail))*scale.zw ).r;
    }

vec4 calcColor(){
    vec4 uv = texture2DRect(uv_texture, gl_TexCoord[0].xy );

    tail = uv.xy;

    float m = calcMask( vec2(0.0, 0.0) )+
              calcMask( vec2(1.0, 0.0) )+
	      calcMask( vec2(1.0, 1.0) )+
	      calcMask( vec2(0.0, 1.0) );
    m*=0.25;
    //m = min(m+pow( max(m-0.25, 0.001), 2.0), 1.0);
    return m*vec4(calcDiff( getDiff(uv.xy), uv.z), uv.a);
    }

void main (void){
    
    gl_FragColor = calcColor();
    }









