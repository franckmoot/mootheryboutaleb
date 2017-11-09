#include "Heli.h"



namespace state{
    Heli::Heli() {
        this->pdv=30;
        this->attaque=30;
    
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