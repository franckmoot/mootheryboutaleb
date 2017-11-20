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

    void AI::InfanterieCommands(const state::State& state, int i, std::vector<std::unique_ptr<engine::Command> >& list) {
        int a, b, c, d, e, f, g, h;
        a = i + 1;
        b = i - 1;
        c = i + 20;
        d = i - 20;
        e = i + 30;
        f = i - 30;
        g = i - 21;
        h = i + 21;
        if (a > 399) a = 399;
        if (a < 0) a = 0;
        if (b > 399) b = 399;
        if (b < 0) b = 0;
        if (c > 399) c = 399;
        if (c < 0) c = 0;
        if (d > 399) d = 399;
        if (d < 0) d = 0;
        if (e > 399) e = 399;
        if (e < 0) e = 0;
        if (f > 399) f = 399;
        if (f < 0) f = 0;
        if (g > 399) g = 399;
        if (g < 0) g = 0;
        if (h > 399) h = 399;
        if (h < 0) h = 0;
        list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i, a)));
        list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i, b)));
        list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i, c)));
        list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i, h)));
        list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i, g)));
        list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i, d)));
        list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i, f)));
        list.push_back(unique_ptr<Command>(new AttaqueCharCommand(i, e)));
        list.push_back(unique_ptr<Command>(new MoveCharCommand(i, a)));
        list.push_back(unique_ptr<Command>(new MoveCharCommand(i, b)));
        list.push_back(unique_ptr<Command>(new MoveCharCommand(i, c)));
        list.push_back(unique_ptr<Command>(new MoveCharCommand(i, h)));
        list.push_back(unique_ptr<Command>(new MoveCharCommand(i, g)));
        list.push_back(unique_ptr<Command>(new MoveCharCommand(i, d)));
        list.push_back(unique_ptr<Command>(new MoveCharCommand(i, f)));
        list.push_back(unique_ptr<Command>(new MoveCharCommand(i, e)));

    }

    void AI::HeliCommands(const state::State& state, int i, std::vector<std::unique_ptr<engine::Command> >& list1) {
        for (int j = i - 30; j < i + 30; j++) {
            if (j > 399) j = 399;
            if (j < 0) j = 0;
            if (state.chars->getElement(j, 1) != NULL && state.chars->getElement(j, 1)->getJoueur() != state.chars->getElement(j, 1)->getJoueur()) {
                list1.push_back(unique_ptr<Command>(new AttaqueCharCommand(i, j)));
            }
            list1.push_back(unique_ptr<Command>(new MoveCharCommand(i, j)));
        }



    }

    void AI::TankCommands(const state::State& state, int i, std::vector<std::unique_ptr<engine::Command> >& list2) {
        for (int j = i - 30; j < i + 30; j++) {
           if (j > 399) j = 399;
            if (j < 0) j = 0;
            if (state.chars->getElement(j, 1) != NULL) {
                list2.push_back(unique_ptr<Command>(new AttaqueCharCommand(i, j)));
            }
            list2.push_back(unique_ptr<Command>(new MoveCharCommand(i, j)));
        }



    }

    void AI::BatimentCommands(const state::State& state, int joueur, std::vector<std::unique_ptr<engine::Command> >& list4) {
        if (joueur == 1) {
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(22, state::TypeId::HELI, 1)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(22, state::TypeId::INFANTERIE, 1)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(22, state::TypeId::TANK, 1)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(26, state::TypeId::HELI, 1)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(26, state::TypeId::INFANTERIE, 1)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(26, state::TypeId::TANK, 1)));

        }
        if (joueur == 2) {
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(297, state::TypeId::HELI, 2)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(297, state::TypeId::INFANTERIE, 2)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(297, state::TypeId::TANK, 2)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(298, state::TypeId::HELI, 2)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(298, state::TypeId::INFANTERIE, 2)));
            list4.push_back(unique_ptr<Command>(new CreateCharCommand(298, state::TypeId::TANK, 2)));

        }


    }
}