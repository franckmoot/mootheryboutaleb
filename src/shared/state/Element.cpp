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

}