#include "ElementChars.h"
#include "ElementTab.h"
#include "Champdebataille.h"
#include "Batiment.h"
#include "Element.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

namespace state{
  ElementChars::ElementChars() {  
    for (size_t i=0;i<getWidth()*getHeight();i++){
      this->setElement(NULL);
    }
  }
  
  ElementChars::ElementChars(size_t width, size_t height) {
  }

  const std::vector<int> ElementChars::ElementToCarte (std::vector<int> carte){
    for(int i=0;i<(int)this->sizeList();i++){     
      if(list[i]==NULL) carte.push_back(-1);
      else carte.push_back(list[i].get()->getTypeId()-2);
                                                         
    } 
    return carte;
  }   
}
