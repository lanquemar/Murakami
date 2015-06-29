attribute vec3 m_vertex;
attribute vec2 m_texcoord;
attribute vec3 m_normal;

varying vec2 f_texcoord;
varying vec3 f_vertex;
varying vec3 f_normal;

uniform mat4 m_mvp;

void main(void)
{
	gl_Position = m_mvp * vec4(m_vertex, 1.0);
	f_texcoord = m_texcoord;
	f_vertex = m_vertex;
	f_normal = m_normal;
}