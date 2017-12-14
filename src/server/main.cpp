#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include <vector>
#include <fstream>
#include <sstream>
#include "touteslesfonctions.h"

#include "state.h"
#include "engine.h"
#include "state/Infanterie.h"
#include "ai/RandomAI.h"
#include "ai/HeuristicAI.h"



using namespace std;
using namespace state;

using namespace engine;
using namespace ai;

int main(int argc, char* argv[]) {

    if (argc > 1) {
        string s;
        s = argv[1];

        if (!s.compare("hello")) {
            cout << "Bonjour le monde !" << endl;
        } else if (!s.compare("record")) {

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
        if (joueur == 20) break;

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
    std::ofstream file("replay.txt", std::ios_base::app);
    file << output;

}
    }

return 0;
}
