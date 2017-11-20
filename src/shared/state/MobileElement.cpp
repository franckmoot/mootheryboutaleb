#include "MobileElement.h" 

namespace state{
    MobileElement::MobileElement(){
    
    }

    int MobileElement::getAttaque() const {
        return attaque;
    }

    int MobileElement::getDefense() const {
        return defense;
    }

    int MobileElement::getPdv() const {
        return pdv;
    }
    
    int MobileElement::getPorteeAtq() const {
        return porteeAtq;
    }
        
    int MobileElement::getPorteeMvt() const {
        return porteeMvt;
    }

    void MobileElement::setPorteeAtq(int porteeAtq) {
        this->porteeAtq=porteeAtq;
    }
    
    void MobileElement::setPorteeMvt(int porteeMvt) {
        this->porteeMvt=porteeMvt;
    }

    void MobileElement::setAttaque(int attaque) {
        this ->attaque=attaque;
    }

    void MobileElement::setDefense(int defense) {
         this ->defense=defense;
    }

    void MobileElement::setPdv(int pdv) {
         this ->pdv=pdv;
    }

    MobileElement::~MobileElement() {
    }
    
    bool MobileElement::isStatic() const {
        return false;
    }

}
