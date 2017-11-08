#include <iostream>
#include <string>
#include <vector>

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


using namespace std;
using namespace state;
using namespace render;
using namespace engine;

int main(int argc,char* argv[]) {
  
  if (argc>1){
    string s;
    s=argv[1];
    
    if(!s.compare("hello")) {
      cout << "Bonjour le monde !" << endl;
    }
    else if(!s.compare("state")){
       
      teststate();
      
    }
    
    else if(!s.compare("render")){
        
     /// testcommande();
       testrender();
 
      return 0;
    }
    
  }
  
  return 0;
}
