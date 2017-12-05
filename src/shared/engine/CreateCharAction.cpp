#include <iostream>
#include <string>
#include <vector>

#include "state/Element.h"
#include "state/State.h"
#include "CreateCharAction.h"
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
    
    CreateCharAction::CreateCharAction(int x, int y, state::TypeId elementId, int joueur) {

    }

    void CreateCharAction::apply(state::State& state) {

    }

    void CreateCharAction::undo(state::State& state) {

    }




}