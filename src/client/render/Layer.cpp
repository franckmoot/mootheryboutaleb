#include "Tilemap.h"
#include "Layer.h"
#include "TileSet.h"
#include "state/ElementTab.h"
#include "state/ElementChars.h"
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

    void Layer::initmap() {
       // (monde.grid)=new ElementTab(); 
        std::vector<int> level;
        
        this->tilemap=std::unique_ptr<Tilemap>(new Tilemap());
        if (!this->tilemap->load("res/tile.png", sf::Vector2u(64, 64),this->tilemap->lirefichiercsv(level),10 , 10));// return -1;
    }
    const std::unique_ptr<Tilemap>& Layer::getTilemap() const {
        return this->tilemap;
    }

    void Layer::initRandMap(){
        std::vector<int> level(100);
        srand(time(NULL));
        for(size_t i=0;i<100;i++){
            level[i]=rand()%5+0;
            
        if (!this->tilemap->load("res/tile.png", sf::Vector2u(64, 64),level,10 , 10));
        
        
    }
  }
}  
            


