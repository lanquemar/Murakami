/*
** Window.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 11:57:38 2015 Adrien Vasseur
** Last update Wed Jun 24 12:18:03 2015 Adrien Vasseur
*/

#ifndef			WINDOW_H_
# define		WINDOW_H_

# include		<SFML/Window.hpp>
# include		<SFML/OpenGL.hpp>

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
    sf::Window		*m_win;
  };
};

#endif			/* !WINDOW_H_ */
