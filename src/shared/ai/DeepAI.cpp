#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"
#include "DeepAI.h"
#include "AI.h"
#include "RandomAI.h"
#include "state/State.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "engine/Engine.h"
#include "engine/EarnMoney.h"
#include <random>
#include <iostream>



using namespace std;
using namespace state;
using namespace engine;
namespace ai {

    DeepAI::DeepAI() {

    }

    int DeepAI::max(engine::Engine& engine, int joueur, int profondeur, int x, int y) {
        int joueur2;
        if (joueur == 1) joueur2 = 2;
        else if (joueur == 2) joueur2 = 1;


        if (profondeur == 0) {
            return engine.currentState.getscore(joueur2);
        } else {
            if ((engine.currentState.getChars()->getElement(x, y)->getTypeId() == 2)&&(engine.currentState.getChars()->getElement(x, y)->getJoueur() == joueur)) {
                state::Infanterie* eletmp = (state::Infanterie*)(engine.currentState.getChars()->getElement(x, y));
                std::vector<std::unique_ptr<engine::Command> > l0;
                InfanterieCommands(engine.currentState, x, l0, y);
                int mini = 1000;
                int l;
                for (int i = 0; i < l0.size(); i++) {
                    std::vector<std::stack < std::shared_ptr<Action> >> actions;
                    //l0[i]->execute(engine.currentState);
                    engine.addCommand(l0[i].release());
                    actions.push_back(engine.update());
                    int tmp = max(engine, joueur, profondeur - 1,eletmp->getX(),eletmp->getY());
                    if (tmp < mini) {
                        mini = tmp;
                        l = i;
                    }

                    //engine.undo();
                    engine.undo(actions.back());
                    actions.pop_back();
                }
                engine.addCommand(l0[l].release());
                engine.update();
            }
            else if ((engine.currentState.getChars()->getElement(x, y)->getTypeId() == 3)&&(engine.currentState.getChars()->getElement(x, y)->getJoueur() == joueur)) {
                state::Heli* eletmp = (state::Heli*)(engine.currentState.getChars()->getElement(x, y));
                std::vector<std::unique_ptr<engine::Command> > l0;
                HeliCommands(engine.currentState, x, l0, y);
                int mini = 1000;
                int l;
                for (int i = 0; i < l0.size(); i++) {
                    std::vector<std::stack < std::shared_ptr<Action> >> actions;
                    //l0[i]->execute(engine.currentState);
                    engine.addCommand(l0[i].release());
                    actions.push_back(engine.update());
                    int tmp = max(engine, joueur, profondeur - 1,eletmp->getX(),eletmp->getY());
                    if (tmp < mini) {
                        mini = tmp;
                        l = i;
                    }

                    //engine.undo();
                    engine.undo(actions.back());
                    actions.pop_back();
                }
                engine.addCommand(l0[l].release());
                engine.update();
            }
            else if ((engine.currentState.getChars()->getElement(x, y)->getTypeId() == 4)&&(engine.currentState.getChars()->getElement(x, y)->getJoueur() == joueur)) {
                state::Tank* eletmp = (state::Tank*)(engine.currentState.getChars()->getElement(x, y));
                std::vector<std::unique_ptr<engine::Command> > l0;
                TankCommands(engine.currentState, x, l0, y);
                int mini = 1000;
                int l;
                for (int i = 0; i < l0.size(); i++) {
                    std::vector<std::stack < std::shared_ptr<Action> >> actions;
                    //l0[i]->execute(engine.currentState);
                    engine.addCommand(l0[i].release());
                    actions.push_back(engine.update());
                    int tmp = max(engine, joueur, profondeur - 1,eletmp->getX(),eletmp->getY());
                    if (tmp < mini) {
                        mini = tmp;
                        l = i;
                    }

                    //engine.undo();
                    engine.undo(actions.back());
                    actions.pop_back();
                }
                engine.addCommand(l0[l].release());
                
            }
        }

}

void DeepAI::run(int joueur, engine::Engine& engine,int profondeur) {
        std::vector<std::unique_ptr < engine::Command>>list;
        mt19937 mt_rand(time(0));
        std::stack<std::shared_ptr<Action> > actions;
        int h;


        for (int j = 0; j < int(engine.currentState.getChars()->getHeight()); j++) {
            for (int i = 0; i < int(engine.currentState.getChars()->getWidth()); i++) {

                if (engine.currentState.getChars()->getElement(i, j) != NULL) {

                        max(engine,joueur,profondeur,i,j);


                        }
                    }
                }

        //engine.update();

        if (joueur == 1) {

            EarnMoney *E = new EarnMoney(joueur);
            E->execute(actions,engine.currentState);
            std::vector<std::unique_ptr<engine::Command> > l4;
            BatimentCommands(engine.currentState, 1, l4);
            h = (int) (mt_rand() % l4.size());
            //l4[h]->execute(engine.currentState);

            engine.addCommand(l4[h].release());
            //engine.update();
        }

        if (joueur == 2) {
            EarnMoney *E = new EarnMoney(joueur);
            E->execute(actions,engine.currentState);
            std::vector<std::unique_ptr<engine::Command> > l4;
            BatimentCommands(engine.currentState, joueur, l4);
            h = (int) (mt_rand() % l4.size());
            //l4[h]->execute(engine.currentState);

            engine.addCommand(l4[h].release());
            //engine.update();
        }
        engine.update();
    }
}


