/*
** Map.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jul  2 10:28:43 2015 Adrien Vasseur
** Last update Thu Jul  2 23:10:09 2015 Adrien Vasseur
*/

#ifndef				MAP_H_
# define			MAP_H_

# include			<btBulletDynamicsCommon.h>

# include			"Engine/ObjImporter.h"
# include			"Engine/WorldCollider.h"

namespace			Engine
{
  class				Map
  {
  public:
    Map(Engine::WorldCollider *);
    ~Map();

    bool			init();

    Engine::ObjImporter		*getGroundMesh();
    Engine::ObjImporter		*getWallMesh();

  private:
    static void			createMesh(btTriangleMesh *, std::vector<GLfloat>);

    Engine::WorldCollider	*m_world;

    Engine::ObjImporter		*m_ground;
    Engine::ObjImporter		*m_wall;

    btTriangleMesh		*m_groundTriangle;
    btTriangleMesh		*m_wallTriangle;
    btCollisionShape		*m_groundShape;
    btCollisionShape		*m_wallShape;
    btDefaultMotionState	*m_groundMotionState;
    btDefaultMotionState	*m_wallMotionState;
    btRigidBody			*m_groundRigidBody;
    btRigidBody			*m_wallRigidBody;
  };
};

#endif				/* !MAP_H_ */
