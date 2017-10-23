#include <iostream>
#include <string>
#include <vector>

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
    }
    else if(!s.compare("state")){
      /* Init list charactere */
      cout << "Fabrique une list de charactere" << endl;
      Infanterie *I=new Infanterie();
      //ElementTab T(0,0);
      ElementChars *T=new ElementChars();
      
      /* Infanterie */
      cout << "Verifie que la liste est null" << endl;
      if(T->sizeList()==0) cout << "Ok" << endl;
      cout << "On ajoute un Element de type Infanterie" << endl;
      T->setElement(I);
      cout << "Verifie que la liste est 1" << endl;
      if(T->sizeList()==1) cout << "Ok" << endl;
      cout << "Verifie que l'element ajouter est une infanterie" << endl;
      if(T->getElement(0,0)->getTypeId()==2) cout<<"Ok" <<endl;
      
      /* tank */
      Tank *Ta=new Tank();
      cout << "On ajoute un Element de type Tank" << endl;
      T->setElement(Ta);
      cout << "Verifie que la liste est 2" << endl;
      if(T->sizeList()==2) cout << "Ok" << endl;
      cout << "Verifie que l'element ajouter est un Tank" << endl;
      if(T->getElement(1,1)->getTypeId()==4) cout<<"Ok" <<endl;
      
      
      /* Heli */
      Heli *H=new Heli();
      cout << "On ajoute un Element de type Heli" << endl;
      T->setElement(H);
      cout << "Verifie que la liste est 3" << endl;
      if(T->sizeList()==3) cout << "Ok" << endl;
      cout << "Verifie que l'element ajouter est un Tank" << endl;
      if(T->getElement(1,2)->getTypeId()==3) cout<<"Ok" <<endl;
      
      
      /*remplissage de null*/
      cout << "On rempli la liste de chars par 5 elements vide" << endl;
      for(int i=0;i<5;i++){
	T->setElement(NULL);
      }
      cout << "Verifie que la liste est 8" << endl;
      if(T->sizeList()==8) cout << "Ok" << endl;
      
      cout << "Deplacement du tank" << endl;
      T->chgList2(2,7);
      cout << "Verifie que le tank est a la 8eme place" << endl;
      if(T->getElement(1,7)->getTypeId()==3) cout<<"Ok" <<endl;
      cout << "Verifie que à la place du tank on a un element vide" << endl;
      if(T->getElement(1,2)==NULL) cout<<"Ok" <<endl;
      
      /* Ajoue d'un element heli a la 7eme place */
      Heli *H2=new Heli();
      cout << "Ajoue d'un Heli à la 6eme place" << endl;
      T->chgList(6,H2);
      cout << "Verifie que Heli est a la 6eme place" << endl;
      if(T->getElement(1,6)->getTypeId()==3) cout<<"Ok" <<endl;
      
      
      /* init element static*/
      cout << "Fabrique une list d'Element static" << endl;
      Batiment *B=new Batiment();
      ElementTab *S=new ElementTab();
      
      /*batiment */
      cout << "Verifie que la liste est null" << endl;
      if(S->sizeList()==0) cout << "Ok" << endl;
      cout << "On ajoute un Element de type Batiment" << endl;
      S->setElement(B);
      cout << "Verifie que la liste est 1" << endl;
      if(S->sizeList()==1) cout << "Ok" << endl;
      cout << "Verifie que l'element ajouter est une Batiment" << endl;
      if(S->getElement(0,0)->getTypeId()==1) cout<<"Ok" <<endl;
      
      /* Champdebataille */
      Champdebataille *C=new Champdebataille();
      cout << "On ajoute un Element de type Heli" << endl;
      S->setElement(C);
      cout << "Verifie que la liste est 2" << endl;
      if(S->sizeList()==2) cout << "Ok" << endl;
      cout << "Verifie que l'element ajouter est un champdebataille" << endl;
      if(S->getElement(1,1)->getTypeId()==0) cout<<"Ok" <<endl;
      
      
      /* batiment caserne */
      Batiment *C2=new Batiment(BatimentTypeId::CASERNE);
      cout << "On ajoute un Element de type Batiment" << endl;
      S->setElement(C2);
      cout << "Verifie que la liste est 3" << endl;
      if(S->sizeList()==3) cout << "Ok" << endl;
      cout << "Verifie que l'element ajouter est un Batiment caserne" << endl;
      if(S->getElement(1,2)->getType()==BatimentTypeId::CASERNE) cout<<"Ok" <<endl;
    }
    
    else if(!s.compare("render")){
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(2048, 1024), "Tilemap");

    // on définit le niveau à l'aide de numéro de tuiles


    // on crée la tilemap avec le niveau précédemment défini
        

    Tilemap map;
    /*std::vector<sf::Sprite> Map;*/
    std::vector<int> level;
    
	
	
    if (!map.load("tilemap.png", sf::Vector2u(16, 16),map.lirefichiercsv(level),100 , 100))
        return -1;

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
        window.display();
    }

    return 0;
    }
    
    else cout << "it works" << endl;
    
  }
  
  return 0;
}
