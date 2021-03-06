#include <string>
#include <iostream>
#include "AttaqueCharCommand.h"
#include "KillHeliAction.h"
#include "KillTankAction.h"
#include "KillInfanterieAction.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "AttaqueCharAction.h"
#include <math.h>

using namespace std;
using namespace state;
namespace engine {

    AttaqueCharCommand::AttaqueCharCommand(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {

    }

    CommandTypeId AttaqueCharCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }

    void AttaqueCharCommand::execute(std::stack<std::shared_ptr<Action> >& actions, state::State& state) {

        if ((state.getChars()->getElement(x1, y1) != NULL) && (state.getChars()->getElement(x2, y2) != NULL)) {

            if (state.getChars()->getElement(x1, y1)->getJoueur() != state.getChars()->getElement(x2, y2)->getJoueur()) {

                if (state.chars->getElement(x1, y1)->getTypeId() == 2) {
                    state::Infanterie* eletmp = (state::Infanterie*)(state.getChars()->getElement(x1, y1));
                    if (state.getChars()->getElement(x2, y2)->getTypeId() == 2) {
                        state::Infanterie* eletmp2 = (state::Infanterie*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            AttaqueCharAction *A = new AttaqueCharAction(x1, y1, x2, y2);
                            A->apply(state);
                            actions.push(shared_ptr<AttaqueCharAction>(A));

                            if (eletmp2->getPdv() <= 0) {
                                KillInfanterieAction *killinf = new KillInfanterieAction(x2, y2, state.getChars()->getElement(x2, y2)->getJoueur());
                                killinf->apply(state);
                                actions.push(shared_ptr<KillInfanterieAction>(killinf));

                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.getChars()->getElement(x2, y2)->getTypeId() == 3) {
                        state::Heli* eletmp2 = (state::Heli*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            AttaqueCharAction *A = new AttaqueCharAction(x1, y1, x2, y2);
                            A->apply(state);
                            actions.push(shared_ptr<AttaqueCharAction>(A));
                            if (eletmp2->getPdv() <= 0) {
                                KillHeliAction *killheli = new KillHeliAction(x2, y2, state.getChars()->getElement(x2, y2)->getJoueur());
                                killheli->apply(state);
                                actions.push(shared_ptr<KillHeliAction>(killheli));

                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.getChars()->getElement(x2, y2)->getTypeId() == 4) {
                        state::Tank* eletmp2 = (state::Tank*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            AttaqueCharAction *A = new AttaqueCharAction(x1, y1, x2, y2);
                            A->apply(state);
                            actions.push(shared_ptr<AttaqueCharAction>(A));
                            if (eletmp2->getPdv() <= 0) {
                                KillTankAction *killtank = new KillTankAction(x2, y2, state.getChars()->getElement(x2, y2)->getJoueur());
                                killtank->apply(state);
                                actions.push(shared_ptr<KillTankAction>(killtank));

                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    }
                } else if (state.chars->getElement(x1, y1)->getTypeId() == 3) {
                    state::Heli* eletmp = (state::Heli*)(state.getChars()->getElement(x1, y1));
                    if (state.chars->getElement(x2, y2)->getTypeId() == 2) {
                        state::Infanterie* eletmp2 = (state::Infanterie*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            AttaqueCharAction *A = new AttaqueCharAction(x1, y1, x2, y2);
                            A->apply(state);
                            actions.push(shared_ptr<AttaqueCharAction>(A));

                            if (eletmp2->getPdv() <= 0) {
                                KillInfanterieAction *killinf = new KillInfanterieAction(x2, y2, state.getChars()->getElement(x2, y2)->getJoueur());
                                killinf->apply(state);
                                actions.push(shared_ptr<KillInfanterieAction>(killinf));

                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.chars->getElement(x2, y2)->getTypeId() == 3) {
                        state::Heli* eletmp2 = (state::Heli*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            AttaqueCharAction *A = new AttaqueCharAction(x1, y1, x2, y2);
                            A->apply(state);
                            actions.push(shared_ptr<AttaqueCharAction>(A));
                            if (eletmp2->getPdv() <= 0) {

                                KillHeliAction *killheli = new KillHeliAction(x2, y2, state.getChars()->getElement(x2, y2)->getJoueur());
                                killheli->apply(state);
                                actions.push(shared_ptr<KillHeliAction>(killheli));

                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.chars->getElement(x2, y2)->getTypeId() == 4) {
                        state::Tank* eletmp2 = (state::Tank*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            AttaqueCharAction *A = new AttaqueCharAction(x1, y1, x2, y2);
                            A->apply(state);
                            actions.push(shared_ptr<AttaqueCharAction>(A));
                            if (eletmp2->getPdv() <= 0) {
                                KillTankAction *killtank = new KillTankAction(x2, y2, state.getChars()->getElement(x2, y2)->getJoueur());
                                killtank->apply(state);
                                actions.push(shared_ptr<KillTankAction>(killtank));

                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    }
                } else if (state.chars->getElement(x1, y1)->getTypeId() == 4) {
                    state::Tank* eletmp = (state::Tank*)(state.getChars()->getElement(x1, y1));
                    if (state.getChars()->getElement(x2, y2)->getTypeId() == 2) {
                        state::Infanterie* eletmp2 = (state::Infanterie*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            AttaqueCharAction *A = new AttaqueCharAction(x1, y1, x2, y2);
                            A->apply(state);
                            actions.push(shared_ptr<AttaqueCharAction>(A));
                            if (eletmp2->getPdv() <= 0) {
                                KillInfanterieAction *killinf = new KillInfanterieAction(x2, y2, state.getChars()->getElement(x2, y2)->getJoueur());
                                killinf->apply(state);
                                actions.push(shared_ptr<KillInfanterieAction>(killinf));

                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.getChars()->getElement(x2, y2)->getTypeId() == 3) {
                        state::Heli* eletmp2 = (state::Heli*)(state.chars->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            AttaqueCharAction *A = new AttaqueCharAction(x1, y1, x2, y2);
                            A->apply(state);
                            actions.push(shared_ptr<AttaqueCharAction>(A));
                            if (eletmp2->getPdv() <= 0) {

                                KillHeliAction *killheli = new KillHeliAction(x2, y2, state.getChars()->getElement(x2, y2)->getJoueur());
                                killheli->apply(state);
                                actions.push(shared_ptr<KillHeliAction>(killheli));

                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.getChars()->getElement(x2, y2)->getTypeId() == 4) {
                        state::Tank* eletmp2 = (state::Tank*)(state.chars->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            AttaqueCharAction *A = new AttaqueCharAction(x1, y1, x2, y2);
                            A->apply(state);
                            actions.push(shared_ptr<AttaqueCharAction>(A));
                            if (eletmp2->getPdv() <= 0) {
                                KillTankAction *killtank = new KillTankAction(x2, y2, state.getChars()->getElement(x2, y2)->getJoueur());
                                killtank->apply(state);
                                actions.push(shared_ptr<KillTankAction>(killtank));

                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    }
                }
            } else {
                //cout << "tu n'attaques pas ton ami" << endl;
            }
        }
    }

    void AttaqueCharCommand::serialise(Json::Value& out) const {
        out["type"] = "Attaque";
        out["x1"] = x1;
        out["y1"] = y1;
        out["x2"] = x2;
        out["y2"] = y2;

    }

    AttaqueCharCommand* AttaqueCharCommand::deserialise(Json::Value& in) {
        x1 = in["x1"].asInt();
        y1 = in["y1"].asInt();
        x2 = in["x2"].asInt();
        y2 = in["y2"].asInt();

        return new AttaqueCharCommand(x1, y1, x2, y2);
    }

}


