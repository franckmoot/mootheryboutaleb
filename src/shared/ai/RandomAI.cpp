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
#include "engine/Engine.h"
#include "engine/EarnMoney.h"
#include <random>
#include <iostream>



using namespace std;
using namespace state;
using namespace engine;
namespace ai {

    RandomAI::RandomAI() {

    }

    void RandomAI::run(int joueur, engine::Engine& engine) {
        std::vector<std::unique_ptr < engine::Command>>list;
        mt19937 mt_rand(time(0));
        int h;


        for (int j = 0; j < int(engine.currentState.getChars()->getHeight()); j++) {
            for (int i = 0; i < int(engine.currentState.getChars()->getWidth()); i++) {

                if (engine.currentState.getChars()->getElement(i, j) != NULL) {
                    if (engine.currentState.getChars()->getElement(i, j)->getCommande()) {
                        engine.currentState.getChars()->getElement(i, j)->setCommande(false);
                        if (engine.currentState.getChars()->getElement(i, j)->getTypeId() == 2 && engine.currentState.getChars()->getElement(i, j)->getJoueur() == joueur) {

                            std::vector<std::unique_ptr<engine::Command> > l0;
                            InfanterieCommands(engine.currentState, i, l0, j);
                            h = (int) (mt_rand() % l0.size());
                            //l0[h]->execute(engine.currentState);
                             engine.addCommand(l0[h].release());
                            //engine.update();

                        } else if (engine.currentState.getChars()->getElement(i, j)->getTypeId() == 3 && engine.currentState.getChars()->getElement(i, j)->getJoueur() == joueur) {
                            std::vector<std::unique_ptr<engine::Command> > l2;
                            HeliCommands(engine.currentState, i, l2, j);
                            h = (int) (mt_rand() % l2.size());
                            //l2[h]->execute(engine.currentState);
                            engine.addCommand(l2[h].release());
                            // engine.update();

                        } else if (engine.currentState.getChars()->getElement(i, j)->getTypeId() == 4 && engine.currentState.getChars()->getElement(i, j)->getJoueur() == joueur) {
                            std::vector<std::unique_ptr<engine::Command> > l3;
                            TankCommands(engine.currentState, i, l3, j);
                            h = (int) (mt_rand() % l3.size());
                            //l3[h]->execute(engine.currentState);
                            engine.addCommand(l3[h].release());
                           // engine.update();

                        }
                    }
                }

            }
            
        }
        engine.update();

        for (int j = 0; j < int(engine.currentState.getChars()->getHeight()); j++) {
            for (int i = 0; i < int(engine.currentState.getChars()->getWidth()); i++) {
                if (engine.currentState.getChars()->getElement(i, j) != NULL) {
                    engine.currentState.getChars()->getElement(i, j)->setCommande(true);
                }
            }
        }
        //engine.update();

        if (joueur == 1) {

            EarnMoney *E = new EarnMoney(joueur);
            E->execute(engine.currentState);
            std::vector<std::unique_ptr<engine::Command> > l4;
            BatimentCommands(engine.currentState, 1, l4);
            h = (int) (mt_rand() % l4.size());
            //l4[h]->execute(engine.currentState);

            engine.addCommand(l4[h].release());
            //engine.update();
        }

        if (joueur == 2) {
            EarnMoney *E = new EarnMoney(joueur);
            E->execute(engine.currentState);
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




