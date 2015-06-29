/*
** Shader.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun 24 21:34:45 2015 Adrien Vasseur
** Last update Sun Jun 28 15:01:28 2015 Adrien Vasseur
*/

#include		"Display/Shader.h"

namespace		Display
{
  Shader::Shader(std::string vertex, std::string fragment) :
    m_vertexSource(vertex), m_fragmentSource(fragment)
  {
    this->deleteAll();
  }

  Shader::~Shader()
  {
    this->deleteAll();
  }

  bool			Shader::init()
  {
    this->deleteAll();

    if (!Shader::compile(this->m_vertexId, GL_VERTEX_SHADER,
			 this->m_vertexSource))
      return (false);
    if (!Shader::compile(this->m_fragmentId, GL_FRAGMENT_SHADER,
			 this->m_fragmentSource))
      return (false);
    if (!Shader::program(this->m_programId, this->m_vertexId,
			 this->m_fragmentId))
      return (false);
    return (this->initAttribute());
  }

  GLuint		Shader::getProgramId() const
  {
    return (this->m_programId);
  }

  void			Shader::printLog(GLuint obj)
  {
    GLint		size;
    char		*log;

    size = 0;
    if (glIsShader(obj) == GL_TRUE)
      glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &size);
    else if (glIsProgram(obj) == GL_TRUE)
      glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &size);
    else
      {
	std::cerr << "[ERROR] Shader::printLog : unknown type." << std::endl;
	return ;
      }
    log = new char[size + 1];
    if (glIsShader(obj) == GL_TRUE)
      glGetShaderInfoLog(obj, size, NULL, log);
    else if (glIsProgram(obj) == GL_TRUE)
      glGetProgramInfoLog(obj, size, NULL, log);
    log[size] = '\0';
    std::cerr << "[ERROR] Shader::printLog : " << log << std::endl;
    delete[] log;
  }

  bool			Shader::compile(GLuint &shader, GLenum type,
					std::string const &src)
  {
    std::ifstream	file(src.c_str());
    std::string		line;
    std::string		code;
    GLchar		*sourceCode;
    GLint		compileState;

    compileState = 0;
    if ((shader = glCreateShader(type)) == 0)
      return (false);
    if (!file)
      {
	std::cerr << "[ERROR] Shader::compile : unable to read "
		  << src << std::endl;
	glDeleteShader(shader);
	return (false);
      }
    while (getline(file, line))
      code += line + '\n';
    file.close();

    sourceCode = (GLchar *) (code.c_str());
    glShaderSource(shader, 1, (const GLchar **) &sourceCode, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileState);
    if (compileState != GL_TRUE)
      {
	Shader::printLog(shader);
	glDeleteShader(shader);
	return (false);
      }
    return (true);
  }

  bool			Shader::program(GLuint &program, GLuint &vertex,
					GLuint &fragment)
  {
    GLint		linkState;

    linkState = 0;
    if ((program = glCreateProgram()) == 0)
      return (false);
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &linkState);
    if (linkState != GL_TRUE)
      {
	Shader::printLog(program);
	glDeleteProgram(program);
	return (false);
      }
    return (true);
  }

  void			Shader::deleteAll()
  {
    if (glIsShader(this->m_vertexId) == GL_TRUE)
      glDeleteShader(this->m_vertexId);
    if (glIsShader(this->m_fragmentId) == GL_TRUE)
      glDeleteShader(this->m_fragmentId);
    if (glIsProgram(this->m_programId) == GL_TRUE)
      glDeleteProgram(this->m_programId);

    this->m_vertexId = 0;
    this->m_fragmentId = 0;
    this->m_programId = 0;
  }

  bool			Shader::initAttribute()
  {
    std::string		name_vertex;
    std::string		name_texcoord;
    std::string		name_normal;
    std::string		name_mvp;
    std::string		name_data;

    name_vertex = "m_vertex";
    name_texcoord = "m_texcoord";
    name_normal = "m_normal";
    name_mvp = "m_mvp";
    name_data = "m_texture";
    this->m_attr_vertex = glGetAttribLocation(this->m_programId,
					      name_vertex.c_str());
    this->m_attr_texcoord = glGetAttribLocation(this->m_programId,
						name_texcoord.c_str());
    this->m_attr_normal = glGetAttribLocation(this->m_programId,
					      name_normal.c_str());
    this->m_uni_mvp = glGetUniformLocation(this->m_programId, name_mvp.c_str());
    this->m_uni_texture = glGetUniformLocation(this->m_programId,
					       name_data.c_str());
    if (this->m_attr_vertex == -1
	|| this->m_attr_texcoord == -1
	|| this->m_attr_normal == -1
	|| this->m_uni_mvp == -1
	|| this->m_uni_texture == -1)
      {
	std::cerr << "[ERROR] Shader::initAttribute : could not bind ";
	if (this->m_attr_vertex == -1)
	  std::cerr << name_vertex;
	if (this->m_attr_texcoord == -1)
	  std::cerr << name_texcoord;
	if (this->m_attr_normal == -1)
	  std::cerr << name_normal;
	if (this->m_uni_mvp == -1)
	  std::cerr << name_mvp;
	if (this->m_uni_texture)
	  std::cerr << name_data;
	std::cerr << std::endl;
	return (false);
      }
    return (true);
  }
};
