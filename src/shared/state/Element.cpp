#include "Element.h"


namespace state {

    Element::Element() {}

    Element::~Element() {}
        

    void Element::setType(int type) {
        this->type=type;
    }
    
    void Element::setTypeId(TypeId typeId) {
        this->typeId=typeId;
    }
     int Element::getJoueur() {
        return joueur;
    }

    void Element::setJoueur(int joueur) {
        this->joueur=joueur;
    }

    
}