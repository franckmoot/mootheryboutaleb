#include <iostream>
#include <string>
#include <vector>

#include "state/Element.h"
#include "state/State.h"
#include "MoveCharCommand.h"
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

    MoveCharCommand::MoveCharCommand(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {

    }

    void MoveCharCommand::execute(std::stack<std::shared_ptr<Action> >& actions, state::State& state) {

        if ((state.getChars()->getElement(x2, y2) != NULL) || (state.getChars()->getElement(x1, y1) == NULL)) {
        }//cout << "c'est impossible " << endl;
        else {

            if (state.getChars()->getElement(x1, y1)->getTypeId() == 3) {
                state::Heli* eletmp = (state::Heli*)(state.getChars()->getElement(x1, y1));
                if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeMvt()) {
                    MoveCharAction *move = new MoveCharAction(x1, y1, x2, y2);
                    move->apply(state);
                    actions.push(shared_ptr<MoveCharAction>(move));
                }

            } else if (state.getChars()->getElement(x1, y1)->getTypeId() == 4) {
                state::Tank* eletmp = (state::Tank*)(state.getChars()->getElement(x1, y1));
                if (state.getGrid()->getElement(x2, y2)->getTypeId() == 0) {
                    state::Champdebataille* eletmp2 = (state::Champdebataille*)(state.getGrid()->getElement(x2, y2));
                    if (eletmp2->getChampdeBatailleType() == 4 || eletmp2->getChampdeBatailleType() == 5) {
                        //cout << "c'est impossible de mettre un element mobile sur cet elment statique" << endl;
                    } else {
                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeMvt()) {
                            MoveCharAction *move = new MoveCharAction(x1, y1, x2, y2);
                            move->apply(state);
                            actions.push(shared_ptr<MoveCharAction>(move));
                        } //else cout << "c est impossible pour un Tank de partir plus loin" << endl;
                    }
                } else if (state.grid->getElement(x2, y2)->getTypeId() == 1) {
                    if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeMvt()) {
                        MoveCharAction *move = new MoveCharAction(x1, y1, x2, y2);
                        move->apply(state);
                        actions.push(shared_ptr<MoveCharAction>(move));
                    }
                }
            } else if (state.getChars()->getElement(x1, y1)->getTypeId() == 2) {

                state::Infanterie* eletmp = (state::Infanterie*)(state.getChars()->getElement(x1, y1));
                if (state.getGrid()->getElement(x2, y2)->getTypeId() == 0) {
                    state::Champdebataille* eletmp2 = (state::Champdebataille*)(state.getGrid()->getElement(x2, y2));
                    if (eletmp2->getChampdeBatailleType() == 4) {
                        //cout << "c'est impossible de mettre un element mobile sur cet elment statique" << endl;
                    } else {

                        if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeMvt()) {

                            MoveCharAction *move = new MoveCharAction(x1, y1, x2, y2);
                            move->apply(state);
                            actions.push(shared_ptr<MoveCharAction>(move));
                        } //else cout << "c est impossible pour une infanterie de partir plus loin" << endl;
                    }
                } else if (state.getGrid()->getElement(x2, y2)->getTypeId() == 1) {

                    if ((int) (sqrt((((x1 - x2)*(x1 - x2))+((y1 - y2)*(y1 - y2))))) <= eletmp->getPorteeMvt()) {

                        MoveCharAction *move = new MoveCharAction(x1, y1, x2, y2);
                        move->apply(state);
                        actions.push(shared_ptr<MoveCharAction>(move));

                    }
                }
            }
        }
    }

    CommandTypeId MoveCharCommand::getTypeId() const {
        return CommandTypeId::MOVE;

    }

    void MoveCharCommand::serialise(Json::Value& out) const {      
        out["type"] = CommandTypeId::MOVE;
        out["x1"] = x1;
        out["y1"] = y1;
        out["x2"] = x2;
        out["y2"] = y2;
        
    }

    MoveCharCommand* MoveCharCommand::deserialise(Json::Value& in) {
       // if(in["Command"].asInt()==getTypeId()){
            x1 = in.get("x1",0).asInt();
            y1 = in.get("y1",0).asInt();
            x2 = in.get("x2",0).asInt();
            y2 = in.get("y2",0).asInt();
            
            cout <<"x1: "<<x1<<"\ty1: "<<y1<<"\tx2: "<<x2<<"\ty2: "<<y2<<endl;
      //  }
        
        return new MoveCharCommand(x1, y1, x2, y2);
    }

}









