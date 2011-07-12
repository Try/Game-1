uniform sampler2D texture;

varying vec2 dcoord;

vec4 calcColor( in vec2 coord ){
    vec4 re;
    re = vec4(0.0);

    for(int i=-1; i<=1; ++i)
      for(int r=-1; r<=1; ++r){
	re+=texture2D(texture, coord+dcoord*vec2(i,r) );
	}

    return re/9.0;
    }

void main (void){
    
    gl_FragColor = vec4(calcColor( gl_TexCoord[0].xy ).rgb, 1.0);
    }









