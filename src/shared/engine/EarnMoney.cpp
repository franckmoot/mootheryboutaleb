
#include <string>
#include <iostream>
#include "state/Batiment.h"
#include "AttaqueCharCommand.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include <math.h>
#include "EarnMoney.h"
using namespace std;
using namespace state;
namespace engine {
       EarnMoney::EarnMoney( int joueur):joueur(joueur){
           
       }

        
      CommandTypeId EarnMoney::getTypeId() const {
        return CommandTypeId::EARNMONEY;
    }
    
    
    
    void EarnMoney::execute(state::State& state){
        
        int batimentgains=300;
        if(joueur==1){
          int r=0;
          for (int j = 0; j < int(state.getGrid()->getHeight());j++){
            for (int i = 0; i < int(state.getGrid()->getWidth()); i++) {
                int r=0;
                if(state.getGrid()->getElement(i,j)->getTypeId()==1){
                    state::Batiment* eletmp2 = (state::Batiment*)(state.getGrid()->getElement(i, j));
                    if ((eletmp2->getTypeId()==0)||(eletmp2->getTypeId()==1)||(eletmp2->getTypeId()==2))r=r+1;
                }
            }
          }
          state.joueur1->addMoney(r*batimentgains);
        }
          else if(joueur==2){
            int r=0;
           for (int j = 0; j < int(state.getGrid()->getHeight());j++){
            for (int i = 0; i < int(state.getGrid()->getWidth()); i++) {
                if(state.getGrid()->getElement(i,j)->getTypeId()==1){
                    state::Batiment* eletmp2 = (state::Batiment*)(state.getGrid()->getElement(i, j));
                    if ((eletmp2->getTypeId()==3)||(eletmp2->getTypeId()==4)||(eletmp2->getTypeId()==5))r=r+1;
                }
            }
          }
          state.joueur2->addMoney(r*batimentgains);
        }
          
        
    
    
    
}
}