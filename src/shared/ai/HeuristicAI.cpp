#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"
#include "engine/CapturCharCommand.h"
#include "Direction.h"
#include "Pathmap.h"
#include "state/State.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "engine/Engine.h"
#include "engine/EarnMoney.h"
#include "state/Champdebataille.h"
#include "AI.h"
#include "HeuristicAI.h"
#include <random>
#include <iostream>
#include <engine/Engine.h>
#include "Point.h"



using namespace std;
using namespace state;
using namespace engine;

namespace ai {

    HeuristicAI::HeuristicAI() {

    }

    void HeuristicAI::setInfmap(engine::Engine& engine, int joueur) {
        this->infmap.init(*engine.currentState.grid);
        for (int j = 0; j < int(engine.currentState.getGrid()->getHeight()); j++) {
            for (int i = 0; i < int(engine.currentState.getGrid()->getWidth()); i++) {
                if ((engine.currentState.getGrid()->getElement(i, j)->getTypeId() == 1)&&(engine.currentState.getGrid()->getElement(i, j)->getJoueur() != joueur)) {
                    this->infmap.addSink(Point(i, j, 0));

                }
            }
        }
        this->infmap.update(*engine.currentState.grid);
    }

    void HeuristicAI::setHelimap(engine::Engine& engine, int joueur) {
        this->helimap.init(*engine.currentState.grid);
        for (int j = 0; j < int(engine.currentState.getGrid()->getHeight()); j++) {
            for (int i = 0; i < int(engine.currentState.getGrid()->getWidth()); i++) {
                if ((engine.currentState.getGrid()->getElement(i, j)->getTypeId() == 1)&&(engine.currentState.getGrid()->getElement(i, j)->getJoueur() != joueur)) {
                    this->helimap.addSink(Point(i, j, 0));

                }
            }
        }
        this->helimap.update(*engine.currentState.grid);
    }

    void HeuristicAI::setTankmap(engine::Engine& engine, int joueur) {
        this->tankmap.init(*engine.currentState.grid);
        for (int j = 0; j < int(engine.currentState.getGrid()->getHeight()); j++) {
            for (int i = 0; i < int(engine.currentState.getGrid()->getWidth()); i++) {
                if ((engine.currentState.getGrid()->getElement(i, j)->getTypeId() == 1)&&(engine.currentState.getGrid()->getElement(i, j)->getJoueur() != joueur)) {
                    this->tankmap.addSink(Point(i, j, 0));

                }
            }
        }
        this->tankmap.update(*engine.currentState.grid);
    }

    Pathmap& HeuristicAI::getInfmap(engine::Engine& engine, int joueur) {
        return infmap;
    }

    Pathmap& HeuristicAI::getHelimap(engine::Engine& engine, int joueur) {
        return tankmap;
    }

    Pathmap& HeuristicAI::getTankmap(engine::Engine& engine, int joueur) {
        return helimap;
    }

    void HeuristicAI::run(engine::Engine& engine, int joueur) {

        for (int j = 0; j < int(engine.currentState.getChars()->getHeight()); j++) {
            for (int i = 0; i < int(engine.currentState.getChars()->getWidth()); i++) {

                if (engine.currentState.getChars()->getElement(i, j) != NULL) {

                    if ((engine.currentState.getChars()->getElement(i, j)->getTypeId() == 2) && (engine.currentState.getChars()->getElement(i, j)->getJoueur() == joueur)) {
                        Infanterie* eletmp = (Infanterie*) (engine.currentState.getChars()->getElement(i, j));
                        //for (int x2 = (i - eletmp->getPorteeMvt()); x2 < (i + eletmp->getPorteeMvt()); x2++) {
                        //for (int y2 = (j - eletmp->getPorteeMvt()); y2 < (j + eletmp->getPorteeMvt()); y2++){
                        int x2 = 10;
                        int y2 = 10;
                        if ((engine.currentState.getGrid()->getElement(i, j)->getTypeId() == 1)&&(engine.currentState.getGrid()->getElement(i, j)->getJoueur() != joueur)) {
                            engine::CapturCharCommand *C = new CapturCharCommand(i, j);
                            C->execute(engine.currentState);
                        } else if ((x2 >= 0)&&(y2 >= 0)&&(x2<int(engine.currentState.getGrid()->getWidth()))&&(y2<int(engine.currentState.getGrid()->getHeight()))&&(engine.currentState.getChars()->getElement(x2, y2) != NULL)&&(joueur != engine.currentState.getChars()->getElement(x2, y2)->getJoueur())) {
                            engine::AttaqueCharCommand *A = new AttaqueCharCommand(i, j, x2, y2);
                            A->execute(engine.currentState);
                        } else {

                            setInfmap(engine, joueur);

                            int x3min = 100;
                            int y3min = 100;
                            for (int x3 = (i - eletmp->getPorteeMvt() + 1); x3 < (i + eletmp->getPorteeMvt() - 1); x3++) {
                                for (int y3 = (j - eletmp->getPorteeMvt() + 1); y3 < (j + eletmp->getPorteeMvt() - 1); y3++) {
                                    if ((x3 >= 0)&&(y3 >= 0)&&(x3<int(engine.currentState.getGrid()->getWidth()))&&(y3<int(engine.currentState.getGrid()->getHeight()))) {
                                        int min = 1000;

                                        if (min > getInfmap(engine, joueur).getPoidlist(x3 + y3 * 20)) {
                                            min = getInfmap(engine, joueur).getPoidlist(x3 + y3 * 20);
                                            x3min = x3;
                                            y3min = y3;
                                            //cout << x3min << endl;
                                            // cout << y3min << endl;
                                        }
                                    }
                                }
                            }
                            cout << x3min << endl;
                            cout << y3min << endl;

                            if (engine.currentState.getChars()->getElement(i, j)->getCommande()) {
                                engine.currentState.getChars()->getElement(i, j)->setCommande(false);
                                engine.addCommand(new MoveCharCommand(i, j, x3min, y3min));

                            }
                            //M->execute(engine.currentState);

                        }
                        // }               
                        // }
                    } else if (engine.currentState.getChars()->getElement(i, j)->getTypeId() == 3 && engine.currentState.getChars()->getElement(i, j)->getJoueur() == joueur) {

                    } else if (engine.currentState.getChars()->getElement(i, j)->getTypeId() == 4 && engine.currentState.getChars()->getElement(i, j)->getJoueur() == joueur) {

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
    }
}