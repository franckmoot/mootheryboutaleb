#include <iostream>

#include "CharsTileSet.h"

#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"

using namespace std;
using namespace state;

namespace render {
  
  CharsTileSet::CharsTileSet() {
    
    infanterie.push_back( Tile(0,0,32,32));//0 -> infanterie
    heli.push_back( Tile(32,0,32,32));//0 -> helicoptere
    tank.push_back( Tile(64,0,32,32));//0 tank
    tank.push_back( Tile(96,0,32,32));//0 tank
  }
  
  
  const std::string CharsTileSet::getImageFile() const {
    return "res/player.png";
  }
  
  
  const Tile& CharsTileSet::getTile(const state::Element& e) const {
     
    if(!e.isStatic()){
      MobileElement* mobileTmp = (MobileElement*)&e;
      cout<<mobileTmp->getTypeId()<<endl;
      
      switch (mobileTmp->getTypeId()){
	  
	case INFANTERIE:
	  return infanterie[0];
	  break;
	  
	case TANK:    
	  return tank[0];
	  break;
        
        case HELI:    
	  return heli[0];
	  break;
        
	default:
	  return infanterie[0];
	  break;
	}
      
    }  
        return infanterie[0];
  }
}
