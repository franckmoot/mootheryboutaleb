#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "MovecharCommand.h"
#include "state/State.h"
#include "state/Element.h"


using namespace std;
namespace engine{
    
    void MovecharCommand::bouger(state::State& state, int i1, int j1,int i2,int j2){
        if(state.getChars()->getElement(i2,j2)->getTypeId()>1) cout<< "c'est impossible de mettre un element mobile sur un element mobile"<<endl;
        else{
            if(state.getChars()->getElement(i1,j1)->getTypeId()==3){
                state.getChars()->chgList2(i1*j1,i2*j2);
            }
            else if (state.getChars()->getElement(i1,j1)->getTypeId()==4){
               //state.getGrid()->getElement(i2,j2)->isStatic()
            }
            
        }
        
        
    }
       
           
}
  
   
    
    
    
    
    
