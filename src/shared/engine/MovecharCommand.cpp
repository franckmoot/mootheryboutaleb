#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <sstream>
#include "render/CharsTileSet.h"
#include "render/GridTileSet.h"
#include "render/Tile.h"
#include "render/Tilemap.h"
#include "state/Batiment.h"
#include "state/Champdebataille.h"
#include "state/Element.h"
#include "state/ElementChars.h"
#include "state/ElementTab.h"
#include "state/MobileElement.h"
#include "state/StaticElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/State.h"
#include "MovecharCommand.h"
#include "CommandTypeId.h"

using namespace std;
using namespace state;
namespace engine{
    
    void MovecharCommand::bouger(state::State& state, int i1, int j1,int i2,int j2){
        if(state.getChars()->getElement(i2,j2)->getTypeId()>0) cout<< "c'est impossible de mettre un element mobile sur un element mobile"<<endl;
        else{
            if(state.getChars()->getElement(i1,j1)->getTypeId()==3){
                state.getChars()->chgList2(i1*j1,i2*j2);
            }
            else if (state.getChars()->getElement(i1,j1)->getTypeId()==4){
               if(state.getGrid()->getElement(i2,j2)->getType()==BatimentTypeId::CASERNE  || state.getGrid()->getElement(i2,j2)->getType()==BatimentTypeId::QG || state.getGrid()->getElement(i2,j2)->getType()==ChampdebatailleTypeId::EAU){
                   cout<< "c'est impossible de mettre un element mobile sur ces elments static"<<endl;
               }  
               else {
                   state.getChars()->chgList2(i1*j1,i2*j2);
               }
            }
            else if (state.getChars()->getElement(i1,j1)->getTypeId()==2){
               if(state.getGrid()->getElement(i2,j2)->getType()==BatimentTypeId::CASERNE  || state.getGrid()->getElement(i2,j2)->getType()==BatimentTypeId::QG || state.getGrid()->getElement(i2,j2)->getType()==ChampdebatailleTypeId::EAU || state.getGrid()->getElement(i2,j2)->getType()==ChampdebatailleTypeId::ROCHER){
                   cout<< "c'est impossible de mettre un element mobile sur ces elments static"<<endl;
               }  
               else {
                   state.getChars()->chgList2(i1*j1,i2*j2);
                        
                    }
            }
            
        }
        
        
    }
    
    
    
    void MovecharCommand::execute(state::State& state){
        
    }
       
     CommandTypeId MovecharCommand::getTypeId() const{
        return CommandTypeId::MOVE ;
         
     }  



}


  
   
    
    
    
    
    
