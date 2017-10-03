// Generated by dia2code
#ifndef STATE__TANK__H
#define STATE__TANK__H


namespace state {
  class MobileElement;
}

#include "MobileElement.h"
#include "TankTypeId.h"

namespace state {

  /// class Tank - 
  class Tank : public state::MobileElement {
    // Associations
    state::TankTypeId tankTypeId;
    // Operations
  public:
    Tank ();
    ~Tank ();
    int diffUnite ();
    TypeId const getTypeId ();
    // Setters and Getters
    TankTypeId getTankTypeId() const;
    void setTankTypeId(TankTypeId tankTypeId);
  };

};

#endif
