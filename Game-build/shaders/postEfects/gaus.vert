

void main(void){
    gl_Position    = vec4(gl_Vertex.xy, 0.0, 1.0);
    gl_TexCoord[0] = gl_MultiTexCoord0; 

    //int( 10.0/gl_Normal.x+0.5 );
    }
