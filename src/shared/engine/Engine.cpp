/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Engine.h"
#include "state/State.h"
#include "state/Element.h"
#include "engine/LoadCommand.h"
#include "Command.h"
#include "CapturCharCommand.h"
#include "AttaqueCharCommand.h"
#include "CommandTypeId.h"
#include "MoveCharCommand.h"

using namespace std;
using namespace engine;
namespace engine{
    

    Engine::Engine(state::State *currentState) {
        this->currentState=currentState;
    }
    
    void Engine::addCommand( Command* cmd) {
        currentCommands.push_back( unique_ptr<Command>  (cmd ) ) ;
    }
    
    void Engine::update() {
       
        for (int i=0;i<int(currentCommands.size());i++){
            cout<<"1"<<endl;
            //Batiment* batTmp=(Batiment*)&staticTmp;
           if(currentCommands[i]->getTypeId()==LOAD){
               cout<<"2"<<endl;
	   LoadCommand * tmp=(LoadCommand *)&currentCommands[i];
           tmp->execute(currentState);
           }
           else if(currentCommands[i]->getTypeId()==MOVE){
            cout<<"3"<<endl;
               MoveCharCommand * tmp=(MoveCharCommand *)&currentCommands[i];
           cout<<"1"<<endl;
               tmp->execute(currentState);
           cout<<"1"<<endl;
           }
           else if(currentCommands[i]->getTypeId()==CAPTUR){
               cout<<"4"<<endl;
               CapturCharCommand * tmp=(CapturCharCommand *)&currentCommands[i];
           tmp->execute(currentState);
           }
           else if(currentCommands[i]->getTypeId()==ATTAQUE){
               cout<<"5"<<endl;
               AttaqueCharCommand * tmp=(AttaqueCharCommand *)&currentCommands[i];
           tmp->execute(currentState);
           }
        }           
    }
        const state::State Engine::getState() const {
            return currentState;
    }

}
    
    