/*
** Camera.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 25 10:49:21 2015 Adrien Vasseur
** Last update Thu Jun 25 10:53:53 2015 Adrien Vasseur
*/

#ifndef		CAMERA_H_
# define	CAMERA_H_

# include	<iostream>

# define	GLM_FORCE_RADIANS
# include	<glm/glm.hpp>
# include	<glm/gtc/matrix_transform.hpp>
# include	<glm/gtc/type_ptr.hpp>

namespace	Display
{
  class		Camera
  {
  public:
    Camera();
    ~Camera();

    void	resize(unsigned int, unsigned int);
    glm::mat4	getMvp();

    void	moveForward(float);
    void	moveAside(float);

    void	lookHori(float);
    void	lookVerti(float);

  private:
    void	update();

    glm::mat4	m_view;
    glm::mat4	m_projection;

    glm::vec3	m_pos;
    glm::vec3	m_lookAt;
    glm::vec2	m_angleVision;
  };
};

#endif		/* !CAMERA_H_ */
