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
    

    Engine::Engine() {
        
    }
    
    void Engine::addCommand( Command* cmd) {
        currentCommands.push_back( unique_ptr<Command>  (cmd ) ) ;
    }
    
    
    
    void Engine::update(state::State& state) {
       
        for (int i=0;i<int(currentCommands.size());i++){

           if(currentCommands[i]->getTypeId()==LOAD){
	   LoadCommand * tmp=(LoadCommand *)&currentCommands[i];
           tmp->execute(state);
           }
           else if(currentCommands[i]->getTypeId()==MOVE){           
               MoveCharCommand * tmp=(MoveCharCommand *)&currentCommands[i];         
               tmp->execute(state);         
           }
           else if(currentCommands[i]->getTypeId()==CAPTUR){             
               CapturCharCommand * tmp=(CapturCharCommand *)&currentCommands[i];
           tmp->execute(state);
           }
           else if(currentCommands[i]->getTypeId()==ATTAQUE){      
               AttaqueCharCommand * tmp=(AttaqueCharCommand *)&currentCommands[i];
           tmp->execute(state);
           }
        }           
    }
    
        const state::State Engine::getState() const {
            return currentState;
    }

}
    
    