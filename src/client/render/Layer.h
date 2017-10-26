// Generated by dia2code
#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H

#include <memory>

namespace render {
  class Tilemap;
  class TileSet;
};
namespace state {
  class ElementTab;
  class ElementChars;
}

#include "Tilemap.h"
#include "TileSet.h"
#include "state/ElementTab.h"
#include "state/ElementChars.h"

namespace render {

  /// class Layer - 
  class Layer {
    // Associations
    // Attributes
  protected:
    std::unique_ptr<Tilemap> tilemap;
    std::shared_ptr<TileSet> tileset;
    // Setters and Getters
    const std::unique_ptr<Tilemap>& getTilemap() const;
    void setTilemap(const std::unique_ptr<Tilemap>& tilemap);
    const std::shared_ptr<TileSet>& getTileset() const;
    void setTileset(const std::shared_ptr<TileSet>& tileset);
  };

};

#endif
