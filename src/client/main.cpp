#include <iostream>
#include <string>
#include <vector>
#include <time.h>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

#include <vector>
#include <fstream>
#include <sstream>
#include <touteslesfonctions.h>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"
#include "render.h"
#include "engine.h"
#include "state/Infanterie.h"
#include "ai/RandomAI.h"


using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;

int main(int argc, char* argv[]) {

    if (argc > 1) {
        string s;
        s = argv[1];

        if (!s.compare("hello")) {
            cout << "Bonjour le monde !" << endl;
        } else if (!s.compare("state")) {

            teststate();

        } else if (!s.compare("render")) {

            testrender();
        } else if (!s.compare("engine")) {

            testengine();
        } else if (!s.compare("random_ai")) {

            testai();
        }
        else if (!s.compare("heuristic_ai")) {

            testheuristicAI();
        }
        else if (!s.compare("deep_ai")) {

            testdeep_ai();
        }

    }


    return 0;
}
