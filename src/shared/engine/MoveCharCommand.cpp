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
#include "MoveCharCommand.h"
#include "CommandTypeId.h"
#include "Command.h"

using namespace std;
using namespace state;
namespace engine{
    
    
    MoveCharCommand::MoveCharCommand(int i, int j){
        this->i=i;
        this->j=j;
        
    }
    
    void MoveCharCommand::execute(state::State& state){
        int i=this->i;
        int j=this->j;
      
       
        
       if(state.getChars()->getElement(j,1)!=NULL & state.getChars()->getElement(i,1)==NULL ) cout<< "c'est impossible "<<endl;
        else{
            cout<<"je segmente1"<<endl;
            if(state.getChars()->getElement(i,1)->getTypeId()==3){
                cout<<"je segmente2"<<endl;
                state.getChars()->chgList2(i,j);
                cout<<"je segmente3"<<endl;
            }
            else if (state.getChars()->getElement(i,1)->getTypeId()==4){
                cout<<"je segmente4"<<endl;
               if(state.getGrid()->getElement(j,1)->getType()==BatimentTypeId::CASERNE  || state.getGrid()->getElement(j,1)->getType()==BatimentTypeId::QG || state.getGrid()->getElement(j,1)->getType()==ChampdebatailleTypeId::EAU){
                   cout<< "c'est impossible de mettre un element mobile sur ces elments static"<<endl;
               }  
               else {
                   state.getChars()->chgList2(i,j);
               }
            }
            else if (state.getChars()->getElement(i,1)->getTypeId()==2){
               if(state.getGrid()->getElement(j,1)->getType()==BatimentTypeId::CASERNE  || state.getGrid()->getElement(j,1)->getType()==BatimentTypeId::QG || state.getGrid()->getElement(j,1)->getType()==ChampdebatailleTypeId::EAU || state.getGrid()->getElement(j,1)->getType()==ChampdebatailleTypeId::ROCHER){
                   cout<< "c'est impossible de mettre un element mobile sur cette elments static"<<endl;
               }  
               else {
                   state.getChars()->chgList2(i,j);
                        
                    }
            }
            
        }
        
        
    }
    
    
    
     CommandTypeId MoveCharCommand::getTypeId() const{
        return CommandTypeId::MOVE ;
         
     }  



}


  
   
    
    
    
    
    
