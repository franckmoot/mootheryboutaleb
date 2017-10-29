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

using namespace std;
using namespace state;
using namespace render;

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
      
       testrender();
      
      
      // on définit le niveau à l'aide de numéro de tuiles
    /*  std::vector<int> level1 =
	{
1, 
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 
-1,-1,2,-1,-1,-1,0,-1,-1,-1, 
-1,-1,-1,-1,-1,-1,-1,-1,1,-1, 
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 
-1,-1,-1,-1,-1,-1,-1,-1,-1,2, 
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 
-1,-1,-1,-1,0,-1,-1,-1,-1,-1, 
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 
-1,-1,-1,-1,-1,-1,-1,-1,-1,

	};*/
      
      // on crée la tilemap avec le niveau précédemment défini   
      // on crée la fenêtre
      
      //Tilemap map,mapPlayer;
      /*std::vector<sf::Sprite> Map;*/
     // std::vector<int> level;
      
      
      
      //auto tab = map1.lirefichiercsv(level);
      
      //if (!map.load("res/tile.png", sf::Vector2u(64, 64),map.lirefichiercsv(level),10 , 10)) return -1;
      //if (!mapPlayer.load("res/playe.png", sf::Vector2u(64, 64),level1,10 , 10)) return -1;
      
      
      
      return 0;
    }
    
  }
  
  
  
  return 0;
}
