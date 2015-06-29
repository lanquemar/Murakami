varying vec2 f_texcoord;
varying vec3 f_vertex;
varying vec3 f_normal;

uniform sampler2D m_texture;

void main(void)
{
	vec3 light = vec3(0.0f, 1.8f, 0.0f);
	vec3 normal = normalize(f_normal);
	vec3 dir = normalize(light - f_vertex);
	vec2 flipped_texcoord = vec2(f_texcoord.x, 1.0 - f_texcoord.y);

	float coeff = dot(normal, dir);

	gl_FragColor = texture2D(m_texture, f_texcoord) * vec4(coeff, coeff, coeff, 1.0f);
}