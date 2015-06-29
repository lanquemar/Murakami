/*
** MapRenderer.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sun Jun 28 22:22:43 2015 Adrien Vasseur
** Last update Mon Jun 29 22:46:33 2015 Adrien Vasseur
*/

#include	"Display/Renderer/MapRenderer.h"

namespace	Display
{
  MapRenderer::MapRenderer()
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
    this->m_ground = new MeshRenderer;
    if (!this->m_ground->init("data/obj/ground.obj"))
      return (false);
    this->m_wall = new MeshRenderer;
    if (!this->m_wall->init("data/obj/wall.obj"))
      return (false);
    return (true);
  }

  void		MapRenderer::draw(Display::Shader *shader, Display::Camera *camera)
  {
    this->m_ground->draw(shader, camera);
    this->m_wall->draw(shader, camera);
  }
};
