/*
** Camera.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 25 10:49:21 2015 Adrien Vasseur
** Last update Thu Jul  2 23:21:50 2015 Adrien Vasseur
*/

#ifndef			CAMERA_H_
# define		CAMERA_H_

# include		<iostream>

# define		GLM_FORCE_RADIANS
# include		<glm/glm.hpp>
# include		<glm/gtc/matrix_transform.hpp>
# include		<glm/gtc/type_ptr.hpp>

# include		"Engine/Player.h"

namespace		Display
{
  class			Camera
  {
  public:
    Camera(Engine::Player *);
    ~Camera();

    void		resize(unsigned int, unsigned int);
    void		move(float, float);

    void		lookHori(float);
    void		lookVerti(float);

    glm::mat4		getMvp();

  private:
    void		update();

    Engine::Player	*e_player;

    glm::mat4		m_view;
    glm::mat4		m_projection;

    glm::vec3		m_lookAt;
    glm::vec2		m_angleVision;
  };
};

#endif			/* !CAMERA_H_ */
