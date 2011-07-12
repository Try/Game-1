#extension GL_ARB_texture_rectangle: enable

uniform sampler2DRect uv_texture;
//uniform sampler2DRect depth;
uniform sampler2D texture;
uniform sampler2D mask;
uniform sampler2D rand;

uniform vec4    scale;

vec4 random(in vec2 uv){
    return 0.01*(texture2DLod(rand, uv.xy*scale.xy, 1.0 )*2.0-vec4(1.0));
    }

vec3 calcDiff(in vec4 base, float l){
    vec3 diff  = vec3(1.0);
    vec3 ablim = vec3(0.5, 0.5, 0.6);

    return mix(ablim, diff, l )*base.rgb;
    }

vec4 getDiff(in vec2 uv){
    return texture2D(texture, uv.xy*scale.xy );
    }

vec4 calcColor(){
    vec4 uv = texture2DRect(uv_texture, gl_TexCoord[0].xy );

    // uv.xyz*16.0;
    float m = texture2DLod(mask, uv.xy+random(uv.xy).xy, 1.0 ).r;
    return m*vec4(calcDiff( getDiff(uv.xy), uv.z), uv.a);
    }

void main (void){
    
    gl_FragColor = calcColor();
    }









