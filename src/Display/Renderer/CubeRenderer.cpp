/*
** CubeRenderer.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 25 09:54:03 2015 Adrien Vasseur
** Last update Thu Jun 25 15:43:36 2015 Adrien Vasseur
*/

#include	"Display/Renderer/CubeRenderer.h"

namespace	Display
{
  CubeRenderer::CubeRenderer()
  {
    this->m_pos = glm::vec3(0.0, 0.0, 0.0);
    this->m_scale = glm::vec3(0.5, 0.5, 0.5);
    this->m_vbo_vertex = 0;
    this->m_vbo_colors = 0;
    this->m_ibo_index = 0;
  }

  CubeRenderer::~CubeRenderer()
  {
    glDeleteBuffers(1, &(this->m_vbo_vertex));
    glDeleteBuffers(1, &(this->m_vbo_colors));
    glDeleteBuffers(1, &(this->m_ibo_index));
  }

  bool		CubeRenderer::init()
  {
    GLfloat	vertex[] = {
      -1.0, -1.0, 1.0,
      1.0, -1.0, 1.0,
      1.0, 1.0, 1.0,
      -1.0, 1.0, 1.0,
      -1.0, -1.0, -1.0,
      1.0, -1.0, -1.0,
      1.0, 1.0, -1.0,
      -1.0, 1.0, -1.0,
    };
    GLfloat	colors[] = {
      1.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
    };
    GLushort	index[] = {
      0, 1, 2,
      2, 3, 0,
      1, 5, 6,
      6, 2, 1,
      7, 6, 5,
      5, 4, 7,
      4, 0, 3,
      3, 7, 4,
      4, 5, 1,
      1, 0, 4,
      3, 2, 6,
      6, 7, 3,
    };

    glGenBuffers(1, &(this->m_vbo_vertex));
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_vertex);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    glGenBuffers(1, &(this->m_vbo_colors));
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_colors);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    glGenBuffers(1, &(this->m_ibo_index));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ibo_index);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
    return (true);
  }

  void		CubeRenderer::draw(Display::Shader *shader, Display::Camera *camera)
  {
    glm::mat4	model;
    glm::mat4	mvp;
    int		size;

    model = glm::scale(glm::translate(glm::mat4(1.0f), this->m_pos), this->m_scale);
    mvp = camera->getMvp() * model;

    glUseProgram(shader->getProgramId());
    glUniformMatrix4fv(shader->m_uni_mvp, 1, GL_FALSE, glm::value_ptr(mvp));

    glEnableVertexAttribArray(shader->m_attr_vertex);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_vertex);
    glVertexAttribPointer(shader->m_attr_vertex, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glEnableVertexAttribArray(shader->m_attr_colors);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_colors);
    glVertexAttribPointer(shader->m_attr_colors, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ibo_index);
    glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    glDrawElements(GL_TRIANGLES, size / sizeof(GLushort), GL_UNSIGNED_SHORT, 0);

    glDisableVertexAttribArray(shader->m_attr_colors);
    glDisableVertexAttribArray(shader->m_attr_vertex);
    glUseProgram(0);
  }

  void		CubeRenderer::setPosition(glm::vec3 pos)
  {
    this->m_pos = pos;
  }

  void		CubeRenderer::setSize(glm::vec3 size)
  {
    this->m_scale = size;
  }
};
