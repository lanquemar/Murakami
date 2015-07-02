/*
** Core.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jul  2 22:48:21 2015 Adrien Vasseur
** Last update Thu Jul  2 23:03:37 2015 Adrien Vasseur
*/

#include		"Engine/Core.h"

namespace		Engine
{
  Core::Core()
  {
    this->m_collider = NULL;
    this->m_map = NULL;
    this->m_player = NULL;
  }

  Core::~Core()
  {
    if (this->m_map)
      delete this->m_map;
    if (this->m_player)
      delete this->m_player;
    if (this->m_collider)
      delete this->m_collider;
  }

  bool			Core::init()
  {
    this->m_collider = new Engine::WorldCollider;
    if (!this->m_collider->init())
      return (false);

    this->m_map = new Engine::Map(this->m_collider);
    if (!this->m_map->init())
      return (false);

    this->m_player = new Engine::Player(this->m_collider);
    if (!this->m_player->init())
      return (false);

    return (true);
  }

  void			Core::update()
  {
    this->m_collider->update();
  }

  Engine::Map		*Core::getMap()
  {
    return (this->m_map);
  }

  Engine::Player	*Core::getPlayer()
  {
    return (this->m_player);
  }
};
