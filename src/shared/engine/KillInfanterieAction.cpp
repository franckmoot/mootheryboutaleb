#include <iostream>
#include <string>
#include <vector>

#include "state/Element.h"
#include "state/State.h"
#include "KillInfanterieAction.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/Champdebataille.h"
#include "state/Batiment.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/ChampdebatailleTypeId.h"
#include "state/BatimentTypeId.h"
#include <math.h>

using namespace std;
using namespace state;
namespace engine {

    KillInfanterieAction::KillInfanterieAction(int x, int y, int joueur) : x(x), y(y), joueur(joueur) {

    }

    void KillInfanterieAction::apply(state::State& state) {
        state.getChars()->killElement(x, y);
    }

    void KillInfanterieAction::undo(state::State& state) {
        Infanterie *infanterietmp = new Infanterie();
        infanterietmp->setJoueur(joueur);
        state.chars->setElementXY(infanterietmp, x, y);
    }


}
