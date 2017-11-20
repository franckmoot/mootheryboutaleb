#include <string>
#include <iostream>
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/Batiment.h"
#include "CreateCharCommand.h"
#include "state/TypeId.h"



using namespace std;
using namespace state;
namespace engine {

    CreateCharCommand::CreateCharCommand( state::TypeId d, int joueur){

    }

    CommandTypeId CreateCharCommand::getTypeId() const {
        return CommandTypeId::ATTAQUE;
    }

    void CreateCharCommand::execute(state::State& state) {
        if(joueur==1){
        for(int i=0;i<state.grid->getWidth();i++){
            for(int j=0;j<state.chars->getHeight();i++){
                if((state.grid->getElement(i,j)->getTypeId()==1)&& (state.chars->getElement(i,j)==NULL)){
                    if (d == 2) {
                        Infanterie *I = new Infanterie();
                        I->setJoueur(1);
                        state.chars->setElementXY(I,x,y);
                        
                    }
                    if (d == 3) {
                        Heli *H = new Heli();
                        H->setJoueur(1);
                        state.chars->setElementXY(H,x,y);

                    }
                    if (d == 4) {
                        Tank *T = new Tank();
                        T->setJoueur(1);
                        state.chars->setElementXY(T,x,y);
                    }   
                }
                        
            }
        }
        }
        if(joueur==2){
        for(int i=0;i<state.grid->getWidth();i++){
            for(int j=0;j<state.chars->getHeight();i++){
                if((state.grid->getElement(i,j)->getTypeId()==1)&& (state.chars->getElement(i,j)==NULL)){
                    if (d == 2) {
                        Infanterie *I = new Infanterie();
                        I->setJoueur(2);
                        state.chars->setElementXY(I,x,y);
                        
                    }
                    if (d == 3) {
                        Heli *H = new Heli();
                        H->setJoueur(2);
                        state.chars->setElementXY(H,x,y);

                    }
                    if (d == 4) {
                        Tank *T = new Tank();
                        T->setJoueur(2);
                        state.chars->setElementXY(T,x,y);
                    }   
                }
                        
            }
        }
        }



    }
}