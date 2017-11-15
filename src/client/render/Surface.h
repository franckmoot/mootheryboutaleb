// Generated by dia2code
#ifndef RENDER__SURFACE__H
#define RENDER__SURFACE__H

#include <SFML/Graphics.hpp>
#include <string>

namespace render {
  class Tile;
};
namespace sf {
  class Transformable;
  class Drawable;
}


namespace render {

  /// class Surface - 
  class Surface : public sf::Transformable, public sf::Drawable {
    // Attributes
  public:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    // Operations
  public:
    Surface ();
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    void initQuads (int count);
    void setSpriteLocation (int i, int x, int y);
    void loadTexture (const std::string& image_file);
    void setSpriteTexture (int i, const Tile& tex);
    // Setters and Getters
  };

};

#endif
