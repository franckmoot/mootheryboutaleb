#include "ElementChars.h"


using namespace std;

namespace state{
        ElementChars::ElementChars() {

    }
 const std::vector<int> ElementChars::ElementToCarte (std::vector<int> carte){
         for(int i=0;i<(int)list.size();i++){
             if(list[i]=NULL) carte[i]=-1;
             else carte[i]=list[i].get().getTypeId()+5;
         }
         return carte;
    
 }   


}