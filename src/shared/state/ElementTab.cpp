#include "ElementTab.h"



namespace state{

    ElementTab::ElementTab() {
       
    }
    
    ElementTab::ElementTab(size_t width, size_t height) {
            std::vector<Element*> list(width*height);
    }
    
    int ElementTab::sizeList() {
        return list.size();
    }

    
    void ElementTab::setElement(int i, int j, Element* e) {
        list.push_back(e);
    }
    
    Element * const ElementTab::getElement(int i, int j) {
        
       return list[i*j];
    }
    
 
    size_t ElementTab::getHeight() {
        return height;
    }
    
    size_t ElementTab::getWidth() {
        return width;
    }

    ElementTab::~ElementTab() {

    }

    
}