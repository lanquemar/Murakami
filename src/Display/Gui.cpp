/*
** Gui.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon Jun 29 23:29:03 2015 Adrien Vasseur
** Last update Tue Jun 30 00:05:10 2015 Adrien Vasseur
*/

#include	"Display/Gui.h"

namespace	Display
{
  Gui::Gui()
  {
    this->m_font = NULL;
    this->m_name = NULL;
    this->m_fps = NULL;
    this->fps = 0;
  }

  Gui::~Gui()
  {
    if (this->m_font)
      delete this->m_font;
    if (this->m_name)
      delete this->m_name;
    if (this->m_fps)
      delete this->m_fps;
  }

  bool		Gui::init()
  {
    this->m_font = new sf::Font;
    if (!this->m_font->loadFromFile("data/fonts/vera.ttf"))
      return (false);
    this->m_name = new sf::Text;
    this->m_name->setFont(*this->m_font);
    this->m_name->setString("Murakami");
    this->m_name->setCharacterSize(24);
    this->m_name->setColor(sf::Color::White);
    this->m_name->setPosition(5, 5);
    this->m_fps = new sf::Text;
    this->m_fps->setFont(*this->m_font);
    this->m_fps->setString("");
    this->m_fps->setCharacterSize(24);
    this->m_fps->setColor(sf::Color::White);
    this->m_fps->setPosition(5, 34);
    this->m_clock.restart();
    return (true);
  }

  void		Gui::draw(sf::RenderWindow *win)
  {
    sf::Time	elapsed;

    elapsed = this->m_clock.getElapsedTime();
    if (elapsed.asMilliseconds() >= 1000)
      {
	this->m_fps->setString(std::to_string(fps) + " fps");
	this->fps = 0;
	this->m_clock.restart();
      }
    win->draw(*this->m_name);
    win->draw(*this->m_fps);
    fps++;
  }
};
