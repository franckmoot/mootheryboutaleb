#include <string>
#include <iostream>
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/Batiment.h"
#include "CapturCaserneAction.h"

using namespace std;
using namespace state;

namespace engine {

    CapturCaserneAction::CapturCaserneAction(int x, int y, int joueur): x(x), y(y), joueur(joueur) {

    }

    void CapturCaserneAction::apply(state::State& state) {
        if (joueur == 1) {
            state.grid->setElementXY(new state::Batiment(CASERNEROUGE), x, y);
            state.grid->getElement(x, y)->setJoueur(joueur);
        } else {
            state.grid->setElementXY(new state::Batiment(CASERNEBLEU), x, y);
            state.grid->getElement(x, y)->setJoueur(joueur);
        }
    }

    void CapturCaserneAction::undo(state::State& state) {
        state.grid->killElement(x, y);
    }


}


