/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "State.h"
using namespace std;
namespace state {

    State::State() {

    }

    ElementChars* State::getChars() {
        return chars;
    }

    ElementTab* State::getGrid() {
        return grid;
    }

    int State::getscore(int joueur) {
        int nbrelement = 1;
        for (int j = 0; j < int(chars->getHeight()); j++) {
            for (int i = 0; i < int(chars->getWidth()); i++) {

                //cout<<"je fais ça"<<endl;

                if ((chars->getElement(i, j)->getTypeId() >= 2)&&(chars->getElement(i, j)->getJoueur() == joueur)) {
                    nbrelement++;
                }
            }
        }
        return nbrelement;
    }
}