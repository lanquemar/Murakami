/*
** Main.cpp for Murakami in /home/vasseu_g/github/Murakami/src
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 11:55:41 2015 Adrien Vasseur
** Last update Thu Jul  2 23:02:35 2015 Adrien Vasseur
*/

#include		<iostream>

#include		"Engine/Core.h"

#include		"Display/Window.h"

int			main(void)
{
  Engine::Core		gamecore;
  Display::Window	gamewin(&gamecore);

  if (!gamecore.init())
    return (EXIT_FAILURE);
  if (!gamewin.create())
    return (EXIT_FAILURE);
  gamewin.run();
  return (EXIT_SUCCESS);
}
