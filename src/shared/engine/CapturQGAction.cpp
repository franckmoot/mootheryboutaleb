#include <string>
#include <iostream>
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/Batiment.h"
#include "CapturQGAction.h"

using namespace std;
using namespace state;

namespace engine {

    CapturQGAction::CapturQGAction(int x, int y, int joueur): x(x), y(y), joueur(joueur) {

    }

    void CapturQGAction::apply(state::State& state) {

        if (joueur == 1) {
            state.grid->setElementXY(new state::Batiment(QGROUGE), x, y);
            state.grid->getElement(x, y)->setJoueur(joueur);
        }
        if (joueur==2){
            state.grid->setElementXY(new state::Batiment(QGBLEU), x, y);
            state.grid->getElement(x, y)->setJoueur(joueur);
        }
        
    }

    void CapturQGAction::undo(state::State& state) {
        if (joueur == 1) {
            state.grid->setElementXY(new state::Batiment(APPARTBLEU), x, y);
            state.grid->getElement(x, y)->setJoueur(joueur);
        } if (joueur==2){ 
            state.grid->setElementXY(new state::Batiment(APPARTROUGE), x, y);
            state.grid->getElement(x, y)->setJoueur(joueur);
        }
    }


}


