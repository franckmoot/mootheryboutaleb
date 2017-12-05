#include <iostream>
#include <string>
#include <vector>

#include "state/Element.h"
#include "state/State.h"
#include "KillCharAction.h"
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

    KillCharAction::KillCharAction(int x, int y, state::TypeId elementId, int joueur) :x(x),y(y),elementId(elementId),joueur(joueur){

    }

    void KillCharAction::apply(state::State& state) {
        state.getChars()->killElement(x, y);

    }

    void KillCharAction::undo(state::State& state) {
        
    }




}