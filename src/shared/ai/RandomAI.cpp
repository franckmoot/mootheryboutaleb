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
namespace ai {

    RandomAI::RandomAI() {

    }

   void RandomAI::run(state::State& state, int joueur) {
        std::vector<std::unique_ptr < engine::Command>>list;
        mt19937 mt_rand(time(0));
        int h;

        for (int j = 0; j < state.chars->getHeight();j++){
            for (int i = 0; i < state.chars->getWidth(); i++) {
                if (state.chars->getElement(i, j) != NULL) {

                    if (state.chars->getElement(i, j)->getTypeId() == 2 && state.chars->getElement(i, j)->getJoueur() == joueur) {
                        std::vector<std::unique_ptr<engine::Command> > l0;
                        InfanterieCommands(state, i, l0,j);
                        h = (int) (mt_rand() % l0.size());
                        l0[h]->execute(state);
                                
                    }   
                    else if (state.chars->getElement(i, j)->getTypeId() == 3 && state.chars->getElement(i, j)->getJoueur() == joueur) {
                    std::vector<std::unique_ptr<engine::Command> > l2;
                    HeliCommands(state, i, l2,j);
                    h = (int) (mt_rand() % l2.size());
                    l2[h]->execute(state);
                }
                    else if (state.chars->getElement(i, j)->getTypeId() == 4 && state.chars->getElement(i, j)->getJoueur() == joueur) {
                    std::vector<std::unique_ptr<engine::Command> > l3;
                    TankCommands(state, i, l3,j);
                    h = (int) (mt_rand() % l3.size());
                    l3[h]->execute(state);

                }
            }


        }
        }
        if (joueur == 1) {
            if (state.chars->getElement(2,1) == NULL && state.chars->getElement(2, 6) == NULL) {
                std::vector<std::unique_ptr<engine::Command> > l4;
                BatimentCommands(state, 1, l4);
                h = (int) (mt_rand() % l4.size());
                l4[h]->execute(state);
            }
        }
        if (joueur == 2) {
            if (state.chars->getElement(17, 14) == NULL && state.chars->getElement(18,14 ) == NULL) {
                std::vector<std::unique_ptr<engine::Command> > l5;
                BatimentCommands(state, joueur, l5);
                h = (int) (mt_rand() % l5.size());
                l5[h]->execute(state);
            }
        }

    }
}




