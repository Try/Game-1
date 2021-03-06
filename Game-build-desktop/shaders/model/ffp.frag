uniform sampler2D diffuse_texture;
uniform sampler2D specular_texture;
uniform sampler2D shadow_map_texture;
uniform sampler2D normal_map_texture;


varying vec3 ldir;

varying vec3 normal,  frag_pos, shCoord, tpos;

#ifdef NORMAL
varying vec3 tnormal, bnormal;
#endif

#ifdef SPECULAR
varying vec3 eyePos;
#endif

#ifdef PARALLAX
varying vec3 viewDir;
#endif

vec2 textureCoord;

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
#ifdef LAMBERT
    float ddot = max(dot(normal, ldir ), 0.0);

    #ifndef NO_SHADOWS
    vec4 vsm = getSm( shCoord.xy );
    float difference = ( distance()-vsm.r );
    float k = clamp( difference/vsm.r/vsm.r*10.0, 0.0,  1.0);
    #else 
    float difference = 1.0;
    float k          = 0.0;
    #endif
  
    #ifndef SCERTING
    return min(ddot, 1.0-k );
    #else
    
    float r = min(ddot, 1.0-k )+ pow(max(1.0-difference, 0.0), 12.0);
    return clamp(r, 0.0, 1.0);
    #endif
#else
    return 1.0;
#endif
    }

#ifdef SPECULAR
vec3 calcSpecular( in vec3 n, float l ){
    vec4 specPower = texture2D( specular_texture, 
                                textureCoord);
    vec4  specColor = vec4(0.1);

    vec3 r    = reflect ( eyePos, n );    
    vec4 spec = specColor * pow ( max( dot (ldir, r), 0.0), specPower.r*127.0+0.0001 )*specPower.a;

    return sign(l)*spec.rgb;
    }
#endif

vec3 calcDiff(in vec4 base, float l){
    vec3 diff  = vec3(0.75);
    vec3 ablim = vec3(0.4, 0.4, 0.4);

    return (l*diff + ablim)*base.rgb;//mix(ablim, diff, l )*base.rgb;
    }

vec3 clacNormal(){
#ifdef NORMAL
    vec3 nmap = (texture2D(normal_map_texture, textureCoord).rgb)*2.0-vec3(1.0);
    
    return normalize( nmap.r*tnormal + nmap.g*bnormal + nmap.b*normal);
#else
    return normalize(normal);
#endif
    }

#ifdef PARALLAX

#define numsteps 7
#define scale    0.1
void parallax(){
    vec2 TexCoords; 
    vec3 V = normalize(viewDir); 
	
    float height; 
    float Bias = -0.03 / numsteps; 
    float Scale = scale / numsteps; 
      
    TexCoords = textureCoord; 
      
    for(int i = 0; i < numsteps; i++){ 
      height = 1.0 - texture2D(normal_map_texture, TexCoords).a;      
      height = height * Scale + Bias; 
      TexCoords = TexCoords + (height * V.xy); 

      }

    textureCoord = TexCoords;
    }
#endif


vec4 calcColor(){
    textureCoord = gl_TexCoord[0].xy;

    #ifdef PARALLAX
    parallax();
    #endif

#ifdef VIRTUAL
    vec2 vOut = textureCoord.xy;
    textureCoord.xy*=128.0;
#endif
    vec4 base  = getColor( textureCoord );

    //return vec4( vec3( distance() ), base.a );
    //return vec4( vec3( shCoord.xy, 0.0 ), base.a );
    //return vec4( vec3( getSm( shCoord.xy ).r ), base.a );
    //return vec4( vec3( abs(getSm9x(shCoord.xy).r - distance() ) ), base.a );

    vec3  n = clacNormal();
    float l = calcLambert(n);

#ifdef NORMAL

#endif
    //return vec4(n, 1.0);

#ifdef VIRTUAL
    return vec4( vec3( vOut, l ), base.a );
#endif

#ifdef LIGHT_DEBUG
    return vec4( vec3( l ), base.a );
#endif

    //vec3 color = calcSpecular(n);
    vec3 color = calcDiff(base, l) 
#ifdef SPECULAR
               + calcSpecular(n,l)
#endif
               ;
    return vec4( color, base.a );
    }

void main (void){
    
    gl_FragColor = calcColor();
    }









