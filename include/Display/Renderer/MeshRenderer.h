/*
** MeshRenderer.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 25 22:34:51 2015 Adrien Vasseur
** Last update Thu Jul  2 23:30:08 2015 Adrien Vasseur
*/

#ifndef			MESHRENDERER_H_
# define		MESHRENDERER_H_

# include		<GL/glew.h>

# include		<SFML/Graphics/Texture.hpp>

# define		GLM_FORCE_RADIANS
# include		<glm/glm.hpp>
# include		<glm/gtc/matrix_transform.hpp>
# include		<glm/gtc/type_ptr.hpp>

# include		"Engine/ObjImporter.h"

# include		"Display/Shader.h"
# include		"Display/Camera.h"

namespace		Display
{
  class			MeshRenderer
  {
  public:
    MeshRenderer(Engine::ObjImporter *);
    ~MeshRenderer();

    bool		init();
    void		draw(Display::Shader *, Display::Camera *);

    void		setPosition(glm::vec3);
    void		setSize(glm::vec3);

  private:
    Engine::ObjImporter	*e_mesh;

    GLuint		m_vbo_vertex;
    GLuint		m_vbo_texcoord;
    GLuint		m_vbo_normal;

    glm::vec3		m_pos;
    glm::vec3		m_scale;
  };
};

#endif		/* !MESHRENDERER_H_ */
