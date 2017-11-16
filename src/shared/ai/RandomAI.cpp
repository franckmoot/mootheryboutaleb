#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"

#include "RandomAI.h"
#include "state/State.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include <random>
#include <iostream>



using namespace std;
using namespace state;
using namespace engine;
namespace ai{
    
    
    RandomAI::RandomAI(){
        
    }
    
    void RandomAI::run (state::State& state,int joueur){
        std::vector<std::unique_ptr<engine::Command>>list;
        mt19937 mt_rand(time(0));
        int h;
        for(int i=0;i<300;i++){
            if(state.chars->getElement(i,1)!=NULL){
           
               /* if(state.chars->getElement(i,1)->getTypeId()==2){
                    std::vector<std::unique_ptr<engine::Command> > l0;
                    InfanterieCommands(state,i,l0);
                    h=(int)(mt_rand() % l0.size());
                    l0[h]->execute(state);
                    
                  
                }*/  
               if(state.chars->getElement(i,1)->getTypeId()==3 ){
                    std::vector<std::unique_ptr<engine::Command> > l2;
                    HeliCommands(state,i,l2);
                    h=(int)(mt_rand() % l2.size());
                    l2[h]->execute(state);   
                       
    
                }
               else if(state.chars->getElement(i,1)->getTypeId()==4 ){
                    std::vector<std::unique_ptr<engine::Command> > l3;
                    TankCommands(state,i,l3);
                    h=(int)(mt_rand() % l3.size());
                    l3[h]->execute(state);   
                    
                }
            }
      
        /*for(int i=0;i<state.grid->sizeList();i++){
            if(state.grid->getElement(i,1)->getTypeId()==1 ){
                    for(int j=0;j<200;j++){
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::HELI,1)));
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::INFANTERIE,1)));
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::TANK,1)));
                        }
                    h=(int)(mt_rand() % list.size());
                    list[h]->execute(state);

                   }   
                /*else if(joueur==2){
                    for(int j=200;j<400;j++){
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::HELI,2)));
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::INFANTERIE,2)));
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::TANK,2)));
                        }
                    h=(int)(mt_rand() % list.size());
                    list[h]->execute(state);

                    }*/        
                              
                }
    }
}

       


    
