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
      
        State monde;
        monde.grid= new ElementTab();
        monde.grid->setElement(new Batiment());
        if(monde.grid->getElement(0,1)->getTypeId()==BATIMENT) cout << "batiment est 1er" << endl;
        
        
        
       // teststate();
        testcreateelement();
    }
    
    else if(!s.compare("render")){
        
       // testrender();
        
 
    // on définit le niveau à l'aide de numéro de tuiles
 std::vector<int> level1 =
    {
        3, 0, 0, 0, 0, 0, -1, -1, 1, 1,
        3, 1, 1, 1, 1, 1, 1, 0, -1, 0, 
        3, 1, 0, 0, 0, 0, 0, 0, 2, 2, 
        3, 1, 0, 0, 2, 0, 1, 2, 1, 0, 
        3, -1, -1, 0, -1, 1, 0, 0, 0, 0, 
        3, 0, -1, -1, -1, 0, -1, 2, 0, 0,
        3, 0, -1, -1, 0, 0, 2, -1, 2, 0, 
        3, -1, 1, -1, 1, 2, 2, 2, -1, -1,
        3, 0, 1, 0, 0, 2, 2, 2, 0, 0,
        3, 0, 1, 0, 0, -1, -1, -1, 0, 0,
    };

    // on crée la tilemap avec le niveau précédemment défini   
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(640, 640), "Tilemap");
    Tilemap map,mapPlayer;
    /*std::vector<sf::Sprite> Map;*/
    std::vector<int> level;
    
	
	
        //auto tab = map1.lirefichiercsv(level);
        
    if (!map.load("res/tile.png", sf::Vector2u(64, 64),map.lirefichiercsv(level),10 , 10)) return -1;
    if (!mapPlayer.load("res/playe.png", sf::Vector2u(64, 64),level1,10 , 10)) return -1;
       
    // on fait tourner la boucle principale
   while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.draw(mapPlayer);
        window.display();
 
    }

    return 0;
    }
    
  }
  
  
  
  return 0;
}
