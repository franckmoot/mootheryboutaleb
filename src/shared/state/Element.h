// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H


#include "TypeId.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    state::TypeId typeId;
    // Attributes
  private:
    int type;
    // Operations
  public:
    Element ( );
    ~Element ();
    virtual TypeId const getTypeId () = 0;
    virtual bool const isStatic () = 0;
    void setType (int type);
    int getType ();
    // Setters and Getters
    void setTypeId(TypeId typeId);
  };

};

#endif
