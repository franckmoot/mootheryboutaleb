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
    infanterie.push_back( Tile(0,32,32,32));
    heli.push_back( Tile(32,0,32,32));//0 -> helicoptere
    heli.push_back( Tile(32,32,32,32));//0 -> helicoptere
    tank.push_back( Tile(64,0,32,32));//0 tank
    tank.push_back( Tile(96,0,32,32));//0 tank
    tank.push_back( Tile(64,32,32,32));//0 tank
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
            if(mobileTmp->getJoueur()==1)return infanterie[0];
            if(mobileTmp->getJoueur()==2)return infanterie[1];
	  break;
	  
	case TANK:    
	  
            if(mobileTmp->getJoueur()==1)return tank[0];
            if(mobileTmp->getJoueur()==2)return tank[2];
	  break;
        
        case HELI:    
            if(mobileTmp->getJoueur()==1)return heli[0];
            if(mobileTmp->getJoueur()==2)return heli[1];
            
	  break;
        
	default:
	  return infanterie[0];
	  break;
	}
      
    }  
        return infanterie[0];
  }
}
