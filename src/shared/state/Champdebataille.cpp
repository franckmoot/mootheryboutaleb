#include "Champdebataille.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
namespace state {

    Champdebataille::Champdebataille() {

    }
    
    Champdebataille::Champdebataille(ChampdebatailleTypeId id) {
        //std::cout<<"AVANT : le type est "<<id<<std::endl;
        if (id == ChampdebatailleTypeId::EAU ) {
            champdeBatailleType=ChampdebatailleTypeId::EAU;
            //cout<<"JE CREER UNE EAU ET batimentTYpeID EST "<<endl;
            
        }
        if (id == ChampdebatailleTypeId::HERBE ) {
            champdeBatailleType=ChampdebatailleTypeId::HERBE;
           // cout<<"JE CREER UN HERBE ET batimentTYpeID EST :"<<endl;

        }
        
        if (id == ChampdebatailleTypeId::MONTAGNE ) {
            champdeBatailleType=ChampdebatailleTypeId::MONTAGNE;
           // cout<<"JE CREER UN MONTAGE ET batimentTYpeID EST :"<<endl;

        }
        if (id == ChampdebatailleTypeId::ROUTE ) {
            champdeBatailleType=ChampdebatailleTypeId::ROUTE;
           // cout<<"JE CREER UN ROUTE ET batimentTYpeID EST :"<<endl;

        }
        if (id == ChampdebatailleTypeId::SABLE1 ) {
            champdeBatailleType=ChampdebatailleTypeId::SABLE1;
           // cout<<"JE CREER UN SABLE1 ET batimentTYpeID EST :"<<endl;

        }
        if (id == ChampdebatailleTypeId::SABLE2 ) {
            champdeBatailleType=ChampdebatailleTypeId::SABLE2;
           // cout<<"JE CREER UN SABLE2 ET batimentTYpeID EST :"<<endl;

        }
    }

    Champdebataille::~Champdebataille() {

    }


    
   ChampdebatailleTypeId Champdebataille::getChampdeBatailleType() const {
        return champdeBatailleType;
    }


    bool Champdebataille::isChampdebataille() const {
        return true;
    }

    TypeId Champdebataille::getTypeId() const {
           return TypeId::CHAMPSDEBATAILLE;
    }
    
    
    
}