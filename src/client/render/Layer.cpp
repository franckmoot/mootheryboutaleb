#include "Tilemap.h"
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
  
  void Layer::displayChars() {
    
    std::vector<int> carteChars;
    
    ElementChars *elementChars= new ElementChars(9,11); 
    cout<<"La liste de chars fait : "<<elementChars->sizeList()<<endl;
     
    state::Heli *H=new Heli();
    Infanterie *I=new Infanterie();
    Tank *T=new Tank();
    Heli *He=new Heli();
    Infanterie *In=new Infanterie();
    Tank *Ta=new Tank();
    Tank *Tan=new Tank();
    
    elementChars->chgList(2,H);
    
    elementChars->chgList(13,T);
    elementChars->chgList(17,I);
    elementChars->chgList(29,He);
    elementChars->chgList(50,Ta);
    elementChars->chgList(98,In);
    elementChars->setElement(Tan);
    cout<<elementChars->sizeList()<<endl;
    
    
    carteChars=elementChars->ElementToCarte(carteChars);
    
    this->tilemap=std::unique_ptr<Tilemap>(new Tilemap());
    if (!this->tilemap->load("res/player.png", sf::Vector2u(64, 64),carteChars,10 , 10));
    
    
    
  }
  
  
  
}




