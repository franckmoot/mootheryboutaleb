#include "GridTileSet.h"
#include "state/Champdebataille.h"

using namespace std;
using namespace state;
//using namespace Champdebataille;

namespace render {

    GridTileSet::GridTileSet() {
        chpbataille.push_back(new Tile(0,0,16,16));
        chpbataille.push_back(new Tile(16,0,16,16));
        chpbataille.push_back(new Tile(32,0,16,16));
        chpbataille.push_back(new Tile(48,0,16,16));
        chpbataille.push_back(new Tile(64,0,16,16));
        batiment.push_back(new Tile(0,23,16,30));
        batiment.push_back(new Tile(18,33,16,21)); 
    }
    
    int GridTileSet::getCellHeight() const {

        
    }

    int GridTileSet::getCellWidth() const {

        
    }
    
    const std::string GridTileSet::getImageFile() const {
        return "res/map1.csv"
        
    }
    
    const Tile& GridTileSet::getTile(const state::Element& e) const {
        if((e==Champdebataille)&&(e.getType()==EAU))return chpbataille(EAU);
        if((e==Champdebataille)&&(e.getType()==HERBE))return chpbataille(HERBE);
        if((e==Champdebataille)&&(e.getType()==ROCHER))return chpbataille(ROCHER);
        if((e==Champdebataille)&&(e.getType()==ROUTE))return chpbataille(ROUTE);
        if((e==Champdebataille)&&(e.getType()==SABLE))return chpbataille(SABLE);
        if((e==Batiment)&&(e.getType()==QG))return batiment(QG);
        if((e==Batiment)&&(e.getType()==CASERNE))return batiment(CASERNE);        
        }
        
    }

