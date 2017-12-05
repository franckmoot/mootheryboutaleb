#include <string>
#include <iostream>
#include "AttaqueCharCommand.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
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
                            eletmp2->setPdv(eletmp2->getPdv() - eletmp->getAttaque());
                            if (eletmp2->getPdv() <= 0) {
                                state.getChars()->killElement(x2, y2);
                                //cout << "notre element d'absice" << x2 << "et d'ordonnée" << y2 << "est mort" << endl;
                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.getChars()->getElement(x2, y2)->getTypeId() == 3) {
                        state::Heli* eletmp2 = (state::Heli*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            eletmp2->setPdv(eletmp2->getPdv() - eletmp->getAttaque());
                            if (eletmp2->getPdv() <= 0) {

                                state.getChars()->killElement(x2, y2);
                                //cout << "notre element d'absice" << x2 << "et d'ordonnée" << y2 << "est mort" << endl;
                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.getChars()->getElement(x2, y2)->getTypeId() == 4) {
                        state::Tank* eletmp2 = (state::Tank*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            eletmp2->setPdv(eletmp2->getPdv() - eletmp->getAttaque());
                            if (eletmp2->getPdv() <= 0) {

                                state.getChars()->killElement(x2, y2);
                                //cout << "notre element d'absice" << x2 << "et d'ordonnée" << y2 << "est mort" << endl;
                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    }
                } else if (state.chars->getElement(x1, y1)->getTypeId() == 3) {
                    state::Infanterie* eletmp = (state::Infanterie*)(state.getChars()->getElement(x1, y1));
                    if (state.chars->getElement(x2, y2)->getTypeId() == 2) {
                        state::Infanterie* eletmp2 = (state::Infanterie*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            eletmp2->setPdv(eletmp2->getPdv() - eletmp->getAttaque());

                            if (eletmp2->getPdv() <= 0) {

                                state.chars->killElement(x2, y2);
                                //cout << "notre element d'absice" << x2 << "et d'ordonnée" << y2 << "est mort" << endl;
                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.chars->getElement(x2, y2)->getTypeId() == 3) {
                        state::Heli* eletmp2 = (state::Heli*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            eletmp2->setPdv(eletmp2->getPdv() - eletmp->getAttaque());
                            if (eletmp2->getPdv() <= 0) {

                                state.getChars()->killElement(x2, y2);
                                //cout << "notre element d'absice" << x2 << "et d'ordonnée" << y2 << "est mort" << endl;
                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.chars->getElement(x2, y2)->getTypeId() == 4) {
                        state::Tank* eletmp2 = (state::Tank*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            eletmp2->setPdv(eletmp2->getPdv() - eletmp->getAttaque());
                            if (eletmp2->getPdv() <= 0) {

                                state.getChars()->killElement(x2, y2);
                                //cout << "notre element d'absice" << x2 << "et d'ordonnée" << y2 << "est mort" << endl;
                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    }
                } else if (state.chars->getElement(x1, y1)->getTypeId() == 4) {
                    state::Infanterie* eletmp = (state::Infanterie*)(state.getChars()->getElement(x1, y1));
                    if (state.getChars()->getElement(x2, y2)->getTypeId() == 2) {
                        state::Infanterie* eletmp2 = (state::Infanterie*)(state.getChars()->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            eletmp2->setPdv(eletmp2->getPdv() - eletmp->getAttaque());
                            if (eletmp2->getPdv() <= 0) {

                                state.chars->killElement(x2, y2);
                                //cout << "notre element d'absice" << x2 << "et d'ordonnée" << y2 << "est mort" << endl;
                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.getChars()->getElement(x2, y2)->getTypeId() == 3) {
                        state::Heli* eletmp2 = (state::Heli*)(state.chars->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            eletmp2->setPdv(eletmp2->getPdv() - eletmp->getAttaque());
                            if (eletmp2->getPdv() <= 0) {
                               

                                state.chars->killElement(x2, y2);
                                //cout << "notre element d'absice" << x2 << "et d'ordonnée" << y2 << "est mort" << endl;
                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    } else if (state.getChars()->getElement(x2, y2)->getTypeId() == 4) {
                        state::Tank* eletmp2 = (state::Tank*)(state.chars->getElement(x2, y2));
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeAtq()) {
                            eletmp2->setPdv(eletmp2->getPdv() - eletmp->getAttaque());
                            if (eletmp2->getPdv() <= 0) {

                                 state.chars->killElement(x2, y2);
                                //cout << "notre element d'absice" << x2 << "et d'ordonnée" << y2 << "est mort" << endl;
                            }
                        } //else cout << "ta portée n'est pas suffisante" << endl;
                    }
                }
            } else {
                //cout << "tu n'attaques pas ton ami" << endl;
            }
        }
    }
}

