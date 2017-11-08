#include "Element.h"


namespace state {

    Element::Element() {}

    Element::~Element() {}
        
    int Element::getType() {
        return type;
    }

    void Element::setType(int type) {
        this->type=type;
    }
    
    void Element::setTypeId(TypeId typeId) {
        this->typeId=typeId;
    }
     int Element::getjoueur() {
        return joueur;
    }

    void Element::setjoueur(int joueur) {
        this->joueur=joueur;
    }

    
}