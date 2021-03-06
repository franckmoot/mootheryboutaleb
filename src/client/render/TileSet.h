// Generated by dia2code
#ifndef RENDER__TILESET__H
#define RENDER__TILESET__H

#include <string>

namespace render {
  class Tile;
};
namespace state {
  class Element;
}

#include "state/Element.h"
#include "Tile.h"

namespace render {

  /// class TileSet - 
  class TileSet {
    // Associations
    // Operations
  public:
    TileSet ();
    virtual const std::string  getImageFile () const = 0;
    virtual const Tile& getTile (const state::Element& e) const = 0;
    // Setters and Getters
  };

};

#endif
