/*
** Window.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 12:02:07 2015 Adrien Vasseur
** Last update Thu Jul  2 23:01:19 2015 Adrien Vasseur
*/

#include	"Display/Window.h"

namespace	Display
{
  Window::Window(Engine::Core *engine) : e_engine(engine)
  {
    this->m_win = NULL;
    this->m_shader = NULL;
    this->m_camera = NULL;
    this->m_gui = NULL;
    this->m_mapRenderer = NULL;
  }

  Window::~Window()
  {
    if (this->m_win)
      delete this->m_win;
    if (this->m_shader)
      delete this->m_shader;
    if (this->m_camera)
      delete this->m_camera;
    if (this->m_gui)
      delete this->m_gui;
    if (this->m_mapRenderer)
      delete this->m_mapRenderer;
  }

  bool		Window::create()
  {
    GLenum	status;

    this->initContext();
    this->m_win = new sf::RenderWindow(this->m_video, this->m_name,
				       sf::Style::Default, this->m_context);
    if (!this->m_win)
      return (false);
    /*    this->m_win->setVerticalSyncEnabled(true);*/

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
    this->m_camera = new Display::Camera(this->e_engine->getPlayer());
    this->m_gui = new Display::Gui;
    if (!this->m_gui->init())
      return (false);
    this->m_mapRenderer = new Display::MapRenderer(this->e_engine->getMap());
    if (!this->m_mapRenderer->init())
      return (false);
    return (true);
  }

  void		Window::run()
  {
    sf::Event	event;
    sf::View	view;
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
		view.reset(sf::FloatRect(0, 0, event.size.width,
					 event.size.height));
		this->m_win->setView(view);
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
	this->m_mapRenderer->draw(this->m_shader, this->m_camera);
	this->m_win->pushGLStates();
	this->m_gui->draw(this->m_win);
	this->m_win->popGLStates();
	this->m_win->display();
	this->e_engine->update();
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

    forward = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) +
      - sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    aside = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) +
      - sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    this->m_camera->move(forward, aside);
  }
};
