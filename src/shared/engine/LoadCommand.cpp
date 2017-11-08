#include <fstream>
#include <iostream>
#include <string>
#include "LoadCommand.h"
#include "state/State.h"
#include "state/Element.h"


using namespace std;
namespace engine{

    void LoadCommand::execute(state::State& state) {

    }
    
    CommandTypeId LoadCommand::getTypeId() const {
        return CommandTypeId::LOAD;
    }
   
}
    
    