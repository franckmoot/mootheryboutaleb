#include "touteslesfonctions.h"
#include "state/ElementChars.h"
#include "render/Layer.h"
#include "engine/Engine.h"
#include "ai/RandomAI.h"
#include "engine/MoveCharCommand.h"
#include "engine/Engine.h"
#include "engine/LoadCommand.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/CapturCharCommand.h"
#include "engine/CreateCharCommand.h"


using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;

void teststate() {

    /* init monde */
    State monde;

    (monde.grid) = new ElementTab();
    (monde.chars) = new ElementChars();
    /* Init list charactere */
    cout << "Fabrique une list de charactere" << endl;
    Infanterie *I = new Infanterie();

    /* Infanterie */
    cout << "On ajoute un Element de type Infanterie" << endl;
    monde.chars->setElementXY(I, 0, 0);
    cout << "Verifie que l'element ajouter est une infanterie" << endl;
    if (monde.chars->getElement(0, 0)->getTypeId() == INFANTERIE) cout << "Ok" << endl;

    /* tank */
    Tank *Ta = new Tank();
    cout << "On ajoute un Element de type Tank" << endl;
    monde.chars->setElementXY(Ta, 1, 0);
    cout << "Verifie que l'element ajouter est un Tank" << endl;
    if (monde.chars->getElement(1, 0)->getTypeId() == TANK) cout << "Ok" << endl;


    /* Heli */
    Heli *H = new Heli();
    cout << "On ajoute un Element de type Heli" << endl;
    monde.chars->setElementXY(H, 2, 0);
    cout << "Verifie que l'element ajouter est un Tank" << endl;
    if (monde.chars->getElement(2, 0)->getTypeId() == HELI) cout << "Ok" << endl;

    cout << "Deplacement du tank" << endl;
    monde.chars->chgPosition(1, 0, 3, 3);
    cout << "Verifie que le tank est a la 4eme ligne et 4 eme colone" << endl;
    if (monde.chars->getElement(3, 3)->getTypeId() == TANK) cout << "Ok" << endl;
    cout << "Verifie que à la place du tank on a un element vide" << endl;
    if (monde.chars->getElement(1, 0) == NULL) cout << "Ok" << endl;

    /* Ajoue d'un element heli a la 7eme place */
    Heli *H2 = new Heli();
    cout << "Ajoue d'un Heli à la 6eme place" << endl;
    monde.chars->setElementXY(H2, 2, 2);
    cout << "Verifie que Heli est a la 6eme place" << endl;
    if (monde.chars->getElement(2, 2)->getTypeId() == HELI) cout << "Ok" << endl;


    /* init element static*/
    cout << "Fabrique une list d'Element static" << endl;
    Batiment *B = new Batiment();

    /*batiment */
    cout << "Verifie que la liste est null" << endl;
    if (monde.grid->sizeList() == 0) cout << "Ok" << endl;
    cout << "On ajoute un Element de type Batiment" << endl;
    monde.grid->setElement(B);
    cout << "Verifie que la liste est 1" << endl;
    if (monde.grid->sizeList() == 1) cout << "Ok" << endl;
    cout << "Verifie que l'element ajouter est une Batiment" << endl;
    if (monde.grid->getElement(0, 0)->getTypeId() == BATIMENT) cout << "Ok" << endl;

    /* Champdebataille */
    Champdebataille *C = new Champdebataille();
    cout << "On ajoute un Element de type chamdebataille" << endl;
    monde.grid->setElement(C);
    cout << "Verifie que la liste est 2" << endl;
    if (monde.grid->sizeList() == 2) cout << "Ok" << endl;
    cout << "Verifie que l'element ajouter est un champdebataille" << endl;
    if (monde.grid->getElement(1, 0)->getTypeId() == CHAMPSDEBATAILLE) cout << "Ok" << endl;


    /* batiment caserne */
    Batiment *C2 = new Batiment(BatimentTypeId::CASERNE);
    cout << "On ajoute un Element de type Batiment" << endl;
    monde.grid->setElement(C2);
    cout << "Verifie que la liste est 3" << endl;
    if (monde.grid->sizeList() == 3) cout << "Ok" << endl;
    cout << "Verifie que l'element ajouter est un Batiment caserne" << endl;
    if (monde.grid->getElement(2, 0)->getTypeId() == int(BatimentTypeId::CASERNE)) cout << "Ok" << endl;

}

void testrender() {
    sf::RenderWindow window(sf::VideoMode(640, 640), "Advance wars");
    Heli *H = new Heli();

    Infanterie *I = new Infanterie();
    Tank *T = new Tank();
    Heli *He = new Heli();
    Infanterie *In = new Infanterie();
    Tank *Ta = new Tank();
    Tank *Tan = new Tank();
    Heli *Ha = new Heli();
    Infanterie *Ia = new Infanterie();
    Tank *To = new Tank();
    Heli *Hez = new Heli();
    Infanterie *Ina = new Infanterie();
    Tank *Tae = new Tank();
    Tank *Tanz = new Tank();
    State monde;

    (monde.grid) = new ElementTab();
    (monde.chars) = new ElementChars();
    H->setJoueur(1);
    T->setJoueur(1);
    I->setJoueur(1);
    Ina->setJoueur(1);
    He->setJoueur(2);
    Ta->setJoueur(1);
    In->setJoueur(1);
    Tan->setJoueur(2);
    Tae->setJoueur(2);
    Tanz->setJoueur(1);
    Hez->setJoueur(2);
    To->setJoueur(1);
    Ia->setJoueur(1);

    monde.chars->setElementXY(H, 0, 0);
    monde.chars->setElementXY(T, 0, 19);
    monde.chars->setElementXY(I, 1, 2);
    monde.chars->setElementXY(He, 2, 15);
    monde.chars->setElementXY(Ta, 3, 4);
    monde.chars->setElementXY(In, 8, 8);
    monde.chars->setElementXY(Ina, 9, 0);
    monde.chars->setElementXY(Tan, 11, 3);
    monde.chars->setElementXY(Tae, 12, 7);
    monde.chars->setElementXY(To, 14, 15);
    monde.chars->setElementXY(Tanz, 17, 2);
    monde.chars->setElementXY(Hez, 18, 9);
    monde.chars->setElementXY(Ta, 10, 10);
    monde.chars->setElementXY(Ha, 19, 0);

    std::vector<int> liste;
    monde.grid->createElementCsv(liste);


    Layer surf(monde);
    surf.initSurface();
    while (window.isOpen()) {

        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(*(surf.surface));
        window.draw(*(surf.surfaceplayer));
        window.display();

    }
}

void testengine() {

    engine::Engine i;

   /* i.addCommand(new engine::LoadCommand("res/map.csv"));
    i.addCommand(new engine::CreateCharCommand(0, INFANTERIE, 1));
    i.addCommand(new engine::CreateCharCommand(30, INFANTERIE, 1));
    i.addCommand(new engine::MoveCharCommand(0, 30));*/

    // i.update();

    /*Layer surf(i.getState());
    surf.initSurface();
    surf.initSurface();*/

    State monde = i.getState();
    /* engine::LoadCommand a("res/map.csv");

     (monde.chars) = new ElementChars(9, 11);

     Infanterie *I = new Infanterie();
     I->setJoueur(1);
     Heli *H = new Heli();
     H->setJoueur(1);
     Tank *T = new Tank();
     T->setJoueur(1);

     Infanterie *I2 = new Infanterie();
     I2->setJoueur(2);
     Heli *H2 = new Heli();
     H2->setJoueur(2);
     Tank *T2 = new Tank();
     T2->setJoueur(2);

     monde.chars->chgList(0, I); //ajoute des elements

     monde.chars->chgList(10, H);
     monde.chars->chgList(20, T);
     monde.chars->chgList(30, I2);
     monde.chars->chgList(40, H2);
     monde.chars->chgList(50, T2);


     engine::CreateCharCommand infanteriejoueur1(0, INFANTERIE, 1);
     infanteriejoueur1.execute(monde);

     engine::CreateCharCommand infanteriejoueur2(30, INFANTERIE, 2);
     infanteriejoueur2.execute(monde);

     engine::CreateCharCommand Helijoueur1(10, HELI, 1);
     Helijoueur1.execute(monde);

     engine::CreateCharCommand Helijoueur2(40, HELI, 2);
     Helijoueur2.execute(monde);

     engine::CreateCharCommand Tankjoueur1(20, TANK, 1);
     Tankjoueur1.execute(monde);

     engine::CreateCharCommand Tankjoueur2(50, TANK, 2);
     Tankjoueur2.execute(monde);

     if (monde.chars->getElement(0, 1)->getTypeId() == 2) cout << "L'infanterie est en position 0 " << endl;
     engine::MoveCharCommand deplacementinfanterie(0, 1);
     deplacementinfanterie.execute(monde);
     cout << "L'infanterie se deplace " << endl;
     if (monde.chars->getElement(0, 1) == NULL)cout << "L'infanterie se n'est plus en position 0 " << endl;
     if (monde.chars->getElement(1, 1)->getTypeId() == 2) cout << "L'infanterie est en position 1 " << endl;
     cout << "" << endl;

     if (monde.chars->getElement(10, 1)->getTypeId() == 3) cout << "L'heli est en position 10 " << endl;
     engine::MoveCharCommand deplacementheli(10, 11);
     deplacementheli.execute(monde);
     cout << "L'heli se deplace " << endl;
     if (monde.chars->getElement(10, 1) == NULL)cout << "L'heli n'est plus en position 10 " << endl;
     if (monde.chars->getElement(11, 1)->getTypeId() == 3) cout << "L'heli est en position 11 " << endl;
     cout << "" << endl;

     if (monde.chars->getElement(20, 1)->getTypeId() == 4) cout << "Le tank est en position 0 " << endl;
     engine::MoveCharCommand deplacementtank(20, 21);
     deplacementtank.execute(monde);
     cout << "Le tank se deplace " << endl;
     if (monde.chars->getElement(20, 1) == NULL)cout << "Le tank n'est plus en position 0 " << endl;
     if (monde.chars->getElement(21, 1)->getTypeId() == 4) cout << "Le tank est en position 1 " << endl;
     cout << "" << endl;
     // if(monde.chars->getElement(1,1)==NULL)
     //if(monde.chars->getElement(50,1)->getTypeId()==4){

     Tank* tanktmp = (Tank*) (monde.chars->getElement(50, 1));
     cout << "Le tank a : " << tanktmp->getPdv() << "point de vie et appartient au joueur : " << tanktmp->getJoueur() << endl;
     Infanterie* inftmp = (Infanterie*) (monde.chars->getElement(1, 1));
     cout << "L'infanterie a : " << inftmp->getAttaque() << "point d'attaque et appartient au joueur : " << inftmp->getJoueur() << endl;
     engine::AttaqueCharCommand infAttaqueTank(1, 50);
     infAttaqueTank.execute(monde);
     cout << "Le tank a : " << tanktmp->getPdv() << "point de vie apres l'attaque " << endl;
     cout << "" << endl;

     cout << "Le tank a : " << tanktmp->getPdv() << "point de vie et appartient au joueur : " << tanktmp->getJoueur() << endl;
     Infanterie* inftmp2 = (Infanterie*) (monde.chars->getElement(30, 1));
     cout << "L'infanterie a : " << inftmp->getAttaque() << "point d'attaque et appartient au joueur : " << inftmp2->getJoueur() << endl;
     engine::AttaqueCharCommand infAttaqueTank2(30, 50);
     infAttaqueTank2.execute(monde);
     cout << "Le tank a : " << tanktmp->getPdv() << "point de vie apres l'attaque " << endl;
     cout << "" << endl;

     cout << "Le tank a : " << tanktmp->getPdv() << "point de vie et appartient au joueur : " << tanktmp->getJoueur() << endl;
     Heli* helitmp = (Heli*) (monde.chars->getElement(11, 1));
     cout << "L''heli a : " << helitmp->getAttaque() << "point d'attaque et appartient au joueur : " << helitmp->getJoueur() << endl;
     engine::AttaqueCharCommand heliAttaqueTank(11, 50);
     heliAttaqueTank.execute(monde);
     cout << "Le tank a : " << tanktmp->getPdv() << "point de vie apres l'attaque " << endl;
     cout << "" << endl;
     if (monde.chars->getElement(50, 1) == NULL)cout << "Le tank n'existe plus" << endl;
     //Heli* helitmp =(Heli*)(monde.chars->getElement(10,1));
     cout << "" << endl;

     cout << "L'infanteire a : " << inftmp2->getPdv() << "point de vie et appartient au joueur : " << inftmp2->getJoueur() << endl;
     cout << "L''heli a : " << helitmp->getAttaque() << "point d'attaque et appartient au joueur : " << helitmp->getJoueur() << endl;
     engine::AttaqueCharCommand heliAttaqueInf2(11, 30);
     heliAttaqueInf2.execute(monde);
     cout << "L'infanterie a : " << tanktmp->getPdv() << "point de vie apres l'attaque " << endl;
     cout << "" << endl;
     if (monde.chars->getElement(30, 1) == NULL)cout << "L'infanterie n'existe plus" << endl;
     //Heli* helitmp =(Heli*)(monde.chars->getElement(10,1));
     cout << "" << endl;
     */
}

void testai() {
    /*
        sf::RenderWindow window(sf::VideoMode(640, 640), "Advance wars");

        State monde;

        (monde.grid) = new ElementTab();
        (monde.chars) = new ElementChars();

        int joueur1 = 1;
        int joueur2 = 2;


        std::vector<int> liste;
        monde.grid->createElementCsv(liste);

        Layer surf(monde);
        surf.initSurface();
        RandomAI test;
        RandomAI test1;


        surf.initSurface();
        while (window.isOpen()) {

            // on gère les évènements
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {// presser bouton gauche
                // la touche "flèche gauche" est enfoncée : on bouge le personnage
                cout << "JOUEUR1 joue::" << endl;

                //sleep(2);
                test.run(monde, joueur1);

                sf::sleep(sf::milliseconds(500));
                surf.initSurface();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {//presser bouton droit
                // la touche "flèche gauche" est enfoncée : on bouge le personnage
                cout << "JOUEUR2 joue::" << endl;

                //sleep(2);

                test1.run(monde, joueur2);
                sf::sleep(sf::milliseconds(500));
                surf.initSurface();
            }


            window.clear();
            window.draw(*(surf.surface));
            window.draw(*(surf.surfaceplayer));
            window.display();
     */
}

void testcommande() {
    /*  sf::RenderWindow window(sf::VideoMode(640, 640), "Advance wars");
      engine::Engine i;


      i.addCommand(new engine::LoadCommand("res/map.csv"));
      i.addCommand(new engine::CreateCharCommand(0, INFANTERIE, 1));
      i.addCommand(new engine::CreateCharCommand(30, INFANTERIE, 1));
      i.addCommand(new engine::MoveCharCommand(0, 30));
      cout << "je suis" << endl;
      i.update();

      Layer surf(i.getState());
      surf.initSurface();
      surf.initSurface();
      while (window.isOpen()) {

          // on gère les évènements
          sf::Event event;
          while (window.pollEvent(event)) {
              if (event.type == sf::Event::Closed)
                  window.close();
          }

          window.clear();
          window.draw(*(surf.surface));
          window.draw(*(surf.surfaceplayer));
          window.display();*/

}

