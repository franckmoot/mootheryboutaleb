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
    
   
    /* Init list charactere */
    cout << "Fabrique une list de charactere" << endl;
    Infanterie *I=new Infanterie();
    //ElementTab T(0,0);
    ElementChars *T=new ElementChars();
    
    /* Infanterie */
    cout << "Verifie que la liste est null" << endl;
    if(T->sizeList()==0) cout << "Ok" << endl;
    cout << "On ajoute un Element de type Infanterie" << endl;
    T->setElement(0,0,I);
    cout << "Verifie que la liste est 1" << endl;
    if(T->sizeList()==1) cout << "Ok" << endl;
    cout << "Verifie que l'element ajouter est une infanterie" << endl;
    if(T->getElement(0,0)->getTypeId()==2) cout<<"Ok" <<endl;
 
    /* tank */
    Tank *Ta=new Tank();
    cout << "On ajoute un Element de type Tank" << endl;
    T->setElement(1,1,Ta);
    cout << "Verifie que la liste est 2" << endl;
    if(T->sizeList()==2) cout << "Ok" << endl;
    cout << "Verifie que l'element ajouter est un Tank" << endl;
    if(T->getElement(1,1)->getTypeId()==4) cout<<"Ok" <<endl;
    
    
    /* Heli */
    Heli *H=new Heli();
    cout << "On ajoute un Element de type Heli" << endl;
    T->setElement(1,2,H);
    cout << "Verifie que la liste est 3" << endl;
    if(T->sizeList()==3) cout << "Ok" << endl;
    cout << "Verifie que l'element ajouter est un Tank" << endl;
    if(T->getElement(1,2)->getTypeId()==3) cout<<"Ok" <<endl;
    
    
    /* init element static*/
    cout << "Fabrique une list d'Element static" << endl;
    Batiment *B=new Batiment();
    ElementTab *S=new ElementTab();
    
    /*batiment */
    cout << "Verifie que la liste est null" << endl;
    if(S->sizeList()==0) cout << "Ok" << endl;
    cout << "On ajoute un Element de type Batiment" << endl;
    S->setElement(0,0,B);
    cout << "Verifie que la liste est 1" << endl;
    if(S->sizeList()==1) cout << "Ok" << endl;
    cout << "Verifie que l'element ajouter est une Batiment" << endl;
    if(S->getElement(0,0)->getTypeId()==1) cout<<"Ok" <<endl;
    
    /* Champdebataille */
    Champdebataille *C=new Champdebataille();
    cout << "On ajoute un Element de type Heli" << endl;
    S->setElement(1,1,C);
    cout << "Verifie que la liste est 2" << endl;
    if(S->sizeList()==2) cout << "Ok" << endl;
    cout << "Verifie que l'element ajouter est un CHAMPDEBATAILLE" << endl;
    if(S->getElement(1,1)->getTypeId()==0) cout<<"Ok" <<endl;
    
    
    /* batiment caserne */
    Batiment *C2=new Batiment(BatimentTypeId::CASERNE);
    cout << "On ajoute un Element de type Heli" << endl;
    S->setElement(0,0,C2);
    cout << "Verifie que la liste est 3" << endl;
    if(S->sizeList()==3) cout << "Ok" << endl;
    cout << "Verifie que l'element ajouter est un batiment caserne" << endl;
    if(S->getElement(1,2)->getType()==BatimentTypeId::QG) cout<<"Ok" <<endl;
   
    //S->getElement(1,2)->getType();
    
    return 0;
}
