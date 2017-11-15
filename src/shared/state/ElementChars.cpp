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
      vector<unique_ptr<Element> > list(0);
    for (size_t i=0;i<400;i++){
      this->setElement(NULL);
    }
  }
  
  ElementChars::ElementChars(size_t width, size_t height) {
    vector<unique_ptr<Element> > list(0);
    for (size_t i=0;i<width*height;i++){
      this->setElement(NULL);
    }

  }
  

  
  
  const std::vector<int> ElementChars::ElementToCarte (std::vector<int> carte){
    for(int i=0;i<(int)this->sizeList();i++){     
      if(list[i]==NULL) carte.push_back(-1);
      else carte.push_back(list[i].get()->getTypeId()-2);
                                                         
    }
    /*for(int k=0;k<(int)this->sizeList();k++){
        cout<<carte[k]<<",";
        if(k!=0 && (k+1)%10==0)cout<<" "<<endl;
        
    }
    
    cout<<""<<endl;*/
    
    return carte;
  }   
}
