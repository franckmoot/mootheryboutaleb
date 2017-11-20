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
            if(j>400) j=399;
            if(j<0) j=0;
            this->i=i;
            this->j=j;
    }

        
    CommandTypeId AttaqueCharCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }
    
    
    
    void AttaqueCharCommand::execute(state::State& state) {

        if((state.chars->getElement(i,1)!=NULL) && (state.chars->getElement(j,1)!=NULL) ){
            
         if(state.chars->getElement(i,1)->getJoueur()!=state.chars->getElement(j,1)->getJoueur()){

          if(state.chars->getElement(i,1)->getTypeId()==2){
            state::Infanterie* eletmp = (state::Infanterie*)(state.chars->getElement(i,1));
                if(state.chars->getElement(j,1)->getTypeId()==2){
                    state::Infanterie* eletmp2 = (state::Infanterie*)(state.chars->getElement(j,1));
                    if(j==i+1||j==i-1||j==i+20 ||j==i-20||j==i+21||j==i-21||j==i+30 ||j==i-30){
                        eletmp2->setPdv(eletmp2->getPdv()-eletmp->getAttaque());
                        if(eletmp2->getPdv()<=0){
                          //  state.chars->killElement(j);
                            cout<<"notre element" <<j<< "est mort"<<endl;
                        }
                    }
                    else cout<<"ta portée n'est pas suffisante"<<endl;
                }
                else if(state.chars->getElement(j,1)->getTypeId()==3){
                    state::Heli* eletmp2 = (state::Heli*)(state.chars->getElement(j,1));
                    if(j==i+1||j==i-1||j==i+20 ||j==i-20||j==i+21||j==i-21||j==i+30 ||j==i-30){
                        eletmp2->setPdv(eletmp2->getPdv()-eletmp->getAttaque());
                        if(eletmp2->getPdv()<=0){
                          //  state.chars->killElement(j);
                            cout<<"notre element" <<j<< "est mort"<<endl;
                        }
                    }
                    else cout<<"ta portée n'est pas suffisante"<<endl;
                 }
                else if(state.chars->getElement(j,1)->getTypeId()==4){
                    state::Tank* eletmp2 = (state::Tank*)(state.chars->getElement(j,1));
                    if(j==i+1||j==i-1||j==i+20 ||j==i-20||j==i+21||j==i-21||j==i+30 ||j==i-30){
                        eletmp2->setPdv(eletmp2->getPdv()-eletmp->getAttaque());
                        if(eletmp2->getPdv()<=0){
                          //  state.chars->killElement(j);
                            cout<<"notre element" <<j<< "est mort"<<endl;
                        }
                    }
                    else cout<<"ta portée n'est pas suffisante"<<endl;
                }
         }
           else if(state.chars->getElement(i,1)->getTypeId()==3){
              state::Infanterie* eletmp = (state::Infanterie*)(state.chars->getElement(i,1));
                if(state.chars->getElement(j,1)->getTypeId()==2){
                    state::Infanterie* eletmp2 = (state::Infanterie*)(state.chars->getElement(j,1));
                    if(j<i+30 || j>i-30){
                        eletmp2->setPdv(eletmp2->getPdv()-eletmp->getAttaque());
                        if(eletmp2->getPdv()<=0){
                         //   state.chars->killElement(j);
                            cout<<"notre element" <<j<< "est mort"<<endl;
                        }
                    }
                     else cout<<"ta portée n'est pas suffisante"<<endl;
                }    
                else if(state.chars->getElement(j,1)->getTypeId()==3){
                    state::Heli* eletmp2 = (state::Heli*)(state.chars->getElement(j,1));
                    if(j<i+30 || j>i-30){
                        eletmp2->setPdv(eletmp2->getPdv()-eletmp->getAttaque());
                        if(eletmp2->getPdv()<=0){
                         //   state.chars->killElement(j);
                            cout<<"notre element" <<j<< "est mort"<<endl;
                        }
                    }
                     else cout<<"ta portée n'est pas suffisante"<<endl;
                } 

                else if(state.chars->getElement(j,1)->getTypeId()==4){
                    state::Tank* eletmp2 = (state::Tank*)(state.chars->getElement(j,1));
                    if(j<i+30 || j>i-30){
                        eletmp2->setPdv(eletmp2->getPdv()-eletmp->getAttaque());
                        if(eletmp2->getPdv()<=0){
                          //  state.chars->killElement(j);
                            cout<<"notre element" <<j<< "est mort"<<endl;
                        }
                    }
                     else cout<<"ta portée n'est pas suffisante"<<endl;
                }
            }
            else if(state.chars->getElement(i,1)->getTypeId()==4){
               state::Infanterie* eletmp = (state::Infanterie*)(state.chars->getElement(i,1));
                if(state.chars->getElement(j,1)->getTypeId()==2){
                    state::Infanterie* eletmp2 = (state::Infanterie*)(state.chars->getElement(j,1));
                    if(j<i+30 || j>i-30){
                        eletmp2->setPdv(eletmp2->getPdv()-eletmp->getAttaque());
                        if(eletmp2->getPdv()<=0){
                         //   state.chars->killElement(j);
                            cout<<"notre element" <<j<< "est mort"<<endl;
                        }
                    }
                     else cout<<"ta portée n'est pas suffisante"<<endl;
                } 
                else if(state.chars->getElement(j,1)->getTypeId()==3){
                    state::Heli* eletmp2 = (state::Heli*)(state.chars->getElement(j,1));
                    if(j<i+30 || j>i-30){
                        eletmp2->setPdv(eletmp2->getPdv()-eletmp->getAttaque());
                        if(eletmp2->getPdv()<=0){
                          //  state.chars->killElement(j);
                            cout<<"notre element" <<j<< "est mort"<<endl;
                        }
                    }
                     else cout<<"ta portée n'est pas suffisante"<<endl;
                } 
                else if(state.chars->getElement(j,1)->getTypeId()==4){
                    state::Tank* eletmp2 = (state::Tank*)(state.chars->getElement(j,1));
                    if(j<i+30 || j>i-30){
                        eletmp2->setPdv(eletmp2->getPdv()-eletmp->getAttaque());
                        if(eletmp2->getPdv()<=0){
                          //  state.chars->killElement(j);
                            cout<<"notre element" <<j<< "est mort"<<endl;
                        }
                    }
                     else cout<<"ta portée n'est pas suffisante"<<endl;
                } 
            }
        }
         else {cout<<"tu n'attaques pas ton ami"<<endl;}
        } 
         
        
    
   
    


}
}
    
    