#include "Tilemap.h"
#include "Layer.h"
#include "TileSet.h"
#include "state/ElementTab.h"
#include "state/ElementChars.h"





using namespace std;
using namespace state;

namespace render {

    void Layer::initmap() {
       // (monde.grid)=new ElementTab(); 
        std::vector<int> level;
        
        this->tilemap=std::unique_ptr<Tilemap>(new Tilemap());
        if (!this->tilemap->load("res/tile.png", sf::Vector2u(64, 64),this->tilemap->lirefichiercsv(level),10 , 10));// return -1;
    }
    const std::unique_ptr<Tilemap>& Layer::getTilemap() const {
        return this->tilemap;
    }

    
  }
            


