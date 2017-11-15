#include "Champdebataille.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
namespace state {

    Champdebataille::Champdebataille() {

    }
    
    Champdebataille::Champdebataille(ChampdebatailleTypeId id) {

        if (id == ChampdebatailleTypeId::EAU ) {
            champdeBatailleType=ChampdebatailleTypeId::EAU;
            
        }
        if (id == ChampdebatailleTypeId::HERBE ) {
            champdeBatailleType=ChampdebatailleTypeId::HERBE;

        }
        
        if (id == ChampdebatailleTypeId::MONTAGNE ) {
            champdeBatailleType=ChampdebatailleTypeId::MONTAGNE;

        }
        if (id == ChampdebatailleTypeId::ROUTE ) {
            champdeBatailleType=ChampdebatailleTypeId::ROUTE;

        }
        if (id == ChampdebatailleTypeId::SABLE1 ) {
            champdeBatailleType=ChampdebatailleTypeId::SABLE1;

        }
        if (id == ChampdebatailleTypeId::SABLE2 ) {
            champdeBatailleType=ChampdebatailleTypeId::SABLE2;

        }
    }

    Champdebataille::~Champdebataille() {

    }


    
   ChampdebatailleTypeId Champdebataille::getChampdeBatailleType() const {
        return champdeBatailleType;
    }


    bool Champdebataille::isChampdebataille() const {
        return true;
    }

    TypeId Champdebataille::getTypeId() const {
           return TypeId::CHAMPSDEBATAILLE;
    }
    
    
    
}