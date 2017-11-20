#include <iostream>
#include <string>
#include <vector>

#include "state/Element.h"
#include "state/State.h"
#include "MoveCharCommand.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/Champdebataille.h"
#include "state/Batiment.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/ChampdebatailleTypeId.h"
#include "state/BatimentTypeId.h"

using namespace std;
using namespace state;
namespace engine{
    
    
    MoveCharCommand::MoveCharCommand(int i, int j){
        if(j>400) j=399;
        if(j<0) j=0;
        this->i=i;
        this->j=j;
        
    }
    
    void MoveCharCommand::execute(state::State& state){
        int i=this->i;
        int j=this->j;
      
       
        
       if((state.getChars()->getElement(j,1)!=NULL) && (state.getChars()->getElement(i,1)==NULL) ) cout<< "c'est impossible "<<endl;
       else{

            if(state.getChars()->getElement(i,1)->getTypeId()==3){
                if(j<i+40||j>i-40){
                 //   state.getChars()->chgList2(i,j);
                }

            }
            else if (state.getChars()->getElement(i,1)->getTypeId()==4){
                if(state.getGrid()->getElement(j,1)->getTypeId()==0){
                    state::Champdebataille* eletmp2 = (state::Champdebataille*)(state.grid->getElement(j,1));
                    if(eletmp2->getChampdeBatailleType()==4 || eletmp2->getChampdeBatailleType()==5 ){
                        cout<< "c'est impossible de mettre un element mobile sur cet elment statique"<<endl;
                    }   
                    else {
                        if(j<i+30||j>i-30){
                       //     state.getChars()->chgList2(i,j);
                        }
                        else cout<<"c est impossible pour un Tank de partir plus loin"<<endl;
                     }
                }
                else if(state.getGrid()->getElement(j,1)->getTypeId()==1){
                        if(j<i+30||j>i-30){
                       //     state.getChars()->chgList2(i,j);
                        }
                    
                }
            }       
            else if (state.getChars()->getElement(i,1)->getTypeId()==2){
                if(state.getGrid()->getElement(j,1)->getTypeId()==0){               
                    state::Champdebataille* eletmp2 = (state::Champdebataille*)(state.grid->getElement(j,1));
                    if(eletmp2->getChampdeBatailleType()==4 ){
                        cout<< "c'est impossible de mettre un element mobile sur cet elment statique"<<endl;
                    }
                    
                    else {
                        if(j==i+1||j==i-1||j==i+21||j==i-21||j==i+20 ||j==i-20||j==i+30 ||j==i-30){
                      //      state.getChars()->chgList2(i,j);
                        }
                        else cout<<"c est impossible pour une infanterie de partir plus loin"<<endl;
                     }
                }    
                else if(state.getGrid()->getElement(j,1)->getTypeId()==1){
                        if(j==i+1||j==i-1||j==i+21||j==i-21||j==i+20 ||j==i-20||j==i+30 ||j==i-30){
                    //        state.getChars()->chgList2(i,j);
                        }
                }
            }
       }
                    
     }
 
            
        
   
    
     CommandTypeId MoveCharCommand::getTypeId() const{
        return CommandTypeId::MOVE ;
         
     }  



}


  
   
    
    
    
    
    
