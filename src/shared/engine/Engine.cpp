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


using namespace std;
namespace engine{
    
    Engine::Engine() {

    }
    
    void Engine::addCommand( Command* cmd) {
        currentCommands.push_back( unique_ptr<Command>  (cmd ) ) ;
    }
    
    void Engine::update() {
       
      cout<<"dsf"<<endl;  
      //for ( auto& command : currentCommands ) {
        currentCommands[0]->execute(currentState);

      //  }
cout<<"dsdf"<<endl;  
    }
        const state::State Engine::getState() const {
            return currentState;
    }

}
    
    