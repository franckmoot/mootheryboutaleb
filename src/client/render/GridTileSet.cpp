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

    MobileElement* E = (MobileElement*)&e;
    if(E->isStatic()){
      Champdebataille* C=(Champdebataille*)&E;
      if(C->isChampdebataille()){
	
        
	switch (C->getChampdeBatailleType()){
	  
	case state::ChampdebatailleTypeId::EAU:
	  return chpbataille[ChampdebatailleTypeId::EAU];
	  break;
	  
	case state::ChampdebatailleTypeId::HERBE:     
	  return chpbataille[state::ChampdebatailleTypeId::HERBE];
	  break;
	  
	case state::ChampdebatailleTypeId::ROCHER:
	  return chpbataille[state::ChampdebatailleTypeId::ROCHER];
	  break;
          
	case state::ChampdebatailleTypeId::ROUTE:
	  return chpbataille[state::ChampdebatailleTypeId::ROUTE];
	  break;
          
	case state::ChampdebatailleTypeId::SABLE:
	  return chpbataille[state::ChampdebatailleTypeId::SABLE];
	  break;
          
	default:
	  return chpbataille[0];
	  break;
	}
      }
    }
    else{
      Batiment* C=(Batiment*)&E;
      if(!C->isChampdebataille()){
	
	switch (C->getBatimentTypeId()){
	  
	case state::BatimentTypeId::CASERNE:
	  return batiment[state::BatimentTypeId::CASERNE];
	  break;
	  
	case state::BatimentTypeId::QG:    
	  return batiment[state::BatimentTypeId::CASERNE];
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



