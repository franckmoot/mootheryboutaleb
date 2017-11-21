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



using namespace std;
using namespace state;
namespace engine {

    CreateCharCommand::CreateCharCommand(state::TypeId d, int joueur):d(d),joueur(joueur) {

    }

    CommandTypeId CreateCharCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }

    void CreateCharCommand::execute(state::State& state) {
        if (joueur == 1) {
            for (int j = 0; j < int(state.getChars()->getHeight()); j++) {
                for (int i = 0; i < int(state.getChars()->getWidth()); i++) {
                    if ((state.grid->getElement(i, j)->getTypeId() == 1)&& (state.chars->getElement(i, j) == NULL)) {
                        if (d == 2) {
                            Infanterie *I = new Infanterie();
                            I->setJoueur(1);
                            state.chars->setElementXY(I, i, j);

                        }
                        if (d == 3) {
                            Heli *H = new Heli();
                            H->setJoueur(1);
                            state.chars->setElementXY(H, i, j);

                        }
                        if (d == 4) {
                            Tank *T = new Tank();
                            T->setJoueur(1);
                            state.chars->setElementXY(T, i, j);
                        }
                    }

                }
            }
        }
        if (joueur == 2) {
            for (int j = 0; j < int(state.chars->getHeight()); j++) {
                for (int i = 0; i < int(state.chars->getWidth()); i++) {
                    if ((state.grid->getElement(i, j)->getTypeId() == 1)&& (state.chars->getElement(i, j) == NULL)) {
                        if (d == 2) {
                            Infanterie *I = new Infanterie();
                            I->setJoueur(2);
                            state.chars->setElementXY(I, i, j);

                        }
                        if (d == 3) {
                            Heli *H = new Heli();
                            H->setJoueur(2);
                            state.chars->setElementXY(H, i, j);

                        }
                        if (d == 4) {
                            Tank *T = new Tank();
                            T->setJoueur(2);
                            state.chars->setElementXY(T, i, j);
                        }
                    }

                }
            }
        }
    }
}