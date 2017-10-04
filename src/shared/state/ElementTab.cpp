#include "ElementTab.h"




namespace state{

    /*void ElementTab::setElement(int i, int j, Element* e) {
        list[i*j]=e;
    }*/
    
    Element * const ElementTab::getElement(int i, int j) {
        
       return list[i*j];
    }


 
    size_t ElementTab::getHeight() {
        return height;
    }
    
    size_t ElementTab::getWidth() {
        return width;
    }
      

}