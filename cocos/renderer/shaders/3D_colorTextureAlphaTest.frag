const char* CC3D_colorTextureAlphaTest_frag = R"(

#ifdef GL_ES
varying mediump vec2 TextureCoordOut;
precision lowp float;
#else
varying vec2 TextureCoordOut;
#endif
uniform vec4 u_color;
uniform sampler2D u_texture;

void main(void)
{
    vec4 texColor = texture2D(u_texture, TextureCoordOut);
    
    if (texColor.a <= 0.9 )
        discard;
    
    gl_FragColor = texColor * u_color;
}
)";
