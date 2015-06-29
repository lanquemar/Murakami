/*
** Window.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 12:02:07 2015 Adrien Vasseur
** Last update Mon Jun 29 22:45:00 2015 Adrien Vasseur
*/

#include	"Display/Window.h"

namespace	Display
{
  Window::Window()
  {
    this->m_win = NULL;
    this->m_shader = NULL;
    this->m_camera = NULL;
    this->m_map = NULL;
  }

  Window::~Window()
  {
    if (this->m_win)
      delete this->m_win;
    if (this->m_shader)
      delete this->m_shader;
    if (this->m_camera)
      delete this->m_camera;
    if (this->m_map)
      delete this->m_map;
  }

  bool		Window::create()
  {
    GLenum	status;

    this->initContext();
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
    this->m_shader = new Display::Shader("data/shaders/mesh.vert.glsl",
					 "data/shaders/mesh.frag.glsl");
    if (!this->m_shader->init())
      return (false);
    this->m_camera = new Display::Camera;
    this->m_map = new Display::MapRenderer;
    if (!this->m_map->init())
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
	      {
		glViewport(0, 0, event.size.width, event.size.height);
		this->m_camera->resize(event.size.width, event.size.height);
	      }
	    else if (event.type == sf::Event::MouseMoved)
	      {
		if (event.mouseMove.x != m_win->getSize().x / 2 ||
		    event.mouseMove.y != m_win->getSize().y / 2)
		  {
		    this->m_camera->lookHori((event.mouseMove.x
					      - this->m_win->getSize().x / 2.0f)
					     * 0.005f);
		    this->m_camera->lookVerti((event.mouseMove.y
					       - this->m_win->getSize().y / 2.0f)
					      * 0.005f);
		    sf::Mouse::setPosition(sf::Vector2i(m_win->getSize().x / 2,
							m_win->getSize().y / 2),
					   *m_win);
		  }
	      }
	  }
	this->movement(event);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	this->m_map->draw(this->m_shader, this->m_camera);
	this->m_win->display();
      }
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

  void		Window::movement(sf::Event &event)
  {
    float	forward;
    float	aside;

    forward = 0.5f * sf::Keyboard::isKeyPressed(sf::Keyboard::Up) +
      (- 0.5f) * sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    aside = 0.5f * sf::Keyboard::isKeyPressed(sf::Keyboard::Right) +
      (- 0.5f) * sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    this->m_camera->moveForward(forward);
    this->m_camera->moveAside(aside);
  }
};
