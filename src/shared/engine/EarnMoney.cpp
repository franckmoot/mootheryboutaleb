#include "state/BatimentTypeId.h"
#include <string>
#include <iostream>
#include "state/Batiment.h"
#include "AttaqueCharCommand.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include <math.h>
#include "EarnMoney.h"
#include "EarnMoneyAction.h"
using namespace std;
using namespace state;
namespace engine {

    EarnMoney::EarnMoney(int joueur) : joueur(joueur) {

    }

    CommandTypeId EarnMoney::getTypeId() const {
        return CommandTypeId::EARNMONEY;
    }

    void EarnMoney::execute(std::stack<std::shared_ptr<Action> >& actions, state::State& state) {


        if (joueur == 1) {
            int nbrBatiment = 0;
            for (int j = 0; j < int(state.getGrid()->getHeight()); j++) {
                for (int i = 0; i < int(state.getGrid()->getWidth()); i++) {
                    if (state.getGrid()->getElement(i, j)->getTypeId() == 1) {
                        state::Batiment* eletmp2 = (state::Batiment*)(state.getGrid()->getElement(i, j));
                        if ((eletmp2->getBatimentTypeId() == QGROUGE) || (eletmp2->getBatimentTypeId() == CASERNEROUGE) || (eletmp2->getBatimentTypeId() == APPARTROUGE))nbrBatiment++;
                    }
                }
            }
            EarnMoneyAction *E = new EarnMoneyAction(joueur, nbrBatiment);
            E->apply(state);
            actions.push(shared_ptr<EarnMoneyAction>(E));
        }
        if (joueur == 2) {
            int nbrBatiment = 0;
            for (int j = 0; j < int(state.getGrid()->getHeight()); j++) {
                for (int i = 0; i < int(state.getGrid()->getWidth()); i++) {
                    if (state.getGrid()->getElement(i, j)->getTypeId() == 1) {
                        state::Batiment* eletmp2 = (state::Batiment*)(state.getGrid()->getElement(i, j));
                        if ((eletmp2->getBatimentTypeId() == QGBLEU) || (eletmp2->getBatimentTypeId() == CASERNEBLEU) || (eletmp2->getBatimentTypeId() == APPARTBLEU))nbrBatiment++;
                    }
                }
            }
            EarnMoneyAction *E = new EarnMoneyAction(joueur, nbrBatiment);
            E->apply(state);
            actions.push(shared_ptr<EarnMoneyAction>(E));
        }

    }

    void EarnMoney::serialise(Json::Value& out) const {
        out["type"]="EarnMoney";
        out["joueur"]=joueur;

    }

    EarnMoney* EarnMoney::deserialise(Json::Value& in) {
           joueur = in["joueur"].asInt();

            
        return new EarnMoney(joueur);
    }


}