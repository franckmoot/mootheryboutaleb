#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"

#include "AI.h"
#include "state/State.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"



using namespace std;
using namespace state;
using namespace engine;
namespace ai {

    void AI::InfanterieCommands(const state::State& state, int x, std::vector<std::unique_ptr<engine::Command> >& list0, int y) {
        state::Infanterie* eletmp = (state::Infanterie*)(state.chars->getElement(x,y));
        
        for(int x2=(x-eletmp->getPorteeMvt());x2<(x+eletmp->getPorteeMvt());x2++){
            for(int y2=(y-eletmp->getPorteeMvt());y2<(y+eletmp->getPorteeMvt());y2++){
                if((x2>=0)&&(y2>=0)&&(x2<state.grid->getWidth())&&(y2<state.grid->getHeight())){
                list0.push_back(unique_ptr<Command>(new MoveCharCommand(x,y,x2,y2)));
                list0.push_back(unique_ptr<Command>(new AttaqueCharCommand(x,y,x2,y2)));
                }
            }
        }
            
    }
    
    
    void AI::HeliCommands(const state::State& state, int x, std::vector<std::unique_ptr<engine::Command> >& list1, int y){
               state::Heli* eletmp = (state::Heli*)(state.chars->getElement(x,y));
        
        for(int x2=(x-eletmp->getPorteeMvt());x2<(x+eletmp->getPorteeMvt());x2++){
            for(int y2=(y-eletmp->getPorteeMvt());y2<(y+eletmp->getPorteeMvt());y2++){
                if((x2>=0)&&(y2>=0)&&(x2<state.grid->getWidth())&&(y2<state.grid->getHeight())){
                list1.push_back(unique_ptr<Command>(new MoveCharCommand(x,y,x2,y2)));
                list1.push_back(unique_ptr<Command>(new AttaqueCharCommand(x,y,x2,y2)));
                }
            }
        } 
    }
    
    void AI::TankCommands(const state::State& state, int x, std::vector<std::unique_ptr<engine::Command> >& list2, int y){
                state::Tank* eletmp = (state::Tank*)(state.chars->getElement(x,y));
        
        for(int x2=(x-eletmp->getPorteeMvt());x2<(x+eletmp->getPorteeMvt());x2++){
            for(int y2=(y-eletmp->getPorteeMvt());y2<(y+eletmp->getPorteeMvt());y2++){
                if((x2>=0)&&(y2>=0)&&(x2<state.grid->getWidth())&&(y2<state.grid->getHeight())){
                list2.push_back(unique_ptr<Command>(new MoveCharCommand(x,y,x2,y2)));
                list2.push_back(unique_ptr<Command>(new AttaqueCharCommand(x,y,x2,y2)));
                }
            }
        }
    }
    
    
    



    void AI::BatimentCommands(const state::State& state, int joueur, std::vector<std::unique_ptr<engine::Command> >& list4) {
        if (joueur == 1) {
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(state::TypeId::HELI, 1)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(state::TypeId::INFANTERIE, 1)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(state::TypeId::TANK, 1)));

        }
        if (joueur == 2) {
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(state::TypeId::HELI, 2)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(state::TypeId::INFANTERIE, 2)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(state::TypeId::TANK, 2)));

        }


    }
}