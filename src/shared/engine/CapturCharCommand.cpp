#include <string>
#include <iostream>
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/Batiment.h"
#include "CapturCharCommand.h"

using namespace std;
namespace engine{
    
        CommandTypeId CapturCharCommand::getTypeId() const {
        return CommandTypeId::CAPTUR;
    }

    CapturCharCommand::CapturCharCommand(int i){
            this->i=i;
    }
    
    void CapturCharCommand::execute(state::State& state) {
        int i=this->i;
        if(state.grid->getElement(i,1)->getTypeId()==1){
            if((state.chars->getElement(i,1)->getTypeId()==2) ||(state.chars->getElement(i,1)->getTypeId()==3) || (state.chars->getElement(i,1)->getTypeId()==4)){
                state::Batiment* eletmp2= (state::Batiment*)(state.grid->getElement(i,1));
                eletmp2->setPdv(eletmp2->getPdv()-10);
                if(eletmp2->getPdv()<=0){
                      cout<<"notre Batiment a été capturé"<<endl;
                      
                }
            }
            
            
        }

    }
    

        
        
    }

    
    