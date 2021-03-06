#include <string>
#include <iostream>
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/Batiment.h"
#include "CapturAppartAction.h"

using namespace std;
using namespace state;

namespace engine {

    CapturAppartAction::CapturAppartAction(int x, int y, int joueur) : x(x), y(y), joueur(joueur) {

    }

    void CapturAppartAction::apply(state::State& state) {
        if (joueur == 1) {
            state.grid->killElement(x, y);
            state.grid->setElementXY(new state::Batiment(APPARTROUGE), x, y);
            state.grid->getElement(x, y)->setJoueur(joueur);
        }
        if (joueur == 2) {
            state.grid->killElement(x, y);
            state.grid->setElementXY(new state::Batiment(APPARTBLEU), x, y);
            state.grid->getElement(x, y)->setJoueur(joueur);
        }
    }

    void CapturAppartAction::undo(state::State& state) {
        if (joueur == 1) {
            state.grid->killElement(x, y);
            state.grid->setElementXY(new state::Batiment(APPARTBLEU), x, y);
            state.grid->getElement(x, y)->setJoueur(joueur);
        }
        if (joueur == 2) {
            state.grid->killElement(x, y);
            state.grid->setElementXY(new state::Batiment(APPARTROUGE), x, y);
            state.grid->getElement(x, y)->setJoueur(joueur);
        }
    }
}


