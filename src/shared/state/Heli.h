// Generated by dia2code
#ifndef STATE__HELI__H
#define STATE__HELI__H


namespace state {
  class MobileElement;
}

#include "MobileElement.h"
#include "HeliTypeId.h"

namespace state {

  /// class Heli - 
  class Heli : public state::MobileElement {
    // Associations
    // Operations
  public:
    Heli ();
    ~Heli ();
    int diffUnite ();
    TypeId const getTypeId ();
    // Setters and Getters
  };

};

#endif
