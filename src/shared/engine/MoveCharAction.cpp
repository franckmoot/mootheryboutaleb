#include <iostream>
#include <string>
#include <vector>

#include "state/Element.h"
#include "state/State.h"
#include "MoveCharAction.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/Champdebataille.h"
#include "state/Batiment.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/ChampdebatailleTypeId.h"
#include "state/BatimentTypeId.h"
#include <math.h>

using namespace std;
using namespace state;
namespace engine {

   
    MoveCharAction::MoveCharAction(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2)  {

        
    }


    
    void MoveCharAction::apply(state::State& state) {

       state.chars->chgPosition(x1, y1, x2, y2);
       cout<<"je bouge"<<endl;
    }
    
    void MoveCharAction::undo(state::State& state) {

        state.chars->chgPosition(x2, y2, x1, y1);
        cout<<"je reviens"<<endl;
    }

    
}







