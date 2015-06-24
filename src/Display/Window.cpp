/*
** Window.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 12:02:07 2015 Adrien Vasseur
** Last update Wed Jun 24 15:00:24 2015 Adrien Vasseur
*/

#include	"Display/Window.h"

namespace	Display
{
  Window::Window()
  {
    this->m_win = NULL;
  }

  Window::~Window()
  {
    if (this->m_win)
      delete this->m_win;
  }

  void		Window::initContext()
  {
    m_context.depthBits = 24;
    m_context.stencilBits = 8;
    m_context.antialiasingLevel = 4;
    m_context.majorVersion = 3;
    m_context.minorVersion = 0;
    m_video.width = 1024;
    m_video.height = 768;
    m_video.bitsPerPixel = 32;
    m_name = "Murakami";
  }

  bool		Window::create()
  {
    GLenum	status;

    initContext();
    this->m_win = new sf::Window(this->m_video, this->m_name, sf::Style::Default, this->m_context);
    if (!this->m_win)
      return (false);
    this->m_win->setVerticalSyncEnabled(true);

    if ((status = glewInit()) != GLEW_OK)
      {
	std::cerr << "[ERROR] GLEW init : " << glewGetErrorString(status) << std::endl;
	return (false);
      }
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    return (true);
  }

  void		Window::run()
  {
    sf::Event	event;
    bool	running;

    running = true;
    while (running)
      {
	while (this->m_win->pollEvent(event))
	  {
	    if (event.type == sf::Event::Closed)
	      running = false;
	    else if (event.type == sf::Event::Resized)
	      glViewport(0, 0, event.size.width, event.size.height);
	  }
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	this->m_win->display();
      }
  }
};
