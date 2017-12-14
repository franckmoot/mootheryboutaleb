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
#include "CapturQGAction.h"
#include "CapturCaserneAction.h"
#include "CapturAppartAction.h"

using namespace std;
using namespace state;

namespace engine {

    CommandTypeId CapturCharCommand::getTypeId() const {
        return CommandTypeId::CAPTUR;
    }

    CapturCharCommand::CapturCharCommand(int x, int y) : x(x), y(y) {

    }

    void CapturCharCommand::execute(std::stack<std::shared_ptr<Action> >& actions, state::State& state) {
        if (state.grid->getElement(x, y)->getTypeId() == 1) {
            if ((state.chars->getElement(x, y)->getTypeId() == 2)) {
                if (state.chars->getElement(x, y)->getJoueur() != state.grid->getElement(x, y)->getJoueur()) {
                    state::Batiment* eletmp2 = (state::Batiment*)(state.grid->getElement(x, y));
                    eletmp2->setPdv(eletmp2->getPdv() - 10);
                    if (eletmp2->getPdv() <= 0) {
                        state::BatimentTypeId typebatiment = eletmp2->getBatimentTypeId();
                        state.grid->killElement(x, y);
                        if (typebatiment == state::QGBLEU) {
                            CapturQGAction *newQG = new CapturQGAction(x, y, 1);
                            newQG->apply(state);
                            actions.push(shared_ptr<CapturQGAction>(newQG));

                        } else if (typebatiment == state::QGROUGE) {

                            CapturQGAction *newQG = new CapturQGAction(x, y, 2);
                            newQG->apply(state);
                            actions.push(shared_ptr<CapturQGAction>(newQG));

                        } else if (typebatiment == state::CASERNEBLEU) {

                            CapturCaserneAction *newCaserne = new CapturCaserneAction(x, y, 1);
                            newCaserne->apply(state);
                            actions.push(shared_ptr<CapturCaserneAction>(newCaserne));

                        } else if (typebatiment == state::CASERNEROUGE) {
                            CapturCaserneAction *newCaserne = new CapturCaserneAction(x, y, 2);
                            newCaserne->apply(state);
                            actions.push(shared_ptr<CapturCaserneAction>(newCaserne));

                        } else if (typebatiment == state::APPARTBLEU) {
                            CapturAppartAction *newAppart = new CapturAppartAction(x, y, 1);
                            newAppart->apply(state);
                            actions.push(shared_ptr<CapturAppartAction>(newAppart));

                        } else if (typebatiment == state::APPARTROUGE) {
                            CapturAppartAction *newAppart = new CapturAppartAction(x, y, 2);
                            newAppart->apply(state);
                            actions.push(shared_ptr<CapturAppartAction>(newAppart));

                        }
                    }
                }
            }


        }

    }

    void CapturCharCommand::serialise(Json::Value& out) const {
        out["Command"] = "Capture";
        out["x"] = x;
        out["y"] = y;
    }

    CapturCharCommand* CapturCharCommand::deserialise(Json::Value& in) {
        x = in["x"].asInt();
        y = in["y"].asInt();


        return new CapturCharCommand(x, y);
    }

}


