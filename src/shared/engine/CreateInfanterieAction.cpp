#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "CreateInfanterieAction.h"
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

    CreateInfanterieAction::CreateInfanterieAction(int x, int y, int joueur) {

    }

    void CreateInfanterieAction::apply(state::State& state) {
        Infanterie *infanterietmp = new Infanterie();
        infanterietmp->setJoueur(joueur);
        state.chars->setElementXY(infanterietmp, x, y);
    }

    void CreateInfanterieAction::undo(state::State& state) {
        state.getChars()->killElement(x, y);
    }



}
