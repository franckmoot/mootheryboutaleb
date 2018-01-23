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
            testrecord();


        } else if (!s.compare("listen")) {
            testlisten(argc,argv);

        }
    }

    return 0;
}
