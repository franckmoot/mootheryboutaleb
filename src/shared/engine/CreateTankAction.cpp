#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "CreateTankAction.h"
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

    CreateTankAction::CreateTankAction(int x, int y,  int joueur):x(x),y(y),joueur(joueur) {

    }

    
    void CreateTankAction::apply(state::State& state) {
        Tank *T = new Tank();
        T->setJoueur(joueur);
        state.chars->setElementXY(T, x, y);
    }

    void CreateTankAction::undo(state::State& state) {
        state.getChars()->killElement(x, y);
    }


}

