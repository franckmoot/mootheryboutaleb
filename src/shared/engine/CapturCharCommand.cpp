#include <string>
#include "CapturCharCommand.h"
#include "state/State.h"
#include "state/Element.h"

using namespace std;
namespace engine{
    
    void CapturCharCommand::execute(state::State state) {

    }
    
    CommandTypeId CapturCharCommand::getTypeId() const {
        return CommandTypeId::CAPTUR;
    }


}
    
    