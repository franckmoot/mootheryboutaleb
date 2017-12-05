#include "Tank.h"



namespace state{
    Tank::Tank(){
         this->pdv=40;
        this->attaque=15;
        this->porteeMvt=4;
        this->porteeAtq=5;
    }

    int Tank::diffUnite() {
        return 2;
    }
  

    TypeId Tank::getTypeId() const {
        return TypeId(4);
    }


    Tank::~Tank() {

    }

}