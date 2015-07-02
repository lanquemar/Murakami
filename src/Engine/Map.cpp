/*
** Map.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jul  2 10:38:26 2015 Adrien Vasseur
** Last update Thu Jul  2 23:12:15 2015 Adrien Vasseur
*/

#include		"Engine/Map.h"

namespace		Engine
{
  Map::Map(Engine::WorldCollider *world) : m_world(world)
  {
    this->m_ground = NULL;
    this->m_wall = NULL;
    this->m_groundTriangle = NULL;
    this->m_wallTriangle = NULL;
    this->m_groundShape = NULL;
    this->m_wallShape = NULL;
    this->m_groundMotionState = NULL;
    this->m_wallMotionState = NULL;
    this->m_groundRigidBody = NULL;
    this->m_wallRigidBody = NULL;
  }

  Map::~Map()
  {
    this->m_world->remRigidBody(this->m_groundRigidBody);
    this->m_world->remRigidBody(this->m_wallRigidBody);
    if (this->m_ground)
      delete this->m_ground;
    if (this->m_wall)
      delete this->m_wall;
    if (this->m_groundTriangle)
      delete this->m_groundTriangle;
    if (this->m_wallTriangle)
      delete this->m_wallTriangle;
    if (this->m_groundShape)
      delete this->m_groundShape;
    if (this->m_wallShape)
      delete this->m_wallShape;
    if (this->m_groundMotionState)
      delete this->m_groundMotionState;
    if (this->m_wallMotionState)
      delete this->m_wallMotionState;
    if (this->m_groundRigidBody)
      delete this->m_groundRigidBody;
    if (this->m_wallRigidBody)
      delete this->m_wallRigidBody;
  }

  bool			Map::init()
  {
    this->m_ground = new Engine::ObjImporter;
    if (!this->m_ground->loadFromFile("data/obj/ground.obj"))
      return (false);

    this->m_groundTriangle = new btTriangleMesh;
    Engine::Map::createMesh(this->m_groundTriangle, this->m_ground->f_vertex);

    this->m_groundShape = new btBvhTriangleMeshShape(this->m_groundTriangle, false);
    this->m_groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));

    btRigidBody::btRigidBodyConstructionInfo groundInfo(0, this->m_groundMotionState, this->m_groundShape, btVector3(0, 0, 0));

    this->m_groundRigidBody = new btRigidBody(groundInfo);
    this->m_world->addRigidBody(this->m_groundRigidBody);

    this->m_wall = new Engine::ObjImporter;
    if (!this->m_wall->loadFromFile("data/obj/wall.obj"))
      return (false);

    this->m_wallTriangle = new btTriangleMesh;
    Engine::Map::createMesh(this->m_wallTriangle, this->m_wall->f_vertex);

    this->m_wallShape = new btBvhTriangleMeshShape(this->m_wallTriangle, false);
    this->m_wallMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));

    btRigidBody::btRigidBodyConstructionInfo wallInfo(0, this->m_wallMotionState, this->m_wallShape, btVector3(0, 0, 0));

    this->m_wallRigidBody = new btRigidBody(wallInfo);
    this->m_world->addRigidBody(this->m_wallRigidBody);

    return (true);
  }

  Engine::ObjImporter	*Map::getGroundMesh()
  {
    return (this->m_ground);
  }

  Engine::ObjImporter	*Map::getWallMesh()
  {
    return (this->m_wall);
  }

  void			Map::createMesh(btTriangleMesh *mesh,
					std::vector<GLfloat> vertex)
  {
    for (std::size_t i = 0; i < vertex.size(); i += 9)
      {
	mesh->addTriangle(btVector3(vertex[i],
				    vertex[i + 1],
				    vertex[i + 2]),
			  btVector3(vertex[i + 3],
				    vertex[i + 4],
				    vertex[i + 5]),
			  btVector3(vertex[i + 6],
				    vertex[i + 7],
				    vertex[i + 8]));
      }
  }
};
