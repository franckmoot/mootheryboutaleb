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
#include "state/Infanterie.h"


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
    else if(!s.compare("engine")){
        
        State monde;
        (monde.grid)=new ElementTab(); 
  engine::LoadCommand a("res/map.csv");
  a.execute(monde);
  (monde.chars)=new ElementChars(9,11);
     
    Infanterie *I=new Infanterie();
    I->setJoueur(1);
    Heli *H=new Heli();
    H->setJoueur(1);
    Tank *T=new Tank();
    T->setJoueur(1);
    
    Infanterie *I2=new Infanterie();
    I2->setJoueur(2);
    Heli *H2=new Heli();
    H2->setJoueur(2);
    Tank *T2=new Tank();
    T2->setJoueur(2);

    monde.chars->chgList(0,I);//ajoute des elements
     
    monde.chars->chgList(10,H);
    monde.chars->chgList(20,T);
    monde.chars->chgList(30,I2);
    monde.chars->chgList(40,H2);
    monde.chars->chgList(50,T2);
    
   
    if(monde.chars->getElement(0,1)->getTypeId()==2) cout<<"L'infanterie est en position 0 " <<endl;
    engine::MoveCharCommand deplacementinfanterie(0,1);
    deplacementinfanterie.execute(monde);cout<<"L'infanterie se deplace " <<endl;
    if(monde.chars->getElement(0,1)==NULL)cout<<"L'infanterie se n'est plus en position 0 " <<endl; 
    if(monde.chars->getElement(1,1)->getTypeId()==2) cout<<"L'infanterie est en position 1 " <<endl;
    cout<<""<<endl;
    
    if(monde.chars->getElement(10,1)->getTypeId()==3) cout<<"L'heli est en position 10 " <<endl;
    engine::MoveCharCommand deplacementheli(10,11);
    deplacementheli.execute(monde);cout<<"L'heli se deplace " <<endl;
    if(monde.chars->getElement(10,1)==NULL)cout<<"L'heli n'est plus en position 10 " <<endl; 
    if(monde.chars->getElement(11,1)->getTypeId()==3) cout<<"L'heli est en position 11 " <<endl;
    cout<<""<<endl;
    
    if(monde.chars->getElement(20,1)->getTypeId()==4) cout<<"Le tank est en position 0 " <<endl;
    engine::MoveCharCommand deplacementtank(20,21);
    deplacementtank.execute(monde);cout<<"Le tank se deplace " <<endl;
    if(monde.chars->getElement(20,1)==NULL)cout<<"Le tank n'est plus en position 0 " <<endl; 
    if(monde.chars->getElement(21,1)->getTypeId()==4) cout<<"Le tank est en position 1 " <<endl;
    cout<<""<<endl;
    
  // if(monde.chars->getElement(1,1)==NULL)
    //if(monde.chars->getElement(50,1)->getTypeId()==4){
    
    Tank* tanktmp =(Tank*)(monde.chars->getElement(50,1));
    cout<<"Le tank a : "<<tanktmp->getPdv()<<"point de vie et appartient au joueur : "<<tanktmp->getJoueur()<<endl;
    Infanterie* inftmp =(Infanterie*)(monde.chars->getElement(1,1));
    cout<<"L'infanterie a : "<<inftmp->getAttaque()<<"point d'attaque et appartient au joueur : "<<inftmp->getJoueur()<<endl;
    engine::AttaqueCharCommand infAttaqueTank(1,50);
    infAttaqueTank.execute(monde);
    cout<<"Le tank a : "<<tanktmp->getPdv()<<"point de vie apres l'attaque "<<endl;
    cout<<""<<endl;
    
    
    cout<<"Le tank a : "<<tanktmp->getPdv()<<"point de vie et appartient au joueur : "<<tanktmp->getJoueur()<<endl;
    Infanterie* inftmp2 =(Infanterie*)(monde.chars->getElement(30,1));
    cout<<"L'infanterie a : "<<inftmp->getAttaque()<<"point d'attaque et appartient au joueur : "<<inftmp2->getJoueur()<<endl;
    engine::AttaqueCharCommand infAttaqueTank2(30,50);
    infAttaqueTank2.execute(monde);
    cout<<"Le tank a : "<<tanktmp->getPdv()<<"point de vie apres l'attaque "<<endl;
    cout<<""<<endl;
    
    
    
    cout<<"Le tank a : "<<tanktmp->getPdv()<<"point de vie et appartient au joueur : "<<tanktmp->getJoueur()<<endl;
    Heli* helitmp =(Heli*)(monde.chars->getElement(11,1));
    cout<<"L''heli a : "<<helitmp->getAttaque()<<"point d'attaque et appartient au joueur : "<<helitmp->getJoueur()<<endl;
    engine::AttaqueCharCommand heliAttaqueTank(11,50);
    heliAttaqueTank.execute(monde);
    cout<<"Le tank a : "<<tanktmp->getPdv()<<"point de vie apres l'attaque "<<endl;
    cout<<""<<endl;
    if(monde.chars->getElement(50,1)==NULL)cout<<"Le tank n'existe plus"<<endl;
    //Heli* helitmp =(Heli*)(monde.chars->getElement(10,1));
    cout<<""<<endl;
    
   
    cout<<"L'infanteire a : "<<inftmp2->getPdv()<<"point de vie et appartient au joueur : "<<inftmp2->getJoueur()<<endl;
    cout<<"L''heli a : "<<helitmp->getAttaque()<<"point d'attaque et appartient au joueur : "<<helitmp->getJoueur()<<endl;
    engine::AttaqueCharCommand heliAttaqueInf2(11,30);
    heliAttaqueInf2.execute(monde);
    cout<<"L'infanterie a : "<<tanktmp->getPdv()<<"point de vie apres l'attaque "<<endl;
    cout<<""<<endl;
    if(monde.chars->getElement(30,1)==NULL)cout<<"L'infanterie n'existe plus"<<endl;
    //Heli* helitmp =(Heli*)(monde.chars->getElement(10,1));
    cout<<""<<endl;
    
    //engine::AttaqueCharCommand bb(3,29);
    
   // }
    
    
      return 0;
    }
    
  }
  
  return 0;
}
