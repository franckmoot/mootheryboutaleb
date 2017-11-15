#include <iostream>

#include "GridTileSet.h"
#include "state/Champdebataille.h"
#include "state/Batiment.h"
#include "state/MobileElement.h"

using namespace std;
using namespace state;

namespace render {
  
  GridTileSet::GridTileSet() {
    
    chpbataille.push_back( Tile(0,0,32,32)); //0 -> herbe
    chpbataille.push_back( Tile(32,0,32,32)); //1 -> route
    chpbataille.push_back( Tile(64,0,32,32)); //2 sable haut
    chpbataille.push_back( Tile(96,0,32,32)); //3 eau sable
    chpbataille.push_back( Tile(128,0,32,32)); //4 eau
    chpbataille.push_back( Tile(160,0,32,32));//5 montagne
    batiment.push_back( Tile(192,0,32,32)); // 0 qg
    batiment.push_back(Tile(224,0,32,32));  //1 caserne
  }
  
  
  const std::string GridTileSet::getImageFile() const {
    return "res/tile.png";
  }
  
  
  const Tile& GridTileSet::getTile(const state::Element& e) const {

    if(e.isStatic()){
      StaticElement* staticTmp = (StaticElement*)&e;
      
      if(staticTmp->isChampdebataille()){
	Champdebataille* champTmp = (Champdebataille*)&e;
	
        
        cout<<champTmp->getChampdeBatailleType()<<endl;
	switch (champTmp->getChampdeBatailleType()){
	
        case HERBE:     
	  return chpbataille[HERBE];
	  break;
        
        case ROUTE:
	  return chpbataille[ROUTE];
	  break;
          
        case SABLE1:
	  return chpbataille[SABLE1];
	  break;
          
        case SABLE2:
	  return chpbataille[SABLE2];
	  break;
          
	case EAU:
	  return chpbataille[EAU];
          cout<<"je suis la EN TANT QUE EAU"<<endl;
	  break;
	  
	case MONTAGNE:
	  return chpbataille[MONTAGNE];
	  break;
          
	default:
	  return chpbataille[0];
          cout<<"IL Y A UN PROLEME"<<endl;
	  break;
	}
      }else if (!staticTmp->isChampdebataille()){
          
	Batiment* batTmp=(Batiment*)staticTmp;
	
	switch (batTmp->getBatimentTypeId()){
	  
	case QG:
	  return batiment[QG];
	  break;
	  
	case CASERNE:    
	  return batiment[CASERNE];
	  break;
          
	default:
            
	  return chpbataille[0];
	  break;
	}
	
      }
    }
    
    return chpbataille[0];
  }
}



