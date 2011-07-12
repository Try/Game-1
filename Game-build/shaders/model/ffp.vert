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

uniform mat4  lMatrix;
uniform vec4  lDirection;

#ifdef PARTICLE
vec3 up, left;

void initBase(){
    up   = vec3(gl_ModelViewMatrix[0][1],
                gl_ModelViewMatrix[1][1],
                gl_ModelViewMatrix[2][1]);
                
    left = vec3(gl_ModelViewMatrix[0][0],
                gl_ModelViewMatrix[1][0],
                gl_ModelViewMatrix[2][0]);
  
    up   = normalize(up);
    left = normalize(left);
    }

void transform(){    
    vec4 vertex = gl_Vertex;
    initBase();
    vertex.xyz += up   * gl_Normal.x;
    vertex.xyz += left * gl_Normal.y;

    gl_Position = gl_ModelViewProjectionMatrix * vertex;
    gl_TexCoord[0] = gl_MultiTexCoord0; 
    
    vec3 n = vec3(gl_ModelViewMatrix[0][2],
                  gl_ModelViewMatrix[1][2],
                  gl_ModelViewMatrix[2][2]);
    n = normalize(n);
    vec3 d = normalize((vertex-gl_Vertex).xyz);
    // normal         = normalize( vec3( 0.0, 0.0, 1.0) );
    normal         = normalize( gl_NormalMatrix*(d+n*0.25) );
    
    //normal.z = sqrt( 1.0-length(normal.xy) );
    }

#else

void transform(){
    gl_Position    = ftransform();
    gl_TexCoord[0] = gl_MultiTexCoord0; 
    normal         = normalize( gl_NormalMatrix*gl_Normal );
    }
#endif

void calcShadowCoord(){
    vec4 mshCoord  = lMatrix*gl_Vertex;
    shCoord        = mshCoord.xyz/mshCoord.w;

    tpos           = shCoord.xyz;

    shCoord = shCoord*0.5+vec3(0.5, 0.5, 0.0);
    }

void main(void){
    transform();

#ifdef NORMAL
    tnormal        = normalize( gl_NormalMatrix*gl_Color.rgb );
    bnormal        = ( cross( normal, tnormal) );
#endif
    calcShadowCoord();

#ifdef SPECULAR
    eyePos = normalize(gl_NormalMatrix*vec3(0,0, -1));//normalize(vec3( gl_ModelViewMatrix[0][2],
                             //gl_ModelViewMatrix[1][2],
                             //gl_ModelViewMatrix[2][2]));
#endif

#ifdef PARALLAX
    vec3 vDir;
    vDir    = -normalize(vec3( gl_ModelViewMatrix[0][2],
                               gl_ModelViewMatrix[1][2],
                               gl_ModelViewMatrix[2][2]));
    #ifdef NORMAL
    
    vec3 bN = cross(gl_Normal, gl_Color.rgb);
    viewDir = vec3(  dot( gl_Color.rgb, vDir),
                     dot( bN, vDir),
                     dot( gl_Normal, vDir) );
    //viewDir = vDir;
    #endif
#endif

    ldir = lDirection.xyz;
    }
