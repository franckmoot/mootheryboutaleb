#include "Champdebataille.h"


namespace state {

    /* Constructeur */
    Champdebataille::Champdebataille(ChampdebatailleTypeId id) {
    }
    
    /* Destructeur */
    Champdebataille::~Champdebataille() {
    }

   /* Defini si c'est un static ou un mobile*/
    const bool Champdebataille::isStatic() {
        if (this == Champdebataille) return true;
        else return false;
    }

    /* Differencie si c'est un batiment avec interaction ou non  */
    const int Champdebataille::diffMap() {
        if(this == Champdebataille) return true;
        else return false;
    }
            
}