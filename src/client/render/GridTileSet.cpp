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
        if(E->isStatic());
         
        
         
        
        /*
        //if((e.isStatic)return chpbataille(state::ChampdebatailleTypeId::HERBE);
        if((e==state::Champdebataille)&&(e.getType()==state::ChampdebatailleTypeId::ROCHER))return chpbataille(state::ChampdebatailleTypeId::ROCHER);
        if((e==state::Champdebataille)&&(e.getType()==state::ChampdebatailleTypeId::ROUTE))return chpbataille(state::ChampdebatailleTypeId::ROUTE);
        if((e==state::Champdebataille)&&(e.getType()==state::ChampdebatailleTypeId::SABLE))return chpbataille(state::ChampdebatailleTypeId::SABLE);
        if((e==state::Batiment)&&(e.getType()==state::BatimentTypeId::QG))return batiment(state::BatimentTypeId::QG);
        if((e==state::Batiment)&&(e.getType()==state::BatimentTypeId::CASERNE))return batiment(state::BatimentTypeId::CASERNE);       */ 
        
        return *(new Tile(4,4,4,4));
    }
        
    }

