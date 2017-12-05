
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "CreateHeliAction.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/Batiment.h"
#include "CreateCharCommand.h"
#include "state/TypeId.h"


using namespace std;
using namespace state;
namespace engine {

    CreateHeliAction::CreateHeliAction(int x, int y, int joueur) : x(x), y(y), joueur(joueur) {

    }

    void CreateHeliAction::apply(state::State& state) {
        Heli *H = new Heli();
        H->setJoueur(joueur);
        state.chars->setElementXY(H, x, y);
    }

    void CreateHeliAction::undo(state::State& state) {
        state.getChars()->killElement(x, y);
    }



}
