#include "Champdebataille.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

namespace state {

    Champdebataille::Champdebataille() {

    }
    
    Champdebataille::Champdebataille(ChampdebatailleTypeId id) {
        //std::cout<<"AVANT : le type est "<<id<<std::endl;
        
        switch (id){
	  
	case EAU:
	  this->setType( EAU );;
	  break;
	  
	case HERBE:     
	  this->setType( HERBE );
	  break;
	  
	case ROCHER:
	  this->setType( ROCHER );
	  break;
          
	case ROUTE:
	  this->setType( ROUTE );
	  break;
          
	case SABLE:
	  this->setType( SABLE );
	  break;
          
        }
        //std::cout<<"APRES : le type est "<<id<<std::endl;
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