#include <iostream>
#include <string>
#include <vector>

#include "state/Element.h"
#include "state/State.h"
#include "EarnMoneyAction.h"
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
    EarnMoneyAction::EarnMoneyAction(int joueur,int nbrBatiment) :joueur(joueur),nbrBatiment(nbrBatiment){

    }

    void EarnMoneyAction::apply(state::State& state) {
        int batimentgains = 100;
        if (joueur==1)state.joueur1->addMoney(nbrBatiment * batimentgains);
        if (joueur==2)state.joueur2->addMoney(nbrBatiment * batimentgains);
        
    }

    void EarnMoneyAction::undo(state::State& state) {
        int batimentgains = 100;
        if (joueur==1)state.joueur1->lessMoney(nbrBatiment * batimentgains);
        if (joueur==2)state.joueur2->lessMoney(nbrBatiment * batimentgains);
    }
    

}