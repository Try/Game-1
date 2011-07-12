varying vec2 dcoord;

void main(void){
    gl_Position    = vec4(gl_Vertex.xy, 0.0, 1.0);
    gl_TexCoord[0] = gl_MultiTexCoord0; 
    dcoord         = gl_Normal.xy;
    }
