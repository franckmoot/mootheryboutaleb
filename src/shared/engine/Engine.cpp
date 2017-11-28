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
#include "state/ElementTab.h"
#include "state/ElementChars.h"

using namespace std;
using namespace state;

namespace engine {

    Engine::Engine() {
        //this->currentState = new State;
        this->currentState.grid = new ElementTab();
        this->currentState.chars = new ElementChars();
        this->currentState.joueur1 =new Joueur();
        this->currentState.joueur2 = new Joueur();


    }

    void Engine::addCommand(Command* cmd) {
        currentCommands.push_back(unique_ptr<Command> (cmd));
    }

    void Engine::update() {

        for (auto& command : currentCommands) {
            
           
            command->execute(currentState);
           
        }
       
        currentCommands.clear();
     
    }

    const state::State& Engine::getState() const {
        return currentState;
    }

}

