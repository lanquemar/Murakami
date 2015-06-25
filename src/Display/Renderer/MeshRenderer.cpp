/*
** MeshRenderer.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 25 22:44:57 2015 Adrien Vasseur
** Last update Fri Jun 26 00:04:59 2015 Adrien Vasseur
*/

#include	"Display/Renderer/MeshRenderer.h"

namespace	Display
{
  MeshRenderer::MeshRenderer()
  {
    this->m_pos = glm::vec3(0.0, 0.0, 0.0);
    this->m_scale = glm::vec3(1.0, 1.0, 1.0);
    this->m_vbo_vertex = 0;
    this->m_vbo_texcoord = 0;
    this->m_ibo_index = 0;
    this->m_texture = NULL;
  }

  MeshRenderer::~MeshRenderer()
  {
    glDeleteBuffers(1, &(this->m_vbo_vertex));
    glDeleteBuffers(1, &(this->m_vbo_texcoord));
    glDeleteBuffers(1, &(this->m_ibo_index));
  }

  bool		MeshRenderer::init()
  {
    GLfloat     vertex[] = {
      -1.0, -1.0, 1.0,
      1.0, -1.0, 1.0,
      1.0, 1.0, 1.0,
      -1.0, 1.0, 1.0,
      -1.0, 1.0, 1.0,
      1.0, 1.0, 1.0,
      1.0, 1.0, -1.0,
      -1.0, 1.0, -1.0,
      1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0,
      -1.0, 1.0, -1.0,
      1.0, 1.0, -1.0,
      -1.0, -1.0, -1.0,
      1.0, -1.0, -1.0,
      1.0, -1.0, 1.0,
      -1.0, -1.0, 1.0,
      -1.0, -1.0, -1.0,
      -1.0, -1.0, 1.0,
      -1.0, 1.0, 1.0,
      -1.0, 1.0, -1.0,
      1.0, -1.0, 1.0,
      1.0, -1.0, -1.0,
      1.0, 1.0, -1.0,
      1.0, 1.0, 1.0,
    };
    GLfloat     texcoord[] = {
      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,
      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,
      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,
      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,
      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,
      0.0, 0.0,
      1.0, 0.0,
      1.0, 1.0,
      0.0, 1.0,
    };
    GLushort    index[] = {
      0, 1, 2,
      2, 3, 0,
      4, 5, 6,
      6, 7, 4,
      8, 9, 10,
      10, 11, 8,
      12, 13, 14,
      14, 15, 12,
      16, 17, 18,
      18, 19, 16,
      20, 21, 22,
      22, 23, 20,
    };

    this->m_texture = new sf::Texture;
    if (!this->m_texture->loadFromFile("data/textures/cube.bmp"))
      return (false);

    glGenBuffers(1, &(this->m_vbo_vertex));
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_vertex);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    glGenBuffers(1, &(this->m_vbo_texcoord));
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_texcoord);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texcoord), texcoord, GL_STATIC_DRAW);

    glGenBuffers(1, &(this->m_ibo_index));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ibo_index);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
    return (true);
  }

  void		MeshRenderer::draw(Display::Shader *shader, Display::Camera *camera)
  {
    glm::mat4	model;
    glm::mat4	mvp;
    int		size;

    model = glm::scale(glm::translate(glm::mat4(1.0f), this->m_pos), this->m_scale);
    mvp = camera->getMvp() * model;

    glUseProgram(shader->getProgramId());
    glUniformMatrix4fv(shader->m_uni_mvp, 1, GL_FALSE, glm::value_ptr(mvp));

    glActiveTexture(GL_TEXTURE0);
    sf::Texture::bind(this->m_texture);
    glUniform1i(shader->m_uni_texture, 0);

    glEnableVertexAttribArray(shader->m_attr_vertex);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_vertex);
    glVertexAttribPointer(shader->m_attr_vertex, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glEnableVertexAttribArray(shader->m_attr_texcoord);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_texcoord);
    glVertexAttribPointer(shader->m_attr_texcoord, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ibo_index);
    glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    glDrawElements(GL_TRIANGLES, size / sizeof(GLushort), GL_UNSIGNED_SHORT, 0);

    sf::Texture::bind(NULL);
    glDisableVertexAttribArray(shader->m_attr_texcoord);
    glDisableVertexAttribArray(shader->m_attr_vertex);
    glUseProgram(0);
  }

  void		MeshRenderer::setPosition(glm::vec3 pos)
  {
    this->m_pos = pos;
  }

  void		MeshRenderer::setSize(glm::vec3 size)
  {
    this->m_scale = size;
  }
};
