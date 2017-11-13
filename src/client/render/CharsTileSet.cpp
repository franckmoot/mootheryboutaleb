#include <iostream>

#include "CharsTileSet.h"

#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"

using namespace std;
using namespace state;

namespace render {
  
  CharsTileSet::CharsTileSet() {
    
    infanterie.push_back(Tile(36,0,16,30));
    infanterie.push_back(Tile(36,0,16,16));
    infanterie.push_back(Tile(36,0,16,16));
    tank.push_back(Tile(109,0,16,16));
    tank.push_back(Tile(109,0,16,16));
    heli.push_back(Tile(216,16,16,30));
    heli.push_back(Tile(216,32,16,16)); 
    
  }
  
  
  const std::string CharsTileSet::getImageFile() const {
    return "res/player.png";
  }
  
  
  const Tile& CharsTileSet::getTile(const state::Element& e) const {
    
    if(!e.isStatic()){
      MobileElement* mobileTmp = (MobileElement*)&e;
      
      if(mobileTmp->getTypeId()==INFANTERIE){     
	
	return infanterie[MVTATTENTE];
	
      }else if (mobileTmp->getTypeId()==TANK){
	
	return tank[MVTATTENTE2];
	
      }else if( mobileTmp->getTypeId()==HELI){
	
	return heli[MVTATTENTE1];
      }
    }
    return infanterie[MVTATTENTE];
  }

}
