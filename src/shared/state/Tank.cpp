#include "Tank.h"



namespace state{
    Tank::Tank(){
    
    }

    int Tank::diffUnite() {
        return 2;
    }

    const TypeId Tank::getTypeId() {
        return TypeId(4);

    }

    Tank::~Tank() {

    }

}