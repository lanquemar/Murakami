/*
** Main.cpp for Murakami in /home/vasseu_g/github/Murakami/src
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 11:55:41 2015 Adrien Vasseur
** Last update Wed Jun 24 12:12:11 2015 Adrien Vasseur
*/

#include	<iostream>

#include	"Display/Window.h"

int		main(void)
{
  Display::Window	gamewin;

  if (gamewin.create())
    gamewin.run();
  return (EXIT_SUCCESS);
}
