#include <string>
#include <iostream>
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/Batiment.h"
#include "CreateCharCommand.h"
#include "state/TypeId.h"



using namespace std;
using namespace state;
namespace engine{
    CreateCharCommand::CreateCharCommand(int i,state::TypeId d) {
            this->i=i;
            this->d=d;
    }

        
    CommandTypeId CreateCharCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }
    
    
    
    void CreateCharCommand::execute(state::State& state) {
        if(d==2){
         Infanterie *I=new Infanterie(); 
         state.chars->setElement(I);
         state.chars->chgList(i,I);
        }
        if(d==3){
            Heli *H=new Heli();
         state.chars->setElement(H);
         state.chars->chgList(i,H);
        
        }
        if(d==4){
            Tank *T=new Tank();
         state.chars->setElement(T);
         state.chars->chgList(i,T);
        
        }
    }

        
        
        
        
        
        
}