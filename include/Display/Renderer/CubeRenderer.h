/*
** CubeRenderer.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 25 09:55:09 2015 Adrien Vasseur
** Last update Thu Jun 25 10:40:14 2015 Adrien Vasseur
*/

#ifndef		CUBERENDERER_H_
# define	CUBERENDERER_H_

# include	<GL/glew.h>

# define	GLM_FORCE_RADIANS
# include	<glm/glm.hpp>
# include	<glm/gtc/matrix_transform.hpp>
# include	<glm/gtc/type_ptr.hpp>

# include	"Display/Shader.h"

namespace	Display
{
  class		CubeRenderer
  {
  public:
    CubeRenderer();
    ~CubeRenderer();

    bool	init();
    void	draw(Display::Shader *);
    void	setPosition(glm::vec3);
    void	setSize(glm::vec3);

  private:
    GLuint	m_vbo_vertex;
    GLuint	m_vbo_colors;
    GLuint	m_ibo_index;

    glm::vec3	m_pos;
    glm::vec3	m_scale;
  };
};

#endif		/* !CUBERENDERER_H_ */
