void main(void){
    gl_Position    = vec4(gl_Vertex.xy*0.25-vec2(0.5), 0.0, 1.0);
    gl_TexCoord[0] = gl_MultiTexCoord0; 
    }
