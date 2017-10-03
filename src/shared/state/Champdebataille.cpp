#include "Champdebataille.h"


namespace state {

    Champdebataille::Champdebataille(ChampdebatailleTypeId id) {

    }
    
    Champdebataille::~Champdebataille() {

    }

    const TypeId Champdebataille::getTypeId() {
        return ChampdebatailleTypeId;

    }
    
    const bool Champdebataille::isStatic() {
        if (this == Champdebataille) return true;
        else return false;
    }

   

    const int Champdebataille::diffMap() {

    }

}