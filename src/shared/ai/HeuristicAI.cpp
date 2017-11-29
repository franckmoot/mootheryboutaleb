#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"
#include "engine/CapturCharCommand.h"
#include "Direction.h"
#include "Pathmap.h"
#include "state/State.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/MobileElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "engine/Engine.h"
#include "engine/EarnMoney.h"
#include "state/Champdebataille.h"
#include "AI.h"
#include "HeuristicAI.h"
#include <random>
#include <iostream>
#include <engine/Engine.h>



using namespace std;
using namespace state;
using namespace engine;

namespace ai {
        HeuristicAI::HeuristicAI() {

        }
        

       const Pathmap&  HeuristicAI::getInfmap (engine::Engine& engine,int joueur) const{
           /*
            
           this->infmap.init(*engine.currentState.grid);
           for (int j = 0; j < int(engine.currentState.getGrid()->getHeight()); j++) {
            for (int i = 0; i < int(engine.currentState.getGrid()->getWidth()); i++) { 
                
            }
                
            }
                    
           
        
            Point p1(1, 2, 0);
            Point p2(2, 15, 0);
            path.addSink(p1);
            path.addSink(p2);
            path.update(*monde.grid);*/
        }

    void HeuristicAI::run(int joueur, engine::Engine& engine) {
        
         for (int j = 0; j < int(engine.currentState.getChars()->getHeight()); j++) {
            for (int i = 0; i < int(engine.currentState.getChars()->getWidth()); i++) {
                
                if (engine.currentState.getChars()->getElement(i, j) != NULL) {
                   
                    if ((engine.currentState.getChars()->getElement(i, j)->getTypeId() == 2) && (engine.currentState.getChars()->getElement(i, j)->getJoueur() == joueur)) {
                        Infanterie* eletmp = (Infanterie*)(engine.currentState.getChars()->getElement(i, j));
                        for (int x2 = (i - eletmp->getPorteeMvt()); x2 < (i + eletmp->getPorteeMvt()); x2++) {
                            for (int y2 = (j - eletmp->getPorteeMvt()); y2 < (j + eletmp->getPorteeMvt()); y2++){
                                 
                                if((engine.currentState.getGrid()->getElement(i, j)->getTypeId()==1)&&(engine.currentState.getGrid()->getElement(i, j)->getJoueur()!=joueur)){
                                    engine::CapturCharCommand *C=new CapturCharCommand(i,j);
                                    C->execute(engine.currentState);
                                 }
                                else if ((x2 >= 0)&&(y2 >= 0)&&(x2<int(engine.currentState.getGrid()->getWidth()))&&(y2<int(engine.currentState.getGrid()->getHeight()))&&(engine.currentState.getChars()->getElement(x2, y2) != NULL)&&(joueur !=engine.currentState.getChars()->getElement(x2, y2)->getJoueur())) {
                                    engine::AttaqueCharCommand *A=new AttaqueCharCommand(i,j,x2,y2);
                                    A->execute(engine.currentState); 
                                }
                                else{  
                                    
                                }       
                        }       
                    }    
                            
                }     

                    else if (engine.currentState.getChars()->getElement(i, j)->getTypeId() == 3 && engine.currentState.getChars()->getElement(i, j)->getJoueur() == joueur) {

                    } else if (engine.currentState.getChars()->getElement(i, j)->getTypeId() == 4 && engine.currentState.getChars()->getElement(i, j)->getJoueur() == joueur) {


                    }
                }

            }
        }
        
        
        
        
        

    }
    
}