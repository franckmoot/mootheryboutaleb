#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/MoveCharCommand.h"

#include "AI.h"
#include "state/State.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"



using namespace std;
using namespace state;
using namespace engine;
namespace ai{
    
    void AI::listCommands (std::vector<std::unique_ptr<engine::Command> > &list, const state::State& state ,int caractere){
     
        
        for(int i=0;i<state.chars->sizeList();i++){
            if(state.chars->getElement(i,1)->getTypeId()==2){
                list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,i+1)));
                list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,i-1)));
                list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,i+20)));
                list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,i+21)));
                list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,i-21)));
                list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,i-20)));
                list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,i-40)));
                list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,i+40)));
                list.push_back(unique_ptr<Command>(new MoveCharCommand(i,i+1)));
                list.push_back(unique_ptr<Command>(new MoveCharCommand(i,i-1)));
                list.push_back(unique_ptr<Command>(new MoveCharCommand(i,i+20)));
                list.push_back(unique_ptr<Command>(new MoveCharCommand(i,i+21)));
                list.push_back(unique_ptr<Command>(new MoveCharCommand(i,i-21)));
                list.push_back(unique_ptr<Command>(new MoveCharCommand(i,i-20)));
                list.push_back(unique_ptr<Command>(new MoveCharCommand(i,i-40)));
                list.push_back(unique_ptr<Command>(new MoveCharCommand(i,i+40)));
                
                
            }
                
            else if(state.chars->getElement(i,1)->getTypeId()==3){
                   for(int j=i-80;j<i+80;j++){
                       if(j>400) j=200 ;
                       if(j<0) j=0;
                       list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,j)));
                       list.push_back(unique_ptr<Command>(new MoveCharCommand(i,j)));    
               }
            }
            else if(state.chars->getElement(i,1)->getTypeId()==4){
                   for(int j=i-60;j<i+60;j++){
                       if(j>400) j=200 ;
                       if(j<0) j=0;
                       list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,j)));
                       list.push_back(unique_ptr<Command>(new MoveCharCommand(i,j)));    
               }
            }
        
        
   }
    
    
    
    
    
    
}
 
}    
