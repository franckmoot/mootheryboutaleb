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
        /*if (joueur == 1) {
            if (state.chars->getElement(22, 1) == NULL && state.chars->getElement(26, 1) == NULL) {
                        std::vector<std::unique_ptr<engine::Command> > l4;
                        BatimentCommands(state, 1, l4);
                        h = (int) (mt_rand() % l4.size());
                        l4[h]->execute(state);
                    }
                }
        if (joueur == 2) {
            if (state.chars->getElement(374, 1) == NULL &&  state.chars->getElement(375, 1) == NULL) {
                        std::vector<std::unique_ptr<engine::Command> > l5;
                        BatimentCommands(state, joueur, l5);
                        h = (int) (mt_rand() % l5.size());
                        l5[h]->execute(state);
                    }
                }
*/
        for (int i = 0; i < 400; i++) {
            if (state.chars->getElement(i, 1) != NULL) {

                if (state.chars->getElement(i, 1)->getTypeId() == 2) {
                    std::vector<std::unique_ptr<engine::Command> > l0;
                    InfanterieCommands(state, i, l0);
                    h = (int) (mt_rand() % l0.size());
                    l0[h]->execute(state);

                }
                if (state.chars->getElement(i, 1)->getTypeId() == 3) {
                    std::vector<std::unique_ptr<engine::Command> > l2;
                    HeliCommands(state, i, l2);
                    h = (int) (mt_rand() % l2.size());
                    l2[h]->execute(state);
                } else if (state.chars->getElement(i, 1)->getTypeId() == 4) {
                    std::vector<std::unique_ptr<engine::Command> > l3;
                    TankCommands(state, i, l3);
                    h = (int) (mt_rand() % l3.size());
                    l3[h]->execute(state);

                }
            }
        }

        /* else if(state.grid->getElement(i,1)->getTypeId()==1){
            /* if(state.chars->getElement(i,1)==NULL){
                     std::vector<std::unique_ptr<engine::Command> > l4;
                     BatimentCommands(state,joueur,l4);
                     h=(int)(mt_rand() % l4.size());
                     l4[h]->execute(state);                 

                }                 
         }*/
    }
}





