/*
** Player.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jul  2 12:57:00 2015 Adrien Vasseur
** Last update Thu Jul  2 23:16:05 2015 Adrien Vasseur
*/

#ifndef				PLAYER_H_
# define			PLAYER_H_

# include			<glm/glm.hpp>

# include			<btBulletDynamicsCommon.h>

# include			"Engine/WorldCollider.h"

namespace			Engine
{
  class				Player
  {
  public:
    Player(Engine::WorldCollider *);
    ~Player();

    bool			init();
    glm::vec3			getPosition();
    void			move(float, float);

  private:
    Engine::WorldCollider	*m_world;

    btCapsuleShape		*m_shape;
    btDefaultMotionState	*m_motionState;
    btRigidBody			*m_rigidBody;
  };
};

#endif				/* !PLAYER_H_ */
