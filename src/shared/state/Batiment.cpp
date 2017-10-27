#include "Batiment.h"


namespace state {
  
    /* Constructeur */
    Batiment::Batiment() {

    }

    Batiment::Batiment(BatimentTypeId id) {
        
        if (id == BatimentTypeId::CASERNE ) this->setType( BatimentTypeId::CASERNE);
        if (id == BatimentTypeId::QG ) this->setType(BatimentTypeId::QG);
                    
    }



    TypeId Batiment::getTypeId() const {
        return TypeId::BATIMENT;
    }

    
    /* Getter de capture */
    int Batiment::getCapture() const {
            return capture;
    }
    
    /* Setter de capture */
    void Batiment::setCapture(int capture) {
        this->capture=capture;
    }

    /* Differenci le champdebataille au batiment*/
    bool Batiment::isChampdebataille() const {
        return false;
    }

    
    /* Getter de BatimentTypeId */
    BatimentTypeId Batiment::getBatimentTypeId() const {
        return batimentTypeId;
    }

    
    
}