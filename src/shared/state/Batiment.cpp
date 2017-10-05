#include "Batiment.h"


namespace state {
  
    /* Constructeur */
    Batiment::Batiment() {

    }

    Batiment::Batiment(BatimentTypeId id) {
        
        if (id == BatimentTypeId::CASERNE ) this->setType( BatimentTypeId::CASERNE);
        if (id == BatimentTypeId::QG ) this->setType(BatimentTypeId::QG);
                    
    }

    const TypeId Batiment::getTypeId() {
        return TypeId::BATIMENT;
    }

    
    /* Getter de capture */
    const int Batiment::getCapture() {
            return capture;
    }
    
    /* Setter de capture */
    void Batiment::setCapture(int capture) {
        this->capture=capture;
    }

    /* Differenci le champdebataille au batiment*/
    const bool Batiment::isChampdebataille() {
        return false;
    }

    
    /* Getter de BatimentTypeId */
    BatimentTypeId Batiment::getBatimentTypeId() const {
        return batimentTypeId;
    }

    
    
}