// Generated by dia2code
#ifndef STATE__BATIMENT__H
#define STATE__BATIMENT__H


namespace state {
  class Element;
}

#include "BatimentTypeId.h"

namespace state {

  /// class Batiment - 
  class Batiment {
    // Associations
    state::BatimentTypeId batimentTypeId;
    // Attributes
  private:
    int capture;
    // Operations
  public:
    Batiment (BatimentTypeId id);
    ~Batiment ();
    int const diffMap ();
    TypeId const getTypeId ();
    bool const equals (const Element& other);
    bool const isStatic ();
    // Setters and Getters
    BatimentTypeId getBatimentTypeId() const;
    void setBatimentTypeId(BatimentTypeId batimentTypeId);
  };

};

#endif
