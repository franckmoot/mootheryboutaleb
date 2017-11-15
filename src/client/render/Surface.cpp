#include "Surface.h"
#include "Layer.h"
#include "TileSet.h"
#include "state/ElementTab.h"
#include "state/ElementChars.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace state;

namespace render {
        Surface::Surface() {

    }

  
  void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    // on applique la transformation
    states.transform *= getTransform();
    
    // on applique la texture du tileset
    states.texture = &m_tileset;
    
    // et on dessine enfin le tableau de vertex
    target.draw(m_vertices, states);
  }
  
  
  void Surface::initQuads(int count) {
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(count*4);
    
  }
  
  void Surface::loadTexture(const std::string& image_file) {
    
    if (!m_tileset.loadFromFile(image_file)) {
      cout << "Erreur lecture " << image_file << endl;
      
    }
    
  }
  
  void Surface::setSpriteLocation(int i, int x, int y) {
    
    sf::Vertex* quad = &m_vertices[i * 4];
    quad[0].position = sf::Vector2f(x * 32, y * 32);
    quad[1].position = sf::Vector2f((x + 1) * 32, y * 32);
    quad[2].position = sf::Vector2f((x + 1) * 32, (y + 1) * 32);
    quad[3].position = sf::Vector2f(x * 32, (y + 1) * 32);
  }
   
  void Surface::setSpriteTexture(int i, const Tile& tile) {
    sf::Vertex* quad = &m_vertices[i * 4];
    quad[0].texCoords = sf::Vector2f(tile.getX(), tile.getY());
    quad[1].texCoords = sf::Vector2f(tile.getX()+tile.getWidth(), tile.getY());
    quad[2].texCoords = sf::Vector2f(tile.getX()+tile.getWidth(), tile.getY()+tile.getHeight());
    quad[3].texCoords = sf::Vector2f(tile.getX(), tile.getY()+tile.getHeight());
  }
  
}




