/*
** WorldCollider.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jul  2 00:01:09 2015 Adrien Vasseur
** Last update Thu Jul  2 23:17:04 2015 Adrien Vasseur
*/

#include	"Engine/WorldCollider.h"

namespace	Engine
{
  WorldCollider::WorldCollider()
  {
    this->m_broadphase = NULL;
    this->m_configuration = NULL;
    this->m_dispatcher = NULL;
    this->m_solver = NULL;
    this->m_world = NULL;
  }

  WorldCollider::~WorldCollider()
  {
    if (this->m_broadphase)
      delete this->m_broadphase;
    if (this->m_configuration)
      delete this->m_configuration;
    if (this->m_dispatcher)
      delete this->m_dispatcher;
    if (this->m_solver)
      delete this->m_solver;
    if (this->m_world)
      delete this->m_world;
  }

  bool		WorldCollider::init()
  {
    this->m_broadphase = new btDbvtBroadphase;

    this->m_configuration = new btDefaultCollisionConfiguration();
    this->m_dispatcher = new btCollisionDispatcher(this->m_configuration);

    this->m_solver = new btSequentialImpulseConstraintSolver;

    this->m_world = new btDiscreteDynamicsWorld(this->m_dispatcher,
						this->m_broadphase,
						this->m_solver,
						this->m_configuration);
    this->m_world->setGravity(btVector3(0, -10, 0));

    this->m_clock.restart();
    return (true);
  }

  void		WorldCollider::update()
  {
    sf::Time	elapsed;

    elapsed = this->m_clock.getElapsedTime();
    this->m_world->stepSimulation(elapsed.asMilliseconds() / 1000.0f, 10);
    this->m_clock.restart();
  }

  void		WorldCollider::addRigidBody(btRigidBody *body)
  {
    this->m_world->addRigidBody(body);
  }

  void		WorldCollider::remRigidBody(btRigidBody *body)
  {
    this->m_world->removeRigidBody(body);
  }
};
