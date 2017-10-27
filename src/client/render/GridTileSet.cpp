#include <iostream>

#include "GridTileSet.h"
#include "state/Champdebataille.h"
#include "state/Batiment.h"
#include "state/MobileElement.h"

using namespace std;
using namespace state;

namespace render {
  
  GridTileSet::GridTileSet() {
    
    chpbataille.push_back(*(new Tile(0,0,16,16)));
    chpbataille.push_back(*(new Tile(16,0,16,16)));
    chpbataille.push_back(*(new Tile(32,0,16,16)));
    chpbataille.push_back(*(new Tile(48,0,16,16)));
    chpbataille.push_back(*(new Tile(64,0,16,16)));
    batiment.push_back(*(new Tile(0,16,16,30)));
    batiment.push_back(*(new Tile(16,32,16,16))); 
  }
  
  
  const std::string GridTileSet::getImageFile() const {
    return "res/tilemap.png";
  }
  
  
  const Tile& GridTileSet::getTile(const state::Element& e) const {

    if(e.isStatic()){
      StaticElement* staticTmp = (StaticElement*)&e;
      
      if(staticTmp->isChampdebataille()){
	Champdebataille* champTmp = (Champdebataille*)&e;
	
	switch (champTmp->getChampdeBatailleType()){
	  
	case EAU:
	  return chpbataille[EAU];
	  break;
	  
	case HERBE:     
	  return chpbataille[HERBE];
	  break;
	  
	case ROCHER:
	  return chpbataille[ROCHER];
	  break;
          
	case ROUTE:
	  return chpbataille[ROUTE];
	  break;
          
	case SABLE:
	  return chpbataille[SABLE];
	  break;
          
	default:
	  return chpbataille[0];
	  break;
	}
      }else if (!staticTmp->isChampdebataille()){
        
	Batiment* batTmp=(Batiment*)&staticTmp;
	
	switch (batTmp->getBatimentTypeId()){
	  
	case CASERNE:
	  return batiment[CASERNE];
	  break;
	  
	case QG:    
	  return batiment[CASERNE];
	  break;
          
	default:
	  return batiment[0];
	  break;
	}
	
      }
    }
    
    return chpbataille[0];
  }
}



