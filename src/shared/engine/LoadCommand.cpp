#include <fstream>
#include <iostream>
#include <string>
#include "LoadCommand.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/ElementTab.h"
#include "state/Champdebataille.h"
#include "state/Batiment.h"
#include <vector>

#include <sstream>


using namespace std;
namespace engine{
    LoadCommand::LoadCommand (const char* f){
        this->filename=f;
        
        
        
    }

    void LoadCommand::execute(state::State& state) {
        std::vector<int> carte;
        std::ifstream fichier;
    fichier.open(filename,std::ios::in);
    if(!fichier.good())
      throw std::runtime_error("Error opening!!");
    std::string ligne,valeur;
    
    while(!fichier.eof()){
      std::getline(fichier,ligne);
      std::stringstream stream(ligne);
      std::cout << ligne << std::endl;
      
      while(getline(stream, valeur,',')){	
	carte.push_back(atoi(valeur.c_str()));
      }
    }
    
    for(int i=0; i<int(carte.size()) ; i++){
      switch (carte[i]){
	
      case 0:
	state.getGrid()->setElement(new state::Champdebataille(state::ChampdebatailleTypeId::HERBE));
	break;
	
      case 1:     
	state.getGrid()->setElement(new state::Champdebataille(state::ChampdebatailleTypeId::ROUTE));
	break;
	
      case 2:
	state.getGrid()->setElement(new state::Champdebataille(state::ChampdebatailleTypeId::SABLE1));
	break;
        
      case 3:
	state.getGrid()->setElement(new state::Champdebataille(state::ChampdebatailleTypeId::SABLE2));
	break;  
        
      case 4:
	state.getGrid()->setElement(new state::Champdebataille(state::ChampdebatailleTypeId::EAU));
	break;
        
      case 5:
	state.getGrid()->setElement(new state::Champdebataille(state::ChampdebatailleTypeId::MONTAGNE));
	break;
        
      case 6:
	state.getGrid()->setElement(new state::Batiment(state::BatimentTypeId::QG));
	break;
        
      case 7:
	state.getGrid()->setElement(new state::Batiment(state::BatimentTypeId::CASERNE));
	break;
        
      default:
	state.getGrid()->setElement(NULL);
	break; 
      }
    }
  
  }
  

    
    
    CommandTypeId LoadCommand::getTypeId() const {
        return CommandTypeId::LOAD;
    }
   
}
    
    