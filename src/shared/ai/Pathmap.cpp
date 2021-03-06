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

    Pathmap::Pathmap() {
        directions.push_back(HAUT);
        directions.push_back(BAS);
        directions.push_back(GAUCHE);
        directions.push_back(DROITE);
    }

    const std::vector<Direction>& Pathmap::getDirections() const {
        return directions;
    }
        
    const std::priority_queue<Point, std::vector<Point>, PointCompareWeight>& Pathmap::getQueue() const {
        return queue;
    }
        
    void Pathmap::chgWeights(Point p) {
        weights[p.getX() + p.getY()*20] = p.getWeight();
    }

    int Pathmap::getWeights(Point p) {
        return weights[p.getX() + p.getY()*20];
    }

    bool Pathmap::isWall(Point p) {
        if ((p.getX() < 0) || (p.getY() < 0) || p.getY() > 19 || p.getX() > 19) return true;
        else if (weights[p.getX() + p.getY()*20] == -1) return true;
        else return false;
    }

    void Pathmap::addSink(Point p) {
        weights[p.getX() + p.getY()*20] = 0;
        queue.push(p);
    }


    void Pathmap::update(const state::ElementTab & grid) {

        while (!queue.empty()) {
            auto p = queue.top();
            queue.pop();

            chgWeights(p);

            for (Direction d : directions) {
                auto pp = p.transform(d);
                if (!isWall(pp)) {
                    pp.setWeight(p.getWeight() + 1);
                    if (getWeights(pp) > pp.getWeight()) {
                        queue.push(pp);
                    }
                }
            }
        }
    }
        
    int Pathmap::getPoidlist(int i) {
        return weights[i];
    }

    
}