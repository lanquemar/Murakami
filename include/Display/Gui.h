/*
** Gui.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon Jun 29 23:26:25 2015 Adrien Vasseur
** Last update Mon Jun 29 23:59:08 2015 Adrien Vasseur
*/

#ifndef		GUI_H_
# define	GUI_H_

# include	<iostream>

# include	<SFML/Graphics.hpp>

namespace	Display
{
  class		Gui
  {
  public:
    Gui();
    ~Gui();

    bool	init();
    void	draw(sf::RenderWindow *);

  private:
    sf::Font	*m_font;
    sf::Text	*m_name;
    sf::Text	*m_fps;
    sf::Clock	m_clock;

    unsigned int	fps;
  };
};

#endif		/* !GUI_H_ */
