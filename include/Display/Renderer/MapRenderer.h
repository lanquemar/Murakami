/*
** MapRenderer.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sun Jun 28 22:19:29 2015 Adrien Vasseur
** Last update Sun Jun 28 22:27:32 2015 Adrien Vasseur
*/

#ifndef		MAPRENDERER_H_
# define	MAPRENDERER_H_

# include	"Display/Shader.h"
# include	"Display/Camera.h"
# include	"Display/Renderer/MeshRenderer.h"

namespace	Display
{
  class		MapRenderer
  {
  public:
    MapRenderer();
    ~MapRenderer();

    bool	init();
    void	draw(Display::Shader *, Display::Camera *);

  private:
    MeshRenderer	*m_wall;
    MeshRenderer	*m_ground;
  };
};

#endif		/* !MAPRENDERER_H_ */
