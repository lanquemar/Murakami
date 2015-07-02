/*
** WorldCollider.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jul  1 23:59:17 2015 Adrien Vasseur
** Last update Thu Jul  2 23:18:32 2015 Adrien Vasseur
*/

#ifndef						WORLDCOLLIDER_H_
# define					WORLDCOLLIDER_H_

# include					<iostream>

# include					<SFML/Graphics.hpp>

# include					<btBulletDynamicsCommon.h>

namespace					Engine
{
  class						WorldCollider
  {
  public:
    WorldCollider();
    ~WorldCollider();

    bool					init();
    void					update();
    void					addRigidBody(btRigidBody *);
    void					remRigidBody(btRigidBody *);

  private:
    btBroadphaseInterface			*m_broadphase;
    btDefaultCollisionConfiguration		*m_configuration;
    btCollisionDispatcher			*m_dispatcher;
    btSequentialImpulseConstraintSolver		*m_solver;
    btDiscreteDynamicsWorld			*m_world;

    sf::Clock					m_clock;
  };
};

#endif						/* !WORLDCOLLIDER_H_ */
