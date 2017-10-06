#include "Champdebataille.h"


namespace state {

    Champdebataille::Champdebataille() {

    }
    
    Champdebataille::Champdebataille(ChampdebatailleTypeId id) {

        if (id == ChampdebatailleTypeId::EAU ) this->setType( ChampdebatailleTypeId::EAU );
        if (id == ChampdebatailleTypeId::HERBE ) this->setType( ChampdebatailleTypeId::HERBE );
        if (id == ChampdebatailleTypeId::ROCHER ) this->setType( ChampdebatailleTypeId::ROCHER );
        if (id == ChampdebatailleTypeId::ROUTE ) this->setType( ChampdebatailleTypeId::ROUTE );
        if (id == ChampdebatailleTypeId::SABLE ) this->setType( ChampdebatailleTypeId::SABLE );
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