#include "MobileElement.h" 

namespace state{
    MobileElement::MobileElement(){
    
    }

    int MobileElement::getAttaque() const {
        return attaque;
    }

    int MobileElement::getMouvement() const {
        return mouvement;
    }

    int MobileElement::getDefense() const {
        return defense;
    }

    int MobileElement::getPdv() const {
        return pdv;
    }

    int MobileElement::getPosition() const {
        return position;
       
    }

    void MobileElement::setAttaque(int attaque) {
        this ->attaque=attaque;
    }

    void MobileElement::setDefense(int defense) {
         this ->defense=defense;
    }

    void MobileElement::setMouvement(int mouvement) {
         this ->mouvement=mouvement;
    }

    void MobileElement::setPdv(int pdv) {
         this ->pdv=pdv;
    }

    void MobileElement::setPosition(int position) {
         this ->position=position;
    }

    MobileElement::~MobileElement() {

    }
    
    bool const MobileElement::isStatic() {
         return false;
    }
    
    
}
