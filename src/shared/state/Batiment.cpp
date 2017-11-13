#include "Batiment.h"
#include <iostream>

using namespace std;

namespace state {
  
    /* Constructeur */
    Batiment::Batiment() {
        this->pdv=50;
    }

    Batiment::Batiment(BatimentTypeId id) {
        
        if (id == BatimentTypeId::CASERNE ) {
            batimentTypeId=BatimentTypeId::CASERNE;
            cout<<"JE CREER UNE CASERNE ET batimentTYpeID EST "<<endl;
            
        }
        if (id == BatimentTypeId::QG ) {
            batimentTypeId=BatimentTypeId::QG;
            cout<<"JE CREER UN QG ET batimentTYpeID EST :"<<endl;

        }
              
    }

    TypeId Batiment::getTypeId() const {
        return TypeId::BATIMENT;
    }

    
    /* Getter de capture */
    int Batiment::getCapture() const {
            return capture;
    }
    
    /* Setter de capture */
    void Batiment::setCapture(int capture) {
        this->capture=capture;
    }

    /* Differenci le champdebataille au batiment*/
    bool Batiment::isChampdebataille() const {
        return false;
    }

    
    /* Getter de BatimentTypeId */
    BatimentTypeId Batiment::getBatimentTypeId() const {
        return batimentTypeId;
    }
     int Batiment::getPdv() const {
        return pdv;
    }
        void Batiment::setPdv(int pdv) {
         this ->pdv=pdv;
    }
    
}