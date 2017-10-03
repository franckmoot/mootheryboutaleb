#include "Champdebataille.h"


namespace state {
    
    
    ChampdebatailleTypeId Champdebataille::getChampdeBatailleType() const {
        return champdeBatailleType;
    }

    
    const bool Champdebataille::isChampdebataille() {
            return true;
    }

            
}