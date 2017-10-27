#include "Tank.h"



namespace state{
    Tank::Tank(){
    
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