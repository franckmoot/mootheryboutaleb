#include "Infanterie.h"




namespace state{
    Infanterie::Infanterie(){
        
    }

    int Infanterie::diffUnite() {
        return 0;
    }

    const TypeId Infanterie::getTypeId() {
         return TypeId(2);
        
    }

    Infanterie::~Infanterie() {

    }

}