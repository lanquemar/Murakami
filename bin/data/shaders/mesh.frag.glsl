varying vec2 f_texcoord;

uniform sampler2D m_texture;

void main(void)
{
	vec2 flipped_texcoord = vec2(f_texcoord.x, 1.0 - f_texcoord.y);
	gl_FragColor = texture2D(m_texture, flipped_texcoord);
}