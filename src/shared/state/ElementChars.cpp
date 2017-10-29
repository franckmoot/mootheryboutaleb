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
  }
  
  ElementChars::ElementChars(size_t width, size_t height) {
    vector<unique_ptr<Element> > list(0);
    cout<<"AVANT: La liste à "<< this->sizeList() <<" cases"<<endl;
    for (size_t i=0;i<width*height;i++){
      this->setElement(NULL);
    }
    cout<<"APRES: La liste à "<< this->sizeList() <<" cases"<<endl;
  }
  
  
  const std::vector<int> ElementChars::ElementToCarte (std::vector<int> carte){
    for(int i=0;i<(int)this->sizeList();i++){     
      if(list[i]==NULL) carte.push_back(-1);
      else carte.push_back(list[i].get()->getTypeId()-2);
     //if(this->sizeList()>i)cout<<"carte = "<<carte[i]<<"gettypeID = "<<list[i].get()->getTypeId()-1<<endl;                                                     
    cout<<"APRES: La list"<<endl;
    carte[i];
   // list[i].get()->getTypeId();
    }
    
    for(int k=0;k<(int)this->sizeList();k++){
        cout<<carte[k]<<",";
        if(k!=0 && (k+1)%10==0)cout<<" "<<endl;
        
    }
    
    cout<<""<<endl;
    
    return carte;
  }   
}
