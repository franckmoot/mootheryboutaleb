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

    int DeepAI::max(engine::Engine& engine, int joueur, int profondeur) {
        
        if (profondeur == 0) {
            return engine.currentState.getscore(joueur);
        } else {
            for (int y = 0; y < int(engine.currentState.getChars()->getHeight()); y++) {
                for (int x = 0; x < int(engine.currentState.getChars()->getWidth()); x++) {
                    if ((engine.currentState.getChars()->getElement(x, y)->getTypeId() == 2)&&(engine.currentState.getChars()->getElement(x, y)->getJoueur() == joueur)) {
                        std::vector<std::unique_ptr<engine::Command> > l0;
                        InfanterieCommands(engine.currentState, x, l0, y);
                        int maxi = 0;
                        int l;
                        for (int i = 0; i < l0.size(); i++) {
                            //l0[i]->execute(engine.currentState);
                            engine.addCommand(l0[i].release());
                            engine.update();
                            int tmp = max(engine, joueur, profondeur - 1);
                            if (tmp > maxi){
                                max = tmp;
                                l=i;
                            }
                            //engine.undo();
                        }
                        engine.addCommand(l0[l].release());
                        engine.update();
                    }
                }
            }
        }
    }


    void DeepAI::run(int joueur, engine::Engine& engine) {

    }


}