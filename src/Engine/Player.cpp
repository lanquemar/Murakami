/*
** Player.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jul  2 12:56:21 2015 Adrien Vasseur
** Last update Thu Jul  2 16:06:39 2015 Adrien Vasseur
*/

#include	"Engine/Player.h"

namespace	Engine
{
  Player::Player(Engine::WorldCollider *world) : m_world(world)
  {
    this->m_shape = NULL;
    this->m_motionState = NULL;
    this->m_rigidBody = NULL;
  }

  Player::~Player()
  {
    this->m_world->remRigidBody(this->m_rigidBody);
    if (this->m_shape)
      delete this->m_shape;
    if (this->m_motionState)
      delete this->m_motionState;
    if (this->m_rigidBody)
      delete this->m_rigidBody;
  }

  bool		Player::init()
  {
    this->m_shape = new btCapsuleShape(0.5, 1.75);
    this->m_motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 3.0, 0)));

    btScalar mass = 60;
    btVector3 inertia(0, 0, 0);
    this->m_shape->calculateLocalInertia(mass, inertia);
    btRigidBody::btRigidBodyConstructionInfo info(mass, this->m_motionState, this->m_shape, inertia);

    this->m_rigidBody = new btRigidBody(info);
    this->m_rigidBody->setSleepingThresholds(0.0, 0.0);
    this->m_rigidBody->setAngularFactor(0.0);
    this->m_rigidBody->setContactProcessingThreshold(0.0);
    this->m_world->addRigidBody(this->m_rigidBody);

    return (true);
  }

  glm::vec3	Player::getPosition()
  {
    btTransform	trans;
    glm::vec3	pos;

    this->m_rigidBody->getMotionState()->getWorldTransform(trans);
    pos.x = trans.getOrigin().getX();
    pos.y = trans.getOrigin().getY();
    pos.z = trans.getOrigin().getZ();
    return (pos);
  }

  void		Player::move(float x, float y)
  {
    btVector3	velocity;
    btVector3	v_new;

    velocity = this->m_rigidBody->getLinearVelocity();
    v_new.setX(x * 10.0f);
    v_new.setY(velocity.getY());
    v_new.setZ(y * 10.0f);
    this->m_rigidBody->setLinearVelocity(v_new);
  }
};
