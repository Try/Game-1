varying vec3 ldir;
varying vec3 normal, frag_pos, shCoord, tpos;

uniform mat4  lMatrix;
uniform vec4  lDirection;

void main(void){
    gl_Position    = ftransform();
    gl_TexCoord[0] = gl_MultiTexCoord0; 

    normal         = normalize( gl_NormalMatrix*gl_Normal );

    vec4 mshCoord  = lMatrix*gl_Vertex;
    shCoord        = mshCoord.xyz/mshCoord.w;

    tpos           = shCoord.xyz;

    shCoord = shCoord*0.5+vec3(0.5, 0.5, 0.0);

    ldir = lDirection.xyz;
    }
