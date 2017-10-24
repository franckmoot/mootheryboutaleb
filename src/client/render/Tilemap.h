// Generated by dia2code
#ifndef RENDER__TILEMAP__H
#define RENDER__TILEMAP__H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace sf {
  class Transformable;
  class Drawable;
}


namespace render {

  /// class Tilemap - 
  class Tilemap : public sf::Transformable, public sf::Drawable {
    // Attributes
  public:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    // Operations
  public:
    bool load (const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);
    std::vector<int> lirefichiercsv (std::vector<int> carte);
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    // Setters and Getters
  };

};

#endif
