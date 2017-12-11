#include <string>
#include <iostream>
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/Batiment.h"
#include "CreateCharCommand.h"
#include "state/TypeId.h"
#include "CreateInfanterieAction.h"
#include "CreateHeliAction.h"
#include "CreateTankAction.h"

using namespace std;
using namespace state;
namespace engine {

    CreateCharCommand::CreateCharCommand(state::TypeId elementId, int x, int y, int joueur) : elementId(elementId), x(x), y(y), joueur(joueur) {
    }

    CommandTypeId CreateCharCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }

    void CreateCharCommand::execute(std::stack<std::shared_ptr<Action> >& actions, state::State& state) {

        if ((state.grid->getElement(x, y)->getTypeId() == 1)&& (state.chars->getElement(x, y) == NULL)&& (joueur == 1)) {
            if (elementId == state::INFANTERIE) {
                if (state.joueur1->getMoney() > 800) {
                    CreateInfanterieAction *newinf = new CreateInfanterieAction(x, y, joueur);
                    newinf->apply(state);
                    actions.push(shared_ptr<CreateInfanterieAction>(newinf));                
                    state.joueur1->setMoney(state.joueur1->getMoney() - 800);

                }
            } else if (elementId == state::HELI) {
                if (state.joueur1->getMoney() > 1000) {

                    CreateHeliAction *newheli = new CreateHeliAction(x, y, joueur);
                    newheli->apply(state);
                    actions.push(shared_ptr<CreateHeliAction>(newheli));                                      
                    state.joueur1->setMoney(state.joueur1->getMoney() - 1000);
                }
            } else if (elementId == state::TANK) {
                if (state.joueur1->getMoney() > 900) {

                    CreateTankAction *newtank = new CreateTankAction(x, y, joueur);
                    newtank->apply(state);
                    actions.push(shared_ptr<CreateTankAction>(newtank));
                    state.joueur1->setMoney(state.joueur1->getMoney() - 900);
                }
            }

        }
        if ((state.grid->getElement(x, y)->getTypeId() == 1)&& (state.chars->getElement(x, y) == NULL)&& (joueur == 2)) {
            if (elementId == state::INFANTERIE) {
                if (state.joueur2->getMoney() > 800) {

                    CreateInfanterieAction *newinf = new CreateInfanterieAction(x, y, joueur);
                    newinf->apply(state);
                    actions.push(shared_ptr<CreateInfanterieAction>(newinf));
                    state.joueur2->setMoney(state.joueur2->getMoney() - 800);
                }
            } else if (elementId == state::HELI) {
                if (state.joueur2->getMoney() > 1000) {

                    CreateHeliAction *newheli = new CreateHeliAction(x, y, joueur);
                    newheli->apply(state);
                    actions.push(shared_ptr<CreateHeliAction>(newheli));
                    state.joueur2->setMoney(state.joueur2->getMoney() - 1000);
                }
            } else if (elementId == state::TANK) {
                if (state.joueur2->getMoney() > 900) {

                    CreateTankAction *newtank = new CreateTankAction(x, y, joueur);
                    newtank->apply(state);
                    actions.push(shared_ptr<CreateTankAction>(newtank));
                    state.joueur2->setMoney(state.joueur2->getMoney() - 900);
                }
            }
        }
    }
        void CreateCharCommand::serialise(Json::Value& out) const {

    }

}
