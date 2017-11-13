#include <iostream>

#include "GridTileSet.h"
#include "state/Champdebataille.h"
#include "state/Batiment.h"
#include "state/MobileElement.h"

using namespace std;
using namespace state;

namespace render {
  
  GridTileSet::GridTileSet() {
    
    chpbataille.push_back( Tile(0,0,64,64)); //1 -> herbe
    chpbataille.push_back( Tile(64,0,64,64)); //2 -> route
    chpbataille.push_back( Tile(128,0,64,64)); //3 sable
    chpbataille.push_back( Tile(192,0,64,64)); //4 eau
    chpbataille.push_back( Tile(256,0,64,64)); //5 montage
    batiment.push_back( Tile(384,0,64,64)); // 0 qg
    batiment.push_back(Tile(320,0,64,64));  //1 caserne
  }
  
  
  const std::string GridTileSet::getImageFile() const {
    return "res/tile.png";
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
          cout<<"je suis la"<<endl;
	Batiment* batTmp=(Batiment*)staticTmp;
	cout<<"batimentTypeId = "<<batTmp->getBatimentTypeId()<<endl;
	switch (batTmp->getBatimentTypeId()){
	  
	case QG:
	  return batiment[QG];
	  break;
	  
	case CASERNE:    
	  return batiment[CASERNE];
	  break;
          
	default:
            cout<<"IL Y A UN PROLEME"<<endl;
	  return chpbataille[0];
	  break;
	}
	
      }
    }
    
    return chpbataille[0];
  }
}



