#include "Champdebataille.h"


namespace state {

    Champdebataille::Champdebataille() {

    }
        
    Champdebataille::~Champdebataille() {

    }


    
   ChampdebatailleTypeId Champdebataille::getChampdeBatailleType() const {
        return champdeBatailleType;
    }

    
    const bool Champdebataille::isChampdebataille() {
            return true;
    }

    const TypeId Champdebataille::getTypeId() {
        return TypeId::CHAMPSDEBATAILLE;
    }

    

}