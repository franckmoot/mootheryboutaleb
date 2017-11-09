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
    AttaqueCharCommand::AttaqueCharCommand(int i, int j) {
            this->i=i;
            this->j=j;
    }

        
    CommandTypeId AttaqueCharCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }
    
    
    
    void AttaqueCharCommand::execute(state::State& state) {

        if(state.chars->getElement(i,1)!=NULL & state.chars->getElement(j,1)!=NULL ){
            
         if(state.chars->getElement(i,1)->getjoueur()!=state.chars->getElement(j,1)->getjoueur()){

          if(state.chars->getElement(i,1)->getTypeId()==2){
            state::Infanterie* eletmp = (state::Infanterie*)(state.chars->getElement(i,1));
                if(state.chars->getElement(j,1)->getTypeId()==2){
                    state::Infanterie* eletmp2 = (state::Infanterie*)(state.chars->getElement(j,1));
                    eletmp2->setPdv(eletmp->getPdv()-eletmp2->getPdv());
                    
                }
                else if(state.chars->getElement(j,1)->getTypeId()==3){
                    state::Heli* eletmp2 = (state::Heli*)(state.chars->getElement(j,1));
                     eletmp2->setPdv(eletmp->getPdv()-eletmp2->getPdv());
                 }
                else if(state.chars->getElement(j,1)->getTypeId()==4){
                    state::Tank* eletmp2 = (state::Tank*)(state.chars->getElement(j,1));
                     eletmp2->setPdv(eletmp->getPdv()-eletmp2->getPdv());
                }
            }
           else if(state.chars->getElement(i,1)->getTypeId()==3){
              state::Infanterie* eletmp = (state::Infanterie*)(state.chars->getElement(i,1));
                if(state.chars->getElement(j,1)->getTypeId()==2){
                    state::Infanterie* eletmp2 = (state::Infanterie*)(state.chars->getElement(j,1));
                    eletmp2->setPdv(eletmp->getPdv()-eletmp2->getPdv());
                    
                }
                else if(state.chars->getElement(j,1)->getTypeId()==3){
                    state::Heli* eletmp2 = (state::Heli*)(state.chars->getElement(j,1));
                     eletmp2->setPdv(eletmp->getPdv()-eletmp2->getPdv());
                 }
                else if(state.chars->getElement(j,1)->getTypeId()==4){
                    state::Tank* eletmp2 = (state::Tank*)(state.chars->getElement(j,1));
                     eletmp2->setPdv(eletmp->getPdv()-eletmp2->getPdv());
                }
            }
            else if(state.chars->getElement(i,1)->getTypeId()==4){
               state::Infanterie* eletmp = (state::Infanterie*)(state.chars->getElement(i,1));
                if(state.chars->getElement(j,1)->getTypeId()==2){
                    state::Infanterie* eletmp2 = (state::Infanterie*)(state.chars->getElement(j,1));
                    eletmp2->setPdv(eletmp->getPdv()-eletmp2->getPdv());
                    
                }
                else if(state.chars->getElement(j,1)->getTypeId()==3){
                    state::Heli* eletmp2 = (state::Heli*)(state.chars->getElement(j,1));
                     eletmp2->setPdv(eletmp->getPdv()-eletmp2->getPdv());
                 }
                else if(state.chars->getElement(j,1)->getTypeId()==4){
                    state::Tank* eletmp2 = (state::Tank*)(state.chars->getElement(j,1));
                     eletmp2->setPdv(eletmp->getPdv()-eletmp2->getPdv());
                }
            }
        }
         else {cout<<"tu n'attaques pas ton ami"<<endl;}
        } 
         
    else{cout<<"i ou j est null"<<endl;}
        
    
   
    


}
}
    