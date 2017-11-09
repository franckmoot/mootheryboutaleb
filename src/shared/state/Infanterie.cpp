#include "Infanterie.h"




namespace state{
    Infanterie::Infanterie(){
        this->pdv=10;
        this->attaque=10;
        this->mouvement=1;
        this->joueur;
        
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