#include "touteslesfonctions.h"
#include "state/ElementChars.h"
#include "render/Layer.h"


void teststate (){
  
  
  /* init monde */
  State monde;
  
  (monde.grid)=new ElementTab(); 
  (monde.chars)=new ElementChars();
  /* Init list charactere */
  cout << "Fabrique une list de charactere" << endl;
  Infanterie *I=new Infanterie();
  //ElementChars *T=new ElementChars();
  
  /* Infanterie */
  cout << "Verifie que la liste est null" << endl;
  if(monde.chars->sizeList()==0) cout << "Ok" << endl;
  cout << "On ajoute un Element de type Infanterie" << endl;
  monde.chars->setElement(I);
  cout << "Verifie que la liste est 1" << endl;
  if(monde.chars->sizeList()==1) cout << "Ok" << endl;
  cout << "Verifie que l'element ajouter est une infanterie" << endl;
  if(monde.chars->getElement(0,0)->getTypeId()==2) cout<<"Ok" <<endl;
  
  /* tank */
  Tank *Ta=new Tank();
  cout << "On ajoute un Element de type Tank" << endl;
  monde.chars->setElement(Ta);
  cout << "Verifie que la liste est 2" << endl;
  if(monde.chars->sizeList()==2) cout << "Ok" << endl;
  cout << "Verifie que l'element ajouter est un Tank" << endl;
  if(monde.chars->getElement(1,1)->getTypeId()==4) cout<<"Ok" <<endl;
  
      
  /* Heli */
  Heli *H=new Heli();
  cout << "On ajoute un Element de type Heli" << endl;
  monde.chars->setElement(H);
  cout << "Verifie que la liste est 3" << endl;
  if(monde.chars->sizeList()==3) cout << "Ok" << endl;
  cout << "Verifie que l'element ajouter est un Tank" << endl;
  if(monde.chars->getElement(1,2)->getTypeId()==3) cout<<"Ok" <<endl;
  
  
  /*remplissage de null*/
  cout << "On rempli la liste de chars par 5 elements vide" << endl;
  for(int i=0;i<5;i++){
    monde.chars->setElement(NULL);
  }
  cout << "Verifie que la liste est 8" << endl;
  if(monde.chars->sizeList()==8) cout << "Ok" << endl;
  
  cout << "Deplacement du tank" << endl;
  monde.chars->chgList2(2,7);
  cout << "Verifie que le tank est a la 8eme place" << endl;
  if(monde.chars->getElement(1,7)->getTypeId()==3) cout<<"Ok" <<endl;
  cout << "Verifie que à la place du tank on a un element vide" << endl;
  if(monde.chars->getElement(1,2)==NULL) cout<<"Ok" <<endl;
  
  /* Ajoue d'un element heli a la 7eme place */
  Heli *H2=new Heli();
  cout << "Ajoue d'un Heli à la 6eme place" << endl;
  monde.chars->chgList(6,H2);
  cout << "Verifie que Heli est a la 6eme place" << endl;
  if(monde.chars->getElement(1,6)->getTypeId()==3) cout<<"Ok" <<endl;
  
  
  /* init element static*/
  cout << "Fabrique une list d'Element static" << endl;
  Batiment *B=new Batiment();
  
  /*batiment */
  cout << "Verifie que la liste est null" << endl;
  if(monde.grid->sizeList()==0) cout << "Ok" << endl;
  cout << "On ajoute un Element de type Batiment" << endl;
  monde.grid->setElement(B);
  cout << "Verifie que la liste est 1" << endl;
  if(monde.grid->sizeList()==1) cout << "Ok" << endl;
  cout << "Verifie que l'element ajouter est une Batiment" << endl;
  if(monde.grid->getElement(0,0)->getTypeId()==1) cout<<"Ok" <<endl;
  
  /* Champdebataille */
  Champdebataille *C=new Champdebataille();
  cout << "On ajoute un Element de type Heli" << endl;
  monde.grid->setElement(C);
  cout << "Verifie que la liste est 2" << endl;
  if(monde.grid->sizeList()==2) cout << "Ok" << endl;
  cout << "Verifie que l'element ajouter est un champdebataille" << endl;
  if(monde.grid->getElement(1,1)->getTypeId()==0) cout<<"Ok" <<endl;
  
  
  /* batiment caserne */
  Batiment *C2=new Batiment(BatimentTypeId::CASERNE);
  cout << "On ajoute un Element de type Batiment" << endl;
  monde.grid->setElement(C2);
  cout << "Verifie que la liste est 3" << endl;
  if(monde.grid->sizeList()==3) cout << "Ok" << endl;
  cout << "Verifie que l'element ajouter est un Batiment caserne" << endl;
  if(monde.grid->getElement(1,2)->getType()==BatimentTypeId::CASERNE) cout<<"Ok" <<endl;
  
}


void testcreateelement(){
   
  State monde;
    
  std::vector<int> macarte; 
  (monde.grid)=new ElementTab(); 
  (monde.chars)=new ElementChars(10,10);
  cout<<"La liste de chars fait : "<<monde.chars->sizeList()<<endl;
  
  
  for(int i=0;i<10;i++){
    monde.chars->setElement(NULL);
  }
  Heli *H=new Heli();
  Infanterie *I=new Infanterie();
  Tank *T=new Tank();
  Heli *He=new Heli();
  Infanterie *In=new Infanterie();
  Tank *Ta=new Tank();
  
  monde.chars->chgList(2,H);
  
  monde.chars->chgList(13,T);
  monde.chars->chgList(17,I);
  monde.chars->chgList(29,He);
  monde.chars->chgList(50,Ta);
  monde.chars->chgList(98,In); 
  cout<<monde.chars->sizeList()<<endl;
  std::vector<int> carte;
  
  carte=monde.chars->ElementToCarte(carte);
  
  
    
}
     
 
void testrender(){
    
    sf::RenderWindow window(sf::VideoMode(640, 640), "Advance wars");
    
    Layer layer1;
    layer1.initRandMap();
    
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
	  //window.draw(map);
	  window.draw(*(layer1.getTilemap().get()));
	  window.display();
	  
	}
    
    
    
    
}


void testload(){
  
  
  
  
}

