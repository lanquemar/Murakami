/*
** Window.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 11:57:38 2015 Adrien Vasseur
** Last update Sun Jun 28 22:25:26 2015 Adrien Vasseur
*/

#ifndef				WINDOW_H_
# define			WINDOW_H_

# include			<iostream>
# include			<string>
# include			<GL/glew.h>

# include			<SFML/Window.hpp>
# include			<SFML/OpenGL.hpp>

# include			"Display/Shader.h"
# include			"Display/Camera.h"
# include			"Display/Renderer/MapRenderer.h"

namespace			Display
{
  class				Window
  {
  public:
    Window();
    ~Window();

    bool			create();
    void			run();

  private:
    void			initContext();
    void			movement(sf::Event &);

    sf::Window			*m_win;
    sf::ContextSettings		m_context;
    sf::VideoMode		m_video;
    std::string			m_name;

    Display::Shader		*m_shader;
    Display::Camera		*m_camera;
    Display::MapRenderer	*m_map;
  };
};

#endif				/* !WINDOW_H_ */
