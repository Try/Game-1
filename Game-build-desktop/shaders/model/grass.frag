uniform sampler2D diffuse_texture;
uniform sampler2D shadow_map_texture;


varying vec3 ldir;
varying vec3 normal, frag_pos, shCoord, tpos;

vec4 getColor( in vec2 coord ){
    return texture2D(diffuse_texture, coord);
    }

vec4 getSm( in vec2 coord ){
    return texture2D(shadow_map_texture, coord);
    }

float distance(){
    return min((tpos.z-gl_DepthRange.near)/gl_DepthRange.diff, 1.0);
    }

float calcLambert( in vec3 normal ){
    vec4 vsm = getSm( shCoord.xy );

    float ddot = 1.0;
    ddot = max( ddot, 0.0);
    //ddot = max( mix( ddot, -ddot, gl_FrontFacing ), 0.0);
    
    const float bias = 0.0001;
    return mix(ddot, 0.0, float(distance()-vsm.r > bias) );
    }

vec3 calcSpecular( in vec3 n, float l ){
    return vec3(0.0);
    }

vec3 calcDiff(in vec4 base, float l){
    vec3 diff  = vec3(1.0);
    vec3 ablim = vec3(0.5, 0.5, 0.6);

    return mix(ablim, diff, l )*base.rgb;
    }

vec3 clacNormal(){    
    return normal;
    }

vec4 calcColor(){
    vec4 base  = getColor( gl_TexCoord[0].xy );

    //return vec4( vec3( distance() ), base.a );
    //return vec4( vec3( shCoord.xy, 0.0 ), base.a );
    //return vec4( vec3( getSm9x( shCoord.xy ).r ), base.a );
    //return vec4( vec3( abs(getSm9x(shCoord.xy).r - distance() ) ), base.a );

    vec3  n = clacNormal();
    float l = calcLambert(n);
//     return vec4( vec3( calcLambert( n ) ), base.a );

    //vec3 color = calcSpecular(n);
    vec3 color = calcDiff(base, l) + calcSpecular(n,l);
    return vec4( color, base.a );
    }

void main (void){
    
    gl_FragColor = calcColor();
    }









