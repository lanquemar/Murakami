/*
** Shader.h for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 21:31:32 2015 Adrien Vasseur
** Last update Wed Jun 24 22:26:53 2015 Adrien Vasseur
*/

#ifndef		SHADER_H_
# define	SHADER_H_

# include	<GL/glew.h>

# include	<iostream>
# include	<string>
# include	<fstream>

namespace	Display
{
  class		Shader
  {
  public:
    Shader(std::string, std::string);
    ~Shader();

    bool	init();
    GLuint	getProgramId() const;

    GLint	m_attr_vertex;
    GLint	m_attr_colors;
    GLint	m_uni_mvp;

  private:
    static void	printLog(GLuint);
    static bool	compile(GLuint &, GLenum, std::string const &);
    static bool	program(GLuint &, GLuint &, GLuint &);
    void	deleteAll();
    bool	initAttribute();

    GLuint	m_vertexId;
    GLuint	m_fragmentId;
    GLuint	m_programId;

    std::string	m_vertexSource;
    std::string	m_fragmentSource;
  };
};

#endif		/* !SHADER_H_ */
