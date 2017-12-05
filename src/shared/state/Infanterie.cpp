#include "Infanterie.h"




namespace state{
    Infanterie::Infanterie(){
        this->pdv=20;
        this->attaque=10;
        this->porteeMvt=3;
        this->porteeAtq=2;
        
    }
    

    int Infanterie::diffUnite() {
        return 0;
    }
    
    TypeId Infanterie::getTypeId() const {
        return TypeId(2);
    }


    Infanterie::~Infanterie() {

    }

}