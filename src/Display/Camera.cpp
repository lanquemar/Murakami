/*
** Camera.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 25 10:55:43 2015 Adrien Vasseur
** Last update Thu Jul  2 23:35:34 2015 Adrien Vasseur
*/

#include	"Display/Camera.h"

namespace	Display
{
  Camera::Camera(Engine::Player *player) : e_player(player)
  {
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

  void		Camera::move(float up, float right)
  {
    float	x;
    float	y;

    x = - up * glm::cos(this->m_angleVision.x) + right *
      glm::sin(this->m_angleVision.x);;
    y = - up * glm::sin(this->m_angleVision.x) + right *
      glm::cos(this->m_angleVision.x + glm::pi<float>());
    this->e_player->move(x, y);
    this->update();
  }

  void		Camera::lookHori(float value)
  {
    this->m_angleVision.x += value;
    while (this->m_angleVision.x > glm::pi<float>())
      this->m_angleVision.x -= 2.0f * glm::pi<float>();
    while (this->m_angleVision.x < - glm::pi<float>())
      this->m_angleVision.x += 2.0f * glm::pi<float>();
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

  glm::mat4	Camera::getMvp()
  {
    return (this->m_projection * this->m_view);
  }

  void		Camera::update()
  {
    glm::vec3	pos;
    glm::vec3	target;

    pos = this->e_player->getPosition();
    pos.y += 0.40f;
    target.x = pos.x - glm::cos(this->m_angleVision.x);
    target.y = pos.y + glm::tan(- this->m_angleVision.y);
    target.z = pos.z + glm::sin(- this->m_angleVision.x);
    this->m_view = glm::lookAt(pos, target, glm::vec3(0.0, 1.0, 0.0));
  }
};
