
void main(void){
    gl_Position    = vec4(gl_Vertex.xy*2.0+vec2(1.0), 0.0, 1.0);
    gl_TexCoord[0] = gl_MultiTexCoord0*2.0; 
    }
