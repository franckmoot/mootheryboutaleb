#include "Champdebataille.h"


namespace state {

    Champdebataille::Champdebataille(ChampdebatailleTypeId id) {

    }
    
    Champdebataille::~Champdebataille() {

    }

    const TypeId Champdebataille::getTypeId() {
        return this->getChampdeBatailleType();

    }
    
    const bool Champdebataille::isStatic() {
        if (this == Champdebataille) return true;
        else return false;
    }

   

    const int Champdebataille::diffMap() {
        if(this == Champdebataille) return true;
        else return false;

    }
       
    ChampdebatailleTypeId Champdebataille::getChampdeBatailleType() const {
        return ChampdebatailleTypeId;

    }         

}