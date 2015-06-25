/*
** Window.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 11:57:38 2015 Adrien Vasseur
** Last update Thu Jun 25 11:11:59 2015 Adrien Vasseur
*/

#ifndef			WINDOW_H_
# define		WINDOW_H_

# include		<iostream>
# include		<string>
# include		<GL/glew.h>

# include		<SFML/Window.hpp>
# include		<SFML/OpenGL.hpp>

# include		"Display/Shader.h"
# include		"Display/Camera.h"
# include		"Display/Renderer/CubeRenderer.h"

namespace		Display
{
  class			Window
  {
  public:
    Window();
    ~Window();

    bool		create();
    void		run();

  private:
    void		initContext();

    sf::Window		*m_win;
    sf::ContextSettings	m_context;
    sf::VideoMode	m_video;
    std::string		m_name;

    Display::Shader	*m_shader;
    Display::Camera	*m_camera;
    Display::CubeRenderer	*m_cube;
  };
};

#endif			/* !WINDOW_H_ */
