/*
** Core.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jul  2 22:46:26 2015 Adrien Vasseur
** Last update Thu Jul  2 23:01:54 2015 Adrien Vasseur
*/

#ifndef				CORE_H_
# define			CORE_H_

# include			"Engine/WorldCollider.h"
# include			"Engine/Map.h"
# include			"Engine/Player.h"

namespace			Engine
{
  class				Core
  {
  public:
    Core();
    ~Core();

    bool			init();
    void			update();

    Engine::Map			*getMap();
    Engine::Player		*getPlayer();

  private:
    Engine::WorldCollider	*m_collider;
    Engine::Map			*m_map;
    Engine::Player		*m_player;
  };
};

#endif				/* !CORE_H_ */
