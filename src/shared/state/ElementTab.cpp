#include "ElementTab.h"
#include "Champdebataille.h"
#include "Batiment.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

namespace state{

    ElementTab::ElementTab() {
       
    }
    
    ElementTab::ElementTab(size_t width, size_t height) {
            vector<unique_ptr<Element> > list(width*height);
    }
    
    int ElementTab::sizeList() {
        return list.size();
    }

    
    void ElementTab::setElement( Element* e) {
        list.push_back(unique_ptr<Element>(e));
    }
    
    Element *  ElementTab::getElement(int i,int j) const {

           return list[i*j].get();
    }
    

    size_t ElementTab::getHeight() {
        return height;
    }
    
    size_t ElementTab::getWidth() {
        return width;
    }

    ElementTab::~ElementTab() {

    }
    
    void ElementTab::chgList(int i, Element* e) {
         
            if(list[i]==NULL) list[i]=unique_ptr<Element>(e);
                       
    }

    void ElementTab::chgList2(int i, int j) {

        if(int(list.size())>=i&&int(list.size())>=j){
            if(list[i]!=NULL){
                if(list[j]==NULL) {
                list[j].swap(list[i]);
                }
            }
            else std::cout << "Erreur sur le deplacement !" << std::endl;
        }
         else std::cout << "Deplacement hors list" << std::endl;
    }

        const std::vector<int> ElementTab::createElementCsv( std::vector<int> carte){
            std::ifstream fichier;
            fichier.open("res/map2.csv",std::ios::in);
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
            if(carte[i]==0) {
                list.push_back(std::unique_ptr<Element>(new Champdebataille(HERBE)));
            }
           if(carte[i]==1){
                
                list.push_back(std::unique_ptr<Element>(new Champdebataille(ROUTE)));
            }
            
            if(carte[i]==2){
                list.push_back(std::unique_ptr<Element>(new Champdebataille(SABLE)));
            }
            
            if(carte[i]==3){ 
                list.push_back(std::unique_ptr<Element>(new Champdebataille(EAU)));
            }
            
            if(carte[i]==4){
                list.push_back(std::unique_ptr<Element>(new Champdebataille(ROCHER)));
            }
            if(carte[i]==5){
                list.push_back(std::unique_ptr<Element>(new Batiment(CASERNE)));
            }
            
            if(carte[i]==6){
                list.push_back(std::unique_ptr<Element>(new Batiment(QG)));
            }
            else{
                list.push_back(NULL);
                }  
    
        }
                    return carte;
    }

    
}

