#include <string>
#include <iostream>
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/Batiment.h"
#include "CapturCharCommand.h"

using namespace std;
using namespace state;

namespace engine {

    CommandTypeId CapturCharCommand::getTypeId() const {
        return CommandTypeId::CAPTUR;
    }

    CapturCharCommand::CapturCharCommand(int x, int y) : x(x), y(y) {

    }
    

    
    void CapturCharCommand::execute(std::stack<std::shared_ptr<Action> >& actions,state::State& state) {
        if (state.grid->getElement(x, y)->getTypeId() == 1) {
            if ((state.chars->getElement(x, y)->getTypeId() == 2)) {
                if (state.chars->getElement(x, y)->getJoueur() != state.grid->getElement(x, y)->getJoueur()) {
                    state::Batiment* eletmp2 = (state::Batiment*)(state.grid->getElement(x, y));
                    eletmp2->setPdv(eletmp2->getPdv() - 10);
                    if (eletmp2->getPdv() <= 0) {
                        state::BatimentTypeId typebatiment = eletmp2->getBatimentTypeId();
                        state.grid->killElement(x, y);
                        if(typebatiment==state::QGBLEU) {
                            state.grid->setElementXY(new state::Batiment(QGROUGE), x, y);
                            state.grid->getElement(x,y)->setJoueur(1);
                        }
                        else if(typebatiment==state::QGROUGE) {
                            state.grid->setElementXY(new state::Batiment(QGBLEU), x, y);
                            state.grid->getElement(x,y)->setJoueur(2);
                        }
                        else if(typebatiment==state::CASERNEBLEU){
                            state.grid->setElementXY(new state::Batiment(CASERNEROUGE), x, y);
                            state.grid->getElement(x,y)->setJoueur(1);
                        }
                        else if(typebatiment==state::CASERNEROUGE){
                            state.grid->setElementXY(new state::Batiment(CASERNEBLEU), x, y);
                            state.grid->getElement(x,y)->setJoueur(2);
                        }
                        else if(typebatiment==state::APPARTBLEU){
                            state.grid->setElementXY(new state::Batiment(APPARTROUGE), x, y);
                            state.grid->getElement(x,y)->setJoueur(1);
                        }
                        else if(typebatiment==state::APPARTROUGE){
                            state.grid->setElementXY(new state::Batiment(APPARTBLEU), x, y);
                            state.grid->getElement(x,y)->setJoueur(2);
                        }
                    }
                }
            }


        }

    }




}


