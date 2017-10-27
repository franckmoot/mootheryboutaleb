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
    
    Element * const ElementTab::getElement(int i, int j) {

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
}