#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "EarnMoney.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/ElementTab.h"
#include "state/ElementChars.h"

using namespace std;
using namespace state;

namespace engine {

    EarnMoney::EarnMoney() {

    }

    void EarnMoney::execute(state::State& state) {

    }

    CommandTypeId EarnMoney::getTypeId() const {
        return CommandTypeId::EARNMONEY;
    }




}