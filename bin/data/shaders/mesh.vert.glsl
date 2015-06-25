attribute vec3 m_vertex;
attribute vec2 m_texcoord;

varying vec2 f_texcoord;

uniform mat4 m_mvp;

void main(void)
{
	gl_Position = m_mvp * vec4(m_vertex, 1.0);
	f_texcoord = m_texcoord;
}