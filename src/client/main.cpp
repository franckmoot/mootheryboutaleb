#include <iostream>
#include <string>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[]) {

    if (argc>1){
        string s;
        s=argv[1];

        if(!s.compare("hello")) {
            cout << "Bonjour le monde !" << endl;
        }else cout << "it works" << endl;
    }
    
    return 0;
}
