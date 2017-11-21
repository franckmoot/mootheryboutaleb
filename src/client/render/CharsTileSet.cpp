#include <iostream>

#include "CharsTileSet.h"

#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"

using namespace std;
using namespace state;

namespace render {

    CharsTileSet::CharsTileSet() {
        int taille = 32;
        infanterie.push_back(Tile(0 * taille, 0 * taille, taille, taille));
        infanterie.push_back(Tile(0 * taille, 1 * taille, taille, taille));
        heli.push_back(Tile(1 * taille, 0 * taille, taille, taille));
        heli.push_back(Tile(1 * taille, 1 * taille, taille, taille));
        tank.push_back(Tile(2 * taille, 0 * taille, taille, taille));
        tank.push_back(Tile(3 * taille, 0 * taille, taille, taille));
        tank.push_back(Tile(2 * taille, 1 * taille, taille, taille));
    }

    const std::string CharsTileSet::getImageFile() const {
        return "res/player.png";
    }

    const Tile& CharsTileSet::getTile(const state::Element& e) const {

        if (!e.isStatic()) {
            MobileElement* mobileTmp = (MobileElement*) & e;

            switch (mobileTmp->getTypeId()) {

                case INFANTERIE:
                    if (mobileTmp->getJoueur() == 1)return infanterie[0];
                    if (mobileTmp->getJoueur() == 2)return infanterie[1];
                    break;

                case TANK:

                    if (mobileTmp->getJoueur() == 1)return tank[0];
                    if (mobileTmp->getJoueur() == 2)return tank[2];
                    break;

                case HELI:
                    if (mobileTmp->getJoueur() == 1)return heli[0];
                    if (mobileTmp->getJoueur() == 2)return heli[1];

                    break;

                default:
                    return infanterie[0];
                    break;
            }

        }
        return infanterie[0];
    }
}
