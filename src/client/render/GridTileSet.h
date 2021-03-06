// Generated by dia2code
#ifndef RENDER__GRIDTILESET__H
#define RENDER__GRIDTILESET__H

#include <vector>
#include <string>

namespace render {
  class Tile;
};
namespace state {
  class Element;
};
namespace render {
  class TileSet;
}

#include "Tile.h"
#include "TileSet.h"

namespace render {

  /// class GridTileSet - 
  class GridTileSet : public render::TileSet {
    // Attributes
  private:
    std::vector<Tile> chpbataille;
    std::vector<Tile> batiment;
    // Operations
  public:
    GridTileSet ();
    const std::string  getImageFile () const;
    const Tile&  getTile (const state::Element& e) const;
    // Setters and Getters
  };

};

#endif
