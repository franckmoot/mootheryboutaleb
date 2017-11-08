#include <string>
#include "AttaqueCharCommand.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"

using namespace std;
namespace engine{
        
    CommandTypeId AttaqueCharCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }
    
    
    
    void AttaqueCharCommand::execute(state::State& state) {

         /*if(!state.chars->getElement(i,1)->isStatic()){
            if(!state.chars->getElement(j,1)->isStatic()){
                state::MobileElement* mobileTmpi = (state::MobileElement*)&(state.chars->getElement(i,1));
                state::MobileElement* mobileTmpj = (state::MobileElement*)&(state.chars->getElement(j,1));
                //mobileTmpi;
        */
    }
         
    

    


}
    