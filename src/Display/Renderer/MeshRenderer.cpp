/*
** MeshRenderer.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 25 22:44:57 2015 Adrien Vasseur
** Last update Thu Jul  2 23:31:00 2015 Adrien Vasseur
*/

#include	"Display/Renderer/MeshRenderer.h"

namespace	Display
{
  MeshRenderer::MeshRenderer(Engine::ObjImporter *mesh) : e_mesh(mesh)
  {
    this->m_pos = glm::vec3(0.0, 0.0, 0.0);
    this->m_scale = glm::vec3(1.0, 1.0, 1.0);
    this->m_vbo_vertex = 0;
    this->m_vbo_texcoord = 0;
    this->m_vbo_normal = 0;
  }

  MeshRenderer::~MeshRenderer()
  {
    glDeleteBuffers(1, &(this->m_vbo_vertex));
    glDeleteBuffers(1, &(this->m_vbo_texcoord));
    glDeleteBuffers(1, &(this->m_vbo_normal));
  }

  bool		MeshRenderer::init()
  {
    glGenBuffers(1, &(this->m_vbo_vertex));
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_vertex);
    glBufferData(GL_ARRAY_BUFFER, this->e_mesh->f_vertex.size() * sizeof(GLfloat), this->e_mesh->f_vertex.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &(this->m_vbo_texcoord));
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_texcoord);
    glBufferData(GL_ARRAY_BUFFER, this->e_mesh->f_texcoord.size() * sizeof(GLfloat), this->e_mesh->f_texcoord.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &(this->m_vbo_normal));
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_normal);
    glBufferData(GL_ARRAY_BUFFER, this->e_mesh->f_normal.size() * sizeof(GLfloat), this->e_mesh->f_normal.data(), GL_STATIC_DRAW);

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
    sf::Texture::bind(this->e_mesh->m_texture);
    glUniform1i(shader->m_uni_texture, 0);

    glEnableVertexAttribArray(shader->m_attr_vertex);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_vertex);
    glVertexAttribPointer(shader->m_attr_vertex, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glEnableVertexAttribArray(shader->m_attr_texcoord);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_texcoord);
    glVertexAttribPointer(shader->m_attr_texcoord, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glEnableVertexAttribArray(shader->m_attr_normal);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo_normal);
    glVertexAttribPointer(shader->m_attr_normal, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, this->e_mesh->f_vertex.size() / 3);

    sf::Texture::bind(NULL);
    glDisableVertexAttribArray(shader->m_attr_normal);
    glDisableVertexAttribArray(shader->m_attr_texcoord);
    glDisableVertexAttribArray(shader->m_attr_vertex);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
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
