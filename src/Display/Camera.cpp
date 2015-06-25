/*
** Camera.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 25 10:55:43 2015 Adrien Vasseur
** Last update Thu Jun 25 15:53:19 2015 Adrien Vasseur
*/

#include	"Display/Camera.h"

namespace	Display
{
  Camera::Camera()
  {
    this->m_pos = glm::vec3(0.0, 2.0, 0.0);
    this->m_angleVision = glm::vec2(0.0, 0.0);
    this->update();
  }

  Camera::~Camera()
  {
  }

  void		Camera::resize(unsigned int width, unsigned int height)
  {
    this->m_projection = glm::perspective(45.0f, 1.0f * width / height,
					  0.1f, 100000.0f);
  }

  glm::mat4	Camera::getMvp()
  {
    return (this->m_projection * this->m_view);
  }

  void		Camera::moveForward(float value)
  {
    this->m_pos.z -= value * glm::sin(this->m_angleVision.x);
    this->m_pos.x -= value * glm::cos(this->m_angleVision.x);
    this->update();
  }

  void		Camera::moveAside(float value)
  {
    this->m_pos.z += value * glm::cos(this->m_angleVision.x + glm::pi<float>());
    this->m_pos.x += value * glm::sin(this->m_angleVision.x);
    this->update();
  }

  void		Camera::lookHori(float value)
  {
    this->m_angleVision.x += value;
    this->update();
  }

  void		Camera::lookVerti(float value)
  {
    this->m_angleVision.y += value;
    if (this->m_angleVision.y >= glm::pi<float>() / 2.0f - 0.01f)
      this->m_angleVision.y = glm::pi<float>() / 2.0f - 0.01f;
    if (this->m_angleVision.y <= - (glm::pi<float>() / 2.0f) + 0.01f)
      this->m_angleVision.y = - (glm::pi<float>() / 2.0f) + 0.01f;
    this->update();
  }

  void		Camera::update()
  {
    glm::vec3	pos;
    glm::vec3	target;

    pos.x = this->m_pos.x + glm::cos(this->m_angleVision.x);
    pos.y = this->m_pos.y;
    pos.z = this->m_pos.z + glm::sin(this->m_angleVision.x);
    target.x = this->m_pos.x - glm::cos(this->m_angleVision.x);
    target.y = this->m_pos.y + glm::tan(- this->m_angleVision.y);
    target.z = this->m_pos.z + glm::sin(- this->m_angleVision.x);
    this->m_view = glm::lookAt(pos, target, glm::vec3(0.0, 1.0, 0.0));
  }
};
