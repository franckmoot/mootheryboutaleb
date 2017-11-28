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
        int infini = 10000;

        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < 20; i++) {

                if (grid.getElement(i, j)->getTypeId() == 0) {
                    state::Champdebataille * eletmp = (state::Champdebataille*)(grid.getElement(i, j));
                    if (eletmp->getChampdeBatailleType() == state::EAU)
                        weights[i + 20 * j] = -1;

                } else {
                    weights[i + 20 * j] = infini;
                }

            }
        }

    }

    void Pathmap::setWeight(const Point & p) {
        queue.push(p);
    }

    void Pathmap::update(const state::ElementTab & grid) {


        bool found = true;
        Point *p= new Point(0,0,0);
        queue.push(p,weights,PointCompareWeight);
        while (!queue.empty()) {
            auto p = queue.top();
            queue.pop();

            /*chgpoids(p,p.point)*/

            for (Direction d : directions) {
                auto pp = p.transform(d);
                if (pp.getWeight() <= 1) {
                    pp.setWeight(p.getWeight() + 1);
                    if (getWeight(pp) > pp.getWeight()) {
                        queue.push(pp);
                    }
                }

            }


        }
    }






}