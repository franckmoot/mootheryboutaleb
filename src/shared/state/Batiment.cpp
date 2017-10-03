#include "Batiment.h"


namespace state {
    
    /* Constructeur */
    Batiment::Batiment(BatimentTypeId id) {

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