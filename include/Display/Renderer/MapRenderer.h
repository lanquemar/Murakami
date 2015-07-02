/*
** MapRenderer.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sun Jun 28 22:19:29 2015 Adrien Vasseur
** Last update Thu Jul  2 23:27:55 2015 Adrien Vasseur
*/

#ifndef				MAPRENDERER_H_
# define			MAPRENDERER_H_

# include			"Display/Shader.h"
# include			"Display/Camera.h"
# include			"Display/Renderer/MeshRenderer.h"
# include			"Engine/Map.h"

namespace			Display
{
  class				MapRenderer
  {
  public:
    MapRenderer(Engine::Map *);
    ~MapRenderer();

    bool			init();
    void			draw(Display::Shader *, Display::Camera *);

  private:
    Engine::Map			*e_map;

    Display::MeshRenderer	*m_wall;
    Display::MeshRenderer	*m_ground;
  };
};

#endif				/* !MAPRENDERER_H_ */
