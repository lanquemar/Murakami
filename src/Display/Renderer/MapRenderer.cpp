/*
** MapRenderer.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sun Jun 28 22:22:43 2015 Adrien Vasseur
** Last update Thu Jul  2 23:28:16 2015 Adrien Vasseur
*/

#include	"Display/Renderer/MapRenderer.h"

namespace	Display
{
  MapRenderer::MapRenderer(Engine::Map *map) : e_map(map)
  {
    this->m_wall = NULL;
    this->m_ground = NULL;
  }

  MapRenderer::~MapRenderer()
  {
    if (this->m_wall)
      delete this->m_wall;
    if (this->m_ground)
      delete this->m_ground;
  }

  bool		MapRenderer::init()
  {
    this->m_ground = new MeshRenderer(this->e_map->getGroundMesh());
    if (!this->m_ground->init())
      return (false);

    this->m_wall = new MeshRenderer(this->e_map->getWallMesh());
    if (!this->m_wall->init())
      return (false);
    return (true);
  }

  void		MapRenderer::draw(Display::Shader *shader, Display::Camera *camera)
  {
    this->m_ground->draw(shader, camera);
    this->m_wall->draw(shader, camera);
  }
};
