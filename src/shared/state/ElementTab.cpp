#include "ElementTab.h"
#include "Champdebataille.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

namespace state{

    ElementTab::ElementTab() {
       
    }
    
    ElementTab::ElementTab(size_t width, size_t height) {
            std::vector<Element*> list(width*height);
    }
    
    int ElementTab::sizeList() {
        return list.size();
    }

    
    void ElementTab::setElement( Element* e) {
        list.push_back(e);
    }
    
    Element * const ElementTab::getElement(int i, int j) {
        Element *n=NULL;
       if (list[i*j]!=NULL)return list[i*j];
       //if (list[i*j]==NULL)
        return n;
    
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
         
            if(list[i]==NULL) list[i]=e;
                       
    }

    void ElementTab::chgList2(int i, int j) {

        if(int(list.size())>=i&&int(list.size())>=j){
            if(list[i]!=NULL){
                if(list[j]==NULL) {
                list[j]=list[i];
                list[i]=NULL;
                }
            }
            else std::cout << "Erreur sur le deplacement !" << std::endl;
        }
         else std::cout << "Deplacement hors list" << std::endl;
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
            if(carte[i]==0) {
                Champdebataille *C=new Champdebataille(HERBE);
                list.push_back(*C);
            }
            if(carte[i]==1){
                Champdebataille *D=new Champdebataille(ROUTE);
                list.push_back(*D);
            }
            
            if(carte[i]==2){
                Champdebataille *E=new Champdebataille(SABLE);
                list.push_back(*E);
            }
            
            if(carte[i]==3){ 
                Champdebataille *F=new Champdebataille(EAU);
                list.push_back(*F);
            }
            
            if(carte[i]==4){
                Champdebataille *G=new Champdebataille(ROCHER);
                list.push_back(*G);
            }
            if(carte[i]==5){
                Batiment *H=new Batiment(CASERNE);
                list.push_back(*H);
            }
            
            if(carte[i]==6){
                Batiment *I=new Batiment(QG);
                list.push_back(*I);
            }
            if(carte[i]==7){
                Infanterie *J=new Infanterie();
                list.push_back(*J);
            }
            if(carte[i]==8){
                Heli *K=new Heli();
                list.push_back(*K);
            }
            if(carte[i]==7){
                Tank *L=new Tank();
                list.push_back(*L);
            }
    }  
    
}
}    