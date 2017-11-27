#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"
#include "Direction.h"
#include "Pathmap.h"
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

    int Pathmap::getWeight(const Point& p) const {
        return p.getWeight();
    }

    const int* Pathmap::getWeights() const {
        int* a = NULL;
        return a;
    }

    void Pathmap::addSink(Point p) {

    }

    void Pathmap::init(const state::ElementTab& grid) {

        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < 20; i++) {

                if (grid.getElement(i, j)->getTypeId() == 0) {
                    state::Champdebataille * eletmp = (state::Champdebataille*)(grid.getElement(i, j));
                    //eletmp
                }

            }
        }

    }

    void Pathmap::setWeight(const Point & p) {

    }

    void Pathmap::update(const state::ElementTab & grid) {

    }






}