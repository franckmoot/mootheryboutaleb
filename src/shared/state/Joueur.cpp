#include "Joueur.h"

namespace state {

    Joueur::Joueur() {
        money=5000;
    }

    void Joueur::addMoney(int money) {
        this->money+=money;
    }

    int Joueur::getMoney() {
        return money;
    }

    void Joueur::setMoney(int money) {
        this->money=money;
    }

    void Joueur::lessMoney(int money) {
       this->money-=money; 
    }

}