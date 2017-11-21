#include <iostream>

#include "GridTileSet.h"
#include "state/Champdebataille.h"
#include "state/Batiment.h"
#include "state/MobileElement.h"

using namespace std;
using namespace state;

namespace render {

    GridTileSet::GridTileSet() {
        int taille = 32;

        chpbataille.push_back(Tile(0 * taille, 0, taille, taille)); //0 -> herbe
        chpbataille.push_back(Tile(1 * taille, 0, taille, taille)); //1 -> route
        chpbataille.push_back(Tile(2 * taille, 0, taille, taille)); //2 sable haut
        chpbataille.push_back(Tile(3 * taille, 0, taille, taille)); //3 eau sable
        chpbataille.push_back(Tile(4 * taille, 0, taille, taille)); //4 eau
        chpbataille.push_back(Tile(5 * taille, 0, taille, taille)); //5 montagne
        batiment.push_back(Tile(6 * taille, 0, taille, taille)); // 0 qg rouge
        batiment.push_back(Tile(7 * taille, 0, taille, taille)); //1 caserne rouge
        batiment.push_back(Tile(8 * taille, 0, taille, taille)); // 2 batiment rouge
        batiment.push_back(Tile(9 * taille, 0, taille, taille)); // 3 qg bleu
        batiment.push_back(Tile(10 * taille, 0, taille, taille)); //4 caserne bleue
        batiment.push_back(Tile(11 * taille, 0, taille, taille)); // 5 batiment bleu
    }

    const std::string GridTileSet::getImageFile() const {
        return "res/tile.png";
    }

    const Tile& GridTileSet::getTile(const state::Element& e) const {

        if (e.isStatic()) {
            StaticElement* staticTmp = (StaticElement*) & e;

            if (staticTmp->isChampdebataille()) {
                Champdebataille* champTmp = (Champdebataille*) & e;

                switch (champTmp->getChampdeBatailleType()) {

                    case HERBE:
                        return chpbataille[HERBE];
                        break;

                    case ROUTE:
                        return chpbataille[ROUTE];
                        break;

                    case SABLE1:
                        return chpbataille[SABLE1];
                        break;

                    case SABLE2:
                        return chpbataille[SABLE2];
                        break;

                    case EAU:
                        return chpbataille[EAU];
                        break;

                    case MONTAGNE:
                        return chpbataille[MONTAGNE];
                        break;

                    default:
                        return chpbataille[0];
                        break;
                }
            } else if (!staticTmp->isChampdebataille()) {

                Batiment* batTmp = (Batiment*) staticTmp;

                switch (batTmp->getBatimentTypeId()) {

                    case QGROUGE:
                        return batiment[QGROUGE];
                        break;

                    case CASERNEROUGE:
                        return batiment[CASERNEROUGE];
                        break;
                        
                    case APPARTROUGE:
                        return batiment[APPARTROUGE];
                        break;

                    case CASERNEBLEU:
                        return batiment[CASERNEBLEU];
                        break;
                        
                    case QGBLEU:
                        return batiment[QGBLEU];
                        break;

                    case APPARTBLEU:
                        return batiment[APPARTBLEU];
                        break;

                    default:

                        return chpbataille[0];
                        break;
                }

            }
        }

        return chpbataille[0];
    }
}



