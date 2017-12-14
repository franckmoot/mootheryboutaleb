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
#include <stack>
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
        this->currentState.joueur1 = new Joueur();
        this->currentState.joueur2 = new Joueur();





    }

    void Engine::addCommand(Command* cmd) {
        currentCommands.push_back(unique_ptr<Command> (cmd));
    }

    std::stack<std::shared_ptr<Action>> Engine::update() {

        std::stack<std::shared_ptr<Action> > actions;

        for (auto& command : currentCommands) {


            command->execute(actions, currentState);
        }
        currentCommands.clear();
        return actions;

    }

    void Engine::updaterecord() {
        Json::Value H;

        std::stack<std::shared_ptr<Action> > actions;
        for (auto& command : currentCommands) {
            Json::Value a;
            command->serialise(a);
            H.append(a);

            command->execute(actions, currentState);
        }
        record.append(H);
        currentCommands.clear();



    }

    void Engine::undo(std::stack<std::shared_ptr<Action> >& actions) {

        while (!actions.empty()) {
            actions.top()->undo(currentState);
            actions.pop();
        }

    }

    const state::State& Engine::getState() const {
        return currentState;
    }

    void Engine::run() {
        while (1) {
            lockEngine.lock();
            this->update();
            lockEngine.unlock();
        }
    }


}
