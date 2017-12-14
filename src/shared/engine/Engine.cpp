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
#include "MoveCharCommand.h"
#include "AttaqueCharCommand.h"
#include "CapturCharCommand.h"
#include "CreateCharCommand.h"
#include "EarnMoney.h"

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

    void Engine::updatePlay(Json::Value& obj) {
        std::stack<std::shared_ptr<Action> > actions;
        for (int i = 0; i < (int) obj.size(); i++) {
                    
            if (obj[i]["type"].asString() == "Move") {
                MoveCharCommand *move = new MoveCharCommand(0, 0, 0, 0);
                move->deserialise(obj[i])->execute(actions, currentState);
            }
            else if (obj[i]["type"].asString() == "Attaque") {
                AttaqueCharCommand *attaque = new AttaqueCharCommand(0, 0, 0, 0);
                attaque->deserialise(obj[i])->execute(actions, currentState);
            }
            else if (obj[i]["type"].asString() == "Capture") {
                CapturCharCommand *capture = new CapturCharCommand(0, 0);
                capture->deserialise(obj[i])->execute(actions, currentState);
            }
            else if (obj[i]["type"].asString() == "Create") {
                CreateCharCommand *create = new CreateCharCommand((state::TypeId)0, 0, 0, 0);
                create->deserialise(obj[i])->execute(actions, currentState);
            }
            else if (obj[i]["type"].asString() == "EarnMoney") {
                EarnMoney *earn = new EarnMoney(0);
                earn->deserialise(obj[i])->execute(actions, currentState);
            }

        }

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
