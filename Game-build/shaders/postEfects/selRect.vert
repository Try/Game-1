uniform vec4 rect; 

void main(void){
    vec2 coord = gl_Vertex.xy*0.25+vec2(0.5);
    vec4 r = rect;//*2.0-vec2(1.0);

    coord*= r.zw;
    coord+= r.xy;
  
    gl_Position    = vec4( coord*2.0-vec2(1.0), 0.0, 1.0);
    }
