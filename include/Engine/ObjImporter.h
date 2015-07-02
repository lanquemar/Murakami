/*
** ObjImporter.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sat Jun 27 10:29:13 2015 Adrien Vasseur
** Last update Thu Jul  2 23:14:58 2015 Adrien Vasseur
*/

#ifndef				OBJIMPORTER_H_
# define			OBJIMPORTER_H_

# include			<string>
# include			<map>
# include			<iostream>
# include			<fstream>
# include			<sstream>

# include			<GL/glew.h>

# include			<SFML/Graphics/Texture.hpp>

namespace			Engine
{
  class				ObjImporter
  {
  public:
    ObjImporter();
    ~ObjImporter();

    bool			loadFromFile(const std::string);

    typedef void (ObjImporter::*MyPtr)(std::vector<std::string>);

    std::vector<GLfloat>	f_vertex;
    std::vector<GLfloat>	f_texcoord;
    std::vector<GLfloat>	f_normal;

    sf::Texture			*m_texture;

  private:
    void			newTexture(std::vector<std::string>);
    void			newTextureCoord(std::vector<std::string>);
    void			newVertex(std::vector<std::string>);
    void			newNormal(std::vector<std::string>);
    void			newFace(std::vector<std::string>);

    std::vector<GLfloat>	m_vertex;
    std::vector<GLfloat>	m_texcoord;
    std::vector<GLfloat>	m_normal;
    std::vector<GLushort>	m_index;

    std::map<std::string, MyPtr>	m_func;
  };
};

#endif				/* !OBJIMPORTER_H_ */
