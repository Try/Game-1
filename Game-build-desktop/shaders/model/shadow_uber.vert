
varying vec3 tpos;

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

vec4 transform(){    
    vec4 vertex = gl_Vertex;
    initBase();

    up   *= gl_Normal.x;
    left *= gl_Normal.y;

    vertex.xyz += up;
    vertex.xyz += left;
    vertex.xyz -= vec3( gl_ModelViewMatrix[0][2],
                        gl_ModelViewMatrix[1][2],
                        gl_ModelViewMatrix[2][2])*
                        gl_Normal.x * gl_Normal.y;

    
    return gl_ModelViewProjectionMatrix * vertex;
    }

#else

vec4 transform(){ 
  return gl_ModelViewProjectionMatrix*gl_Vertex;
  }
#endif

void main(void){
    //vec4 fpos = m*gl_Vertex;
    //vec4 fpos = gl_ModelViewMatrix*gl_ProjectionMatrix*gl_Vertex;
    vec4 fpos = transform();//gl_ModelViewProjectionMatrix*gl_Vertex;
    fpos/=fpos.w;

    tpos           = vec3(fpos);
    gl_TexCoord[0] = gl_MultiTexCoord0; 
    gl_Position    = fpos;
    //pos.z *= 0.01;
    }
