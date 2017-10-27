#include "ElementTab.h"
#include <iostream>


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
}