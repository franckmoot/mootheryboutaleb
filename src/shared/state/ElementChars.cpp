#include "ElementChars.h"
#include "Infanterie.h"
#include "Tank.h"
#include "Heli.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>


namespace state{
        ElementChars::ElementChars() {

    }
         void ElementTab::createElementCsv(std::vector<int> carte){
                    std::ifstream fichier;
            
    	
      
            fichier.open("res/map1.csv",std::ios::in);
            if(!fichier.good())
                 throw std::runtime_error("Error opening!!");
        std::string ligne,valeur;
       
       // int i = 0;
		
        while(!fichier.eof()){
            std::getline(fichier,ligne);
            std::stringstream stream(ligne);
            std::cout << ligne << std::endl;

		
            while(getline(stream, valeur,',')){
			
                carte.push_back(atoi(valeur.c_str()));
			
            }
        }
    
    for(int i=0; i<int(carte.size()) ; i++){
            if(carte[i]==-1) {
                list.push_back(NULL);
            }
            if(carte[i]==7){
                list.push_back(new Infanterie);
            }
            if(carte[i]==8){
                list.push_back(new Heli);
            }
            if(carte[i]==7){
                list.push_back(new Tank);
            }
            else{
                list.push_back(NULL);
            }
    }    
}
}
  

