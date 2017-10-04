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
        else cout << "it works" << endl;
      
         
        
    }
    cout << " Fabrique un etat" << endl;
    State Etat();
    ElementTab T(0,0);
    
    ElementTab H(0,0);
    
   
    Etat.grid = H;
    
   /* Etat.grid=T;
    
    cout << " Verifie que la largeur est null" << endl;
    if (Etat.grid.sizeList()==0) cout << " Ok" << endl;;
    Infanterie *ptIn,*ptIn2;
    cout << "--" << endl;
    Element *n=NULL;*/
    
    //ptIn->getPdv();
   /*
    T.setElement(0,0,ptIn);
    cout<< T.sizeList() << endl;
    cout << "---" << endl;
    T.setElement(1,1,n);
    cout << "----" << endl;
    n=T.getElement(0,0);*/
   // cout << n->getPdv() << endl;
   // n.getPdv();*/
    
    
    return 0;
}
