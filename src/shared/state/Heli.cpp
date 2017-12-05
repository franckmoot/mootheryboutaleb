#include "Heli.h"



namespace state{
    Heli::Heli() {
        this->pdv=40;
        this->attaque=20;
        this->porteeMvt=4;
        this->porteeAtq=4;
    
    }

    
    

    TypeId Heli::getTypeId() const {
        return TypeId(3);
    }

     
    Heli::~Heli() {

    }
 
     int Heli::diffUnite() {
         return 1;
    }
     


 


}