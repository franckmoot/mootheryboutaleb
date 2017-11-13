// Generated by dia2code
#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H

#include <memory>

namespace render {
  class Surface;
  class Tilemap;
  class TileSet;
};
namespace state {
  class ElementChars;
  class ElementTab;
}

#include "Surface.h"
#include "Tilemap.h"
#include "TileSet.h"
#include "state/ElementChars.h"
#include "state/ElementTab.h"

namespace render {

  /// class Layer - 
  class Layer {
    // Associations
    // Attributes
  public:
    std::unique_ptr<Surface> surface;
  protected:
    std::unique_ptr<Tilemap> tilemap;
    std::shared_ptr<TileSet> tileset;
    // Operations
  public:
    void initmap ();
    void initRandMap ();
    void displayChars (state::ElementChars* a);
    void initSurface ();
    // Setters and Getters
    const std::unique_ptr<Tilemap>& getTilemap() const;
    void setTilemap(const std::unique_ptr<Tilemap>& tilemap);
    const std::shared_ptr<TileSet>& getTileset() const;
    void setTileset(const std::shared_ptr<TileSet>& tileset);
  };

};

#endif
