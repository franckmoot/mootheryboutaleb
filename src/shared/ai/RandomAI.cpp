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
        std::vector<std::unique_ptr<engine::Command> > list;
        mt19937 mt_rand(time(0));
        int h;
        
        
        /*for(int i=0;i<state.chars->sizeList();i++){
            if(state.chars->getElement(i,1)!=NULL){
            if(state.chars->getElement(i,1)->getTypeId()==2 && state.chars->getElement(i,1)->getJoueur()==joueur){
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
                
                h=(int)(mt_rand() % list.size());
                list[h]->execute(state);
                  
            }
                
            else if(state.chars->getElement(i,1)->getTypeId()==3 && state.chars->getElement(i,1)->getJoueur()==joueur){
                   for(int j=i-80;j<i+80;j++){
                       if(j>400) j=200 ;
                       if(j<0) j=0;
                       list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,j)));
                       list.push_back(unique_ptr<Command>(new MoveCharCommand(i,j)));
                       
                    }
                h=(int)(mt_rand() % list.size());
                list[h]->execute(state);       
            }
            else if(state.chars->getElement(i,1)->getTypeId()==4 && state.chars->getElement(i,1)->getJoueur()==joueur){
                   for(int j=i-60;j<i+60;j++){
                       if(j>400) j=200 ;
                       if(j<0) j=0;
                       list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i,j)));
                       list.push_back(unique_ptr<Command>(new MoveCharCommand(i,j)));    
                    }
                h=(int)(mt_rand() % list.size());
                list[h]->execute(state);   
            }
            }
        
        }
        for(int i=0;i<state.grid->sizeList();i++){
        for(int i=0;i<state.grid->sizeList();i++){
            if(state.grid->getElement(i,1)->getTypeId()==1 && state.chars->getElement(i,1)->getJoueur()==joueur){
                if(joueur==1){
                    for(int j=0;j<200;j++){
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::HELI,1)));
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::INFANTERIE,1)));
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::TANK,1)));
                        }
                    h=(int)(mt_rand() % list.size());
                    list[h]->execute(state);

                   }   
                else if(joueur==2){
                    for(int j=200;j<400;j++){
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::HELI,2)));
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::INFANTERIE,2)));
                            list.push_back(unique_ptr<Command>(new CreateCharCommand(j,state::TypeId::TANK,2)));
                        }
                    h=(int)(mt_rand() % list.size());
                    list[h]->execute(state);

                    }        
                }                
                   
        }
        }}*/
 
} 