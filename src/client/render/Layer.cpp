#include "Tilemap.h"
#include "Layer.h"
#include "TileSet.h"
#include "GridTileSet.h"
#include "CharsTileSet.h"
#include "state/ElementTab.h"
#include "state/ElementChars.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/State.h"
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
  
  Layer::Layer(const state::State& state) : state(state) {
    this->surface= unique_ptr<Surface>(new Surface());
    this->surfaceplayer = unique_ptr<Surface>(new Surface());
    this->tileset= shared_ptr<GridTileSet>(new GridTileSet());
    this->tilesetChars= shared_ptr<CharsTileSet>(new CharsTileSet());
  }
  
  
  void Layer::initmap() {
    // (monde.grid)=new ElementTab(); 
    std::vector<int> level;
    
    this->tilemap=std::unique_ptr<Tilemap>(new Tilemap());
    if (!this->tilemap->load("res/tile.png", sf::Vector2u(64, 64),this->tilemap->lirefichiercsv(level),10 , 10));
  }
  
  
  const std::unique_ptr<Tilemap>& Layer::getTilemap() const {
    return this->tilemap;
  }
  
  void Layer::initRandMap(){
    std::vector<int> level(100);
    srand(time(NULL));
    for(size_t i=0;i<100;i++){
      level[i]=rand()%5+0;
      
      this->tilemap=std::unique_ptr<Tilemap>(new Tilemap());
      if (!this->tilemap->load("res/tile.png", sf::Vector2u(64, 64),level,10 , 10));
      
    }
  }
  
  void Layer::displayChars(state::ElementChars *a) {
    
    std::vector<int> carteChars;
    
    carteChars=a->ElementToCarte(carteChars);
    
    this->tilemap=std::unique_ptr<Tilemap>(new Tilemap());
    if (!this->tilemap->load("res/player.png", sf::Vector2u(64, 64),carteChars,10 , 10));
    
  }
  
  void Layer::initSurface (){
      
    int x;
    int y;
    this->surface->initQuads(400);
    this->surfaceplayer->initQuads(400);
    for (int i=0;i<400;i++){
        x=int(i/20);
        y=i%20; 
        this->surface->loadTexture( this->tileset->getImageFile() );
	this->surface->setSpriteLocation(i,y,x);
	this->surface->setSpriteTexture(i,this->tileset->getTile(*(state.grid->getElement(i,1))));  
    }
    for (int i=0;i<400;i++){
        x=int(i/20);
        y=i%20; 
        this->surfaceplayer->loadTexture( this->tilesetChars->getImageFile() );
	this->surfaceplayer->setSpriteLocation(i,y,x);
        if(state.chars->getElement(i,1)!=NULL){
	this->surfaceplayer->setSpriteTexture(i,this->tilesetChars->getTile(*(state.chars->getElement(i,1)))); 
        }
    }
    
  }
  
}


