#include <fstream>
#include <iostream>
#include <string>
#include "Loadcommand.h"
#include "state/State.h"
#include "state/Element.h"


using namespace std;
namespace engine{

    void Loadcommand::execute(state::State& state) {

    }
    
    CommandTypeId Loadcommand::getTypeId() const {
        CommandTypeId i;
        return i;
    }
   
}
    
    