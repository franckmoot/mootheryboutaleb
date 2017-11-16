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
    
   void AI::InfanterieCommands(const state::State& state, int i, std::vector<std::unique_ptr<engine::Command> >& list){
                if(i>360) i=360;
                if(i<0) i=0;
                
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
    
    
    void AI::HeliCommands(const state::State& state, int i, std::vector<std::unique_ptr<engine::Command> >& list1){
                    for(int j=i-80;j<i+80;j++){
                       if(j>400) j=400 ;
                       if(j<0) j=0;
                       if(state.chars->getElement(j,1)!=NULL && state.chars->getElement(j,1)->getJoueur()!=state.chars->getElement(j,1)->getJoueur()){
                       list1.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,j)));
                    }
                       list1.push_back(unique_ptr<Command>(new MoveCharCommand(i,j)));
                    }
        
        
        
    }
    void AI::TankCommands(const state::State& state, int i, std::vector<std::unique_ptr<engine::Command> >& list2){
                    for(int j=i-60;j<i+60;j++){
                       if(j>400) j=400 ;
                       if(j<0) j=0;
                       if(state.chars->getElement(j,1)!=NULL){
                       list2.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,j)));
                    }
                       list2.push_back(unique_ptr<Command>(new MoveCharCommand(i,j)));
                    }
        
        
        
    }
}