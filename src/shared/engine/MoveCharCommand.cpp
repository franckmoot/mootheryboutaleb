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
        this->i=i;
        this->j=j;
        
    }
    
    void MoveCharCommand::execute(state::State& state){
        int i=this->i;
        int j=this->j;
      
       
        
       if(state.getChars()->getElement(j,1)!=NULL & state.getChars()->getElement(i,1)==NULL ) cout<< "c'est impossible "<<endl;
       else{

            if(state.getChars()->getElement(i,1)->getTypeId()==3){
                state.getChars()->chgList2(i,j);
            }
            else if (state.getChars()->getElement(i,1)->getTypeId()==4){
                if(state.getGrid()->getElement(j,1)->getTypeId()==0){
                    state::Champdebataille* eletmp2 = (state::Champdebataille*)(state.grid->getElement(j,1));
                    if(eletmp2->getType()==3|| eletmp2->getType()==4 ){
                        cout<< "c'est impossible de mettre un element mobile sur ces elments static"<<endl;
                    }   
                    else {
                        state.getChars()->chgList2(i,j);
                    }
                }
                else if(state.getGrid()->getElement(j,1)->getTypeId()==1){
                    cout<< "c'est impossible de mettre un element mobile sur ces elments static"<<endl;
                }
                    
             }
            else if (state.getChars()->getElement(i,1)->getTypeId()==2){
                if(state.getGrid()->getElement(j,1)->getTypeId()==0){               
                    state::Champdebataille* eletmp2 = (state::Champdebataille*)(state.grid->getElement(j,1));
                    if(eletmp2->getType()==3 ){
                        cout<< "c'est impossible de mettre un element mobile sur ces elments static"<<endl;
                    }
                    
                    else state.getChars()->chgList2(i,j);
                }
                else if(state.getGrid()->getElement(j,1)->getTypeId()==1) cout<< "c'est impossible de mettre un element mobile sur ces elments static"<<endl;
             }
                    
             }
        }
            
        
   
    
     CommandTypeId MoveCharCommand::getTypeId() const{
        return CommandTypeId::MOVE ;
         
     }  



}


  
   
    
    
    
    
    
