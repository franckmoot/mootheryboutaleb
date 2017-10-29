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
            vector<unique_ptr<Element> > list(width*height);
            for (size_t i=0;i<width*height;i++){
                list[i]=NULL;
            }
        }
          
          
        const std::vector<int> ElementChars::ElementToCarte (std::vector<int> carte){
            for(int i=0;i<(int)list.size();i++){
                 if(list[i]=NULL) carte[i]=-1;
             else carte[i]=list[i].get()->getTypeId()-1;
            }
         return carte;
    
        }   


}