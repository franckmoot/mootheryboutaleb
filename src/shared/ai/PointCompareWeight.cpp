#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"
#include "Direction.h"
#include "PointCompareWeight.h"
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

    bool PointCompareWeight::operator()(const Point& a, const Point& b) {
        if (a.getWeight() < b.getWeight())return true;
        return false;
    }

}




