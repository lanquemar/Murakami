/*
** Window.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 12:02:07 2015 Adrien Vasseur
** Last update Thu Jun 25 11:16:23 2015 Adrien Vasseur
*/

#include	"Display/Window.h"

namespace	Display
{
  Window::Window()
  {
    this->m_win = NULL;
    this->m_shader = NULL;
    this->m_camera = NULL;
    this->m_cube = NULL;
  }

  Window::~Window()
  {
    if (this->m_win)
      delete this->m_win;
    if (this->m_shader)
      delete this->m_shader;
    if (this->m_camera)
      delete this->m_camera;
    if (this->m_cube)
      delete this->m_cube;
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
    this->m_win = new sf::Window(this->m_video, this->m_name,
				 sf::Style::Default, this->m_context);
    if (!this->m_win)
      return (false);
    this->m_win->setVerticalSyncEnabled(true);

    if ((status = glewInit()) != GLEW_OK)
      {
	std::cerr << "[ERROR] GLEW init : "
		  << glewGetErrorString(status) << std::endl;
	return (false);
      }
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    this->m_shader = new Display::Shader("data/vertex.glsl", "data/fragment.glsl");
    if (!this->m_shader->init())
      return (false);
    this->m_camera = new Display::Camera;
    this->m_cube = new Display::CubeRenderer;
    if (!this->m_cube->init())
      return (false);
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
	this->m_cube->draw(this->m_shader, this->m_camera);
	this->m_win->display();
      }
  }
};
