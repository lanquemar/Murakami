/*
** Window.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 11:57:38 2015 Adrien Vasseur
** Last update Mon Jun 29 23:37:29 2015 Adrien Vasseur
*/

#ifndef				WINDOW_H_
# define			WINDOW_H_

# include			<iostream>
# include			<string>
# include			<GL/glew.h>

# include			<SFML/Graphics.hpp>
# include			<SFML/OpenGL.hpp>

# include			"Display/Shader.h"
# include			"Display/Camera.h"
# include			"Display/Gui.h"
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

    sf::RenderWindow		*m_win;
    sf::ContextSettings		m_context;
    sf::VideoMode		m_video;
    std::string			m_name;

    Display::Shader		*m_shader;
    Display::Camera		*m_camera;
    Display::Gui		*m_gui;
    Display::MapRenderer	*m_map;
  };
};

#endif				/* !WINDOW_H_ */
