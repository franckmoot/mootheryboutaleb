#include <string>
#include <iostream>
#include "AttaqueCharCommand.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"

using namespace std;
using namespace state;
namespace engine{
        
    CommandTypeId AttaqueCharCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }
    
    
    
    void AttaqueCharCommand::execute(state::State& state) {

        if((state.chars->getElement(i,1)!=NULL)&&(state.chars->getElement(j,1)!=NULL)){
         if((!state.chars->getElement(i,1)->isStatic())&&!state.chars->getElement(j,1)->isStatic()){
          
            
	  state::Infanterie* infanterieTmpj = (state::Infanterie*)(state.chars->getElement(j,1));
	 
                //= (state::MobileElement*)&(state.chars->getElement(i,1));
                //state::MobileElement* mobileTmpj = (state::MobileElement*)&(state.chars->getElement(j,1));
                
         }else{
             
             cout<<"i ou j n'est pas mobileELement"<<endl;
         }
        
    }else{
             cout<<"i ou j est null"<<endl;
             
    }
         
    
    }
    


}
    