#include <iostream>
#include <string>
#include <vector>

#include "state/Element.h"
#include "state/State.h"
#include "KillTankAction.h"
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

    KillTankAction::KillTankAction(int x, int y, state::TypeId elementId, int joueur) : x(x), y(y), elementId(elementId), joueur(joueur) {

    }

    void KillTankAction::apply(state::State& state) {
        state.getChars()->killElement(x, y);
    }

    void KillTankAction::undo(state::State& state) {
        Tank *T = new Tank();
        T->setJoueur(joueur);
        state.chars->setElementXY(T, x, y);
    }

}