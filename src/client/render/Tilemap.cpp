#include "Tilemap.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace render {
  
  void Tilemap::draw (sf::RenderTarget& target, sf::RenderStates states) const 
  {
    
    // on applique la transformation
    states.transform *= getTransform();
    
    // on applique la texture du tileset
    states.texture = &m_tileset;
    
    // et on dessine enfin le tableau de vertex
    target.draw(m_vertices, states);
  }
  
  
  std::vector<int> Tilemap::lirefichiercsv(std::vector<int> vcarte) {
    std::ifstream fichier;
    fichier.open("res/map2.csv",std::ios::in);
    if(!fichier.good())
      throw std::runtime_error("Error opening!!");
    std::string ligne,valeur;
    
    // int i = 0;
    
    while(!fichier.eof()){
      std::getline(fichier,ligne);
      std::stringstream stream(ligne);
      //std::cout << ligne << std::endl;
      
      
      while(getline(stream, valeur,',')){
	
	vcarte.push_back(atoi(valeur.c_str()));
	
      }
    }
    return vcarte;
  }
  
  
  bool Tilemap:: load ( const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
  {
    
      
    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(tileset)) {
      cout << "Erreur lecture " << tileset << endl;
      return false;
    }
    
    //sreturn false;
    
    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);
    
    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < width; ++i)
      for (unsigned int j = 0; j < height; ++j)
	{
	  // on récupère le numéro de tuile courant
	//  int tileNumber = tiles[i + j * width];
	  
	  // on en déduit sa position dans la texture du tileset
	 // int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
	 // int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
	  
	  // on récupère un pointeur vers le quad à définir dans le tableau de vertex
	  sf::Vertex* quad = &m_vertices[(i + j * width) * 4];
	  
	  // on définit ses quatre coins
	  quad[0].position = sf::Vector2f(i * 16, j * 16);
	  quad[1].position = sf::Vector2f((i + 1) * 16, j * 16);
	  quad[2].position = sf::Vector2f((i + 1) * 16, (j + 1) * 16);
	  quad[3].position = sf::Vector2f(i * 16, (j + 1) * 16);
	  
	  // on définit ses quatre coordonnées de texture
	  quad[0].texCoords = sf::Vector2f(0, 0);
	  quad[1].texCoords = sf::Vector2f(32, 0);
	  quad[2].texCoords = sf::Vector2f(32, 32);
	  quad[3].texCoords = sf::Vector2f(0, 32);
	}
    
    return true;
  }
  
  void Tilemap::initQuads(int count) {
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(count * 4);
    
  }
  
  void Tilemap::loadTexture(const std::string& image_file) {
    
    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(image_file)) {
      cout << "Erreur lecture " << image_file << endl;
    }
      
  }
  
  void Tilemap::setSpriteLocation(int i, int x, int y) {
          sf::Vertex* quad = &m_vertices[(i) * 4];
      //sf::Vertex* quad = &m_vertices[(x + y * 10) * 4];
                // on définit ses quatre coins
	  quad[0].position = sf::Vector2f(x * 16, y * 16);
	  quad[1].position = sf::Vector2f((x + 1) * 16, y * 16);
	  quad[2].position = sf::Vector2f((x + 1) * 16, (y + 1) * 16);
	  quad[3].position = sf::Vector2f(x * 16, (y + 1) * 16);
    
    
  }
  
  void Tilemap::setSpriteTexture(int i, const Tile& tex) {
    
          //i + j * width
          sf::Vertex* quad = &m_vertices[(i) * 4];
      // on définit ses quatre coordonnées de texture
	  quad[0].texCoords = sf::Vector2f(tex.getX(), tex.getY());
	  quad[1].texCoords = sf::Vector2f(tex.getX()+tex.getWidth(), tex.getY());
	  quad[2].texCoords = sf::Vector2f(tex.getX()+tex.getWidth(), tex.getY()+tex.getHeight());
	  quad[3].texCoords = sf::Vector2f(tex.getX(), tex.getY()+tex.getHeight());
        
      
  }
  
  
  
  
}
