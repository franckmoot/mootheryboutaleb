#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"
#include "Direction.h"
#include "Pathmap.h"
#include "Pathinf.h"
#include "state/State.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "engine/Engine.h"
#include "engine/EarnMoney.h"
#include "state/Champdebataille.h"
#include <random>
#include <iostream>



using namespace std;
using namespace state;
using namespace engine;

namespace ai {

    void Pathinf::init(state::ElementTab& grid) {

        int infini = 10000;
        /*directions.push_back(HAUT);
        directions.push_back(BAS);
        directions.push_back(GAUCHE);
        directions.push_back(DROITE);*/

        for (int j = 0; j < int(grid.getHeight()); j++) {
            for (int i = 0; i < int(grid.getWidth()); i++) {

                if (grid.getElement(i, j)->getTypeId() == 0) {
                    state::Champdebataille * eletmp = (state::Champdebataille*)(grid.getElement(i, j));
                    if (eletmp->getChampdeBatailleType() == state::EAU) {
                        weights.push_back(-1);
                    } else {
                        weights.push_back(infini);
                    }

                } else {
                    weights.push_back(infini);
                }

            }
        }

    }


}