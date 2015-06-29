/*
** ObjImporter.cpp for Murakami in /home/vasseu_g/github/Murakami
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sat Jun 27 10:28:38 2015 Adrien Vasseur
** Last update Mon Jun 29 22:56:33 2015 Adrien Vasseur
*/

#include	"Display/Renderer/ObjImporter.h"

namespace	Display
{
  ObjImporter::ObjImporter()
  {
    this->m_texture = NULL;
    this->m_vertex.clear();
    this->m_texcoord.clear();
    this->m_normal.clear();
    this->f_vertex.clear();
    this->f_texcoord.clear();
    this->f_normal.clear();
    this->m_index.clear();
    this->m_func.clear();
    this->m_func.insert(std::make_pair("o", &Display::ObjImporter::newTexture));
    this->m_func.insert(std::make_pair("vt", &Display::ObjImporter::newTextureCoord));
    this->m_func.insert(std::make_pair("v", &Display::ObjImporter::newVertex));
    this->m_func.insert(std::make_pair("vn", &Display::ObjImporter::newNormal));
    this->m_func.insert(std::make_pair("f", &Display::ObjImporter::newFace));
  }

  ObjImporter::~ObjImporter()
  {
    if (this->m_texture)
      delete this->m_texture;
    this->m_vertex.clear();
    this->m_texcoord.clear();
    this->m_normal.clear();
    this->f_vertex.clear();
    this->f_texcoord.clear();
    this->f_normal.clear();
    this->m_index.clear();
    this->m_func.clear();
  }

  bool		ObjImporter::loadFromFile(const std::string filename)
  {
    std::ifstream	file(filename.c_str());
    std::string		line;
    std::string		token;
    std::stringstream	stream;
    std::vector<std::string>	infos;
    bool		correct;
    MyPtr		func;

    if (!file)
      {
	std::cerr << "[ERROR] ObjImporter::loadFromFile : unable to open "
		  << filename << std::endl;
	return (false);
      }
    while (getline(file, line))
      {
	stream.clear();
	infos.clear();
	correct = true;
	func = NULL;
	stream << line;
	while (getline(stream, token, ' ') && correct)
	  {
	    if (token.size() != 0 && token[0] != '\r')
	      infos.push_back(token);
	    if (infos.size() == 1)
	      {
		if (this->m_func.find(token) == this->m_func.end())
		  correct = false;
		else
		  func = this->m_func[token];
	      }
	  }
	if (func)
	  (this->*func)(infos);
      }
    file.close();
    std::cout << "[INFO] Loaded [" << this->f_vertex.size() / 3 << "/";
    std::cout << this->f_texcoord.size() / 3 << "/";
    std::cout << this->f_normal.size() / 3 << "] [vertices/texcoord/normals]"
	      << std::endl;
  }

  void		ObjImporter::newTexture(std::vector<std::string> token)
  {
    if (token.size() != 2)
      std::cerr << "[ERROR] ObjImporter::newTexture : bad token" << std::endl;
    else
      {
	if (token[1].size() > 0 && token[1][token[1].size() - 1] == '\r')
	  token[1].pop_back();
	if (this->m_texture)
	  delete this->m_texture;
	this->m_texture = new sf::Texture;
	if (!this->m_texture->loadFromFile("data/textures/" + token[1]))
	  std::cerr << "[ERROR] ObjImporter::newTexture : unable to load "
		    << "data/textures/" + token[1] << std::endl;
	this->m_texture->setRepeated(true);
      }
  }

  void		ObjImporter::newTextureCoord(std::vector<std::string> token)
  {
    if (token.size() != 3)
      std::cerr << "[ERROR] ObjImporter::newTextureCoord : bad token" << std::endl;
    else
      {
	try
	  {
	    this->m_texcoord.push_back(std::stof(token[1]));
	    this->m_texcoord.push_back(std::stof(token[2]));
	  }
	catch(const std::invalid_argument &e)
	  {
	    std::cerr << "[ERROR] ObjImporter::newTextureCoord : std::stof exception "
		      << e.what() << std::endl;
	  }
	catch(const std::out_of_range &e)
	  {
	    std::cerr << "[ERROR] ObjImporter::newTextureCoord : std::stof exception "
		      << e.what() << std::endl;
	  }
      }
  }

  void		ObjImporter::newVertex(std::vector<std::string> token)
  {
    if (token.size() != 4)
      std::cerr << "[ERROR] ObjImporter::newVertex : bad token" << std::endl;
    else
      {
	try
	  {
	    this->m_vertex.push_back(std::stof(token[1]));
	    this->m_vertex.push_back(std::stof(token[2]));
	    this->m_vertex.push_back(std::stof(token[3]));
	  }
	catch(const std::invalid_argument &e)
	  {
	    std::cerr << "[ERROR] ObjImporter::newVertex : std::stof exception "
		      << e.what() << std::endl;
	  }
	catch(const std::out_of_range &e)
	  {
	    std::cerr << "[ERROR] ObjImporter::newVertex : std::stof exception "
		      << e.what() << std::endl;
	  }
      }
  }

  void		ObjImporter::newNormal(std::vector<std::string> token)
  {
    if (token.size() != 4)
      std::cerr << "[ERROR] ObjImporter::newNormal : bad token" << std::endl;
    else
      {
	try
	  {
	    this->m_normal.push_back(std::stof(token[1]));
	    this->m_normal.push_back(std::stof(token[2]));
	    this->m_normal.push_back(std::stof(token[3]));
	  }
	catch(const std::invalid_argument &e)
	  {
	    std::cerr << "[ERROR] ObjImporter::newNormal : std::stof exception "
		      << e.what() << std::endl;
	  }
	catch(const std::out_of_range &e)
	  {
	    std::cerr << "[ERROR] ObjImporter::newNormal : std::stof exception "
		      << e.what() << std::endl;
	  }
      }
  }

    void	ObjImporter::newFace(std::vector<std::string> token)
    {
      std::stringstream	stream;
      std::string	elem;
      int		id;

      if (token.size() != 4)
	std::cerr << "[ERROR] ObjImporter::newFace : bad token" << std::endl;
      else
	{
	  for (int i = 1; i < 4; i++)
	    {
	      stream.clear();
	      stream << token[i];
	      for (int j = 0; j < 3; j++)
		{
		  if (getline(stream, elem, '/'))
		    {
		      try
			{
			  id = std::stoi(elem) - 1;
			  this->f_vertex.push_back(this->m_vertex[id * 3]);
			  this->f_vertex.push_back(this->m_vertex[id * 3 + 1]);
			  this->f_vertex.push_back(this->m_vertex[id * 3 + 2]);
			}
		      catch(const std::invalid_argument &e)
			{
			  std::cerr << "[ERROR] ObjImporter::newFace : std::stof exception "
				    << e.what() << std::endl;
			}
		      catch(const std::out_of_range &e)
			{
			  std::cerr << "[ERROR] ObjImporter::newFace : std::stof exception "
				    << e.what() << std::endl;
			}
		    }
		  if (getline(stream, elem, '/'))
		    {
		      try
			{
			  id = std::stoi(elem) - 1;
			  this->f_texcoord.push_back(this->m_texcoord[id * 2]);
			  this->f_texcoord.push_back(this->m_texcoord[id * 2 + 1]);
			}
		      catch(const std::invalid_argument &e)
			{
			  std::cerr << "[ERROR] ObjImporter::newFace : std::stof exception "
				    << e.what() << std::endl;
			}
		      catch(const std::out_of_range &e)
			{
			  std::cerr << "[ERROR] ObjImporter::newFace : std::stof exception "
				    << e.what() << std::endl;
			}
		    }
		  if (getline(stream, elem, '/'))
		    {
		      try
			{
			  id = std::stoi(elem) - 1;
			  this->f_normal.push_back(this->m_normal[id * 3]);
			  this->f_normal.push_back(this->m_normal[id * 3 + 1]);
			  this->f_normal.push_back(this->m_normal[id * 3 + 2]);
			}
		      catch(const std::invalid_argument &e)
			{
			  std::cerr << "[ERROR] ObjImporter::newFace : std::stof exception "
				    << e.what() << std::endl;
			}
		      catch(const std::out_of_range &e)
			{
			  std::cerr << "[ERROR] ObjImporter::newFace : std::stof exception "
				    << e.what() << std::endl;
			}
		    }
		}
	    }
	}
    }
};
