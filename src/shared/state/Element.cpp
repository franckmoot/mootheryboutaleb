#include "Element.h"


namespace state {

    Element::Element() {
    }

    Element::~Element() {
    }

    void Element::setTypeId(TypeId typeId) {
        this->typeId = typeId;
    }

    void Element::setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int Element::getX() const {
        return x;
    }

    int Element::getY() const {
        return y;
    }

    int Element::getJoueur() {
        return joueur;
    }

    void Element::setJoueur(int joueur) {
        this->joueur = joueur;
    }
    
    bool Element::getCommande() {
        return commande;
    }

    void Element::setCommande(bool commande) {
        this->commande=commande;
    }

}