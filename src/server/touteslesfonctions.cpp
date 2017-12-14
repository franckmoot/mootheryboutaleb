#include <iostream>
#include <string>

#include <vector>
#include <fstream>
#include <sstream>
#include <thread>
#include "state/Batiment.h"
#include "state/Champdebataille.h"
#include "state/Element.h"
#include "state/ElementChars.h"
#include "state/ElementTab.h"
#include "state/MobileElement.h"
#include "state/StaticElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "engine/Engine.h"
#include "ai/HeuristicAI.h"
#include "state/State.h"
#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/LoadCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"
#include "touteslesfonctions.h"

using namespace std;
using namespace state;
using namespace engine;
using namespace ai;
void testrecord() {
    engine::Engine engine;

    engine.addCommand(new engine::LoadCommand("res/map.csv"));

    engine.update();


    int joueur = 0;
    int joueur1 = 1;
    int joueur2 = 2;
    HeuristicAI test, test1;
    std::vector<std::stack < std::shared_ptr<Action> >> actions;



    while (1) {
        if (joueur % 2 == 0) {
            cout << "JOUEUR1 joue::" << endl;
            test.run(engine, joueur1);
            engine.updaterecord();
            joueur++;

        }

        if (joueur % 2 == 1) {
            cout << "JOUEUR2 joue::" << endl;
            test1.run(engine, joueur2);
            engine.updaterecord();

            joueur++;

        }
        if (joueur == 40) break;

        if (engine.currentState.grid->getElement(17, 14)->getJoueur() == 1) {
            cout << "le joueur 1 à gagné" << endl;
            break;
        }
        if (engine.currentState.grid->getElement(3, 2)->getJoueur() == 2) {
            cout << "le joueur 2 à gagné" << endl;
            break;
        }

        

    }
    std::string output;
    Json::StyledWriter writer;
    output = writer.write(engine.record);
    std::ofstream file("res/replay.txt", std::ios_base::app);
    file << output;

}
