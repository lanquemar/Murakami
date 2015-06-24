/*
** Window.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 12:02:07 2015 Adrien Vasseur
** Last update Wed Jun 24 12:18:23 2015 Adrien Vasseur
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

  bool		Window::create()
  {
    this->m_win = new sf::Window(sf::VideoMode(800, 600), "Murakami", sf::Style::Default, sf::ContextSettings(32));
    if (!this->m_win)
      return (false);
    this->m_win->setVerticalSyncEnabled(true);
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
