#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"
#include "Direction.h"
#include "Point.h"
#include "state/State.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "engine/Engine.h"
#include "engine/EarnMoney.h"
#include <random>
#include <iostream>



using namespace std;
using namespace state;
using namespace engine;

namespace ai {

    Point::Point(int x, int y, int w) : x(x), y(y), weight(w) {

    }

    int Point::getWeight() const {
        return weight;
    }

    int Point::getX() const {
        return x;
    }

    void Point::setWeight(int weight) {
        this->weight = weight;
    }

    int Point::getY() const {
        return y;
    }

    void Point::setY(int y) {
        this->y = y;
    }

    void Point::setX(int x) {
        this->x = x;
    }

    Point Point::transform(Direction d) {

        switch (d) {

            case HAUT:
                return Point(x, y - 1, weight + 1);
                break;

            case BAS:
                return Point(x, y + 1, weight + 1);
                break;

            case DROITE:
                return Point(x + 1, y, weight + 1);
                break;

            case GAUCHE:
                return Point(x - 1, y, weight + 1);
                break;

            default:
                return Point(- 1, -1, 1);
                break;

        }
    }
}




