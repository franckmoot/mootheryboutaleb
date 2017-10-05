// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H


namespace state {
  class ElementTab;
  class ElementChars;
}

#include "ElementTab.h"
#include "ElementChars.h"

namespace state {

  /// class State - 
  class State {
    // Associations
    // Attributes
  public:
    ElementTab* grid;
    ElementChars* chars;
    // Operations
  public:
    State ();
    ElementTab* getGrid ();
    ElementChars* getChars ();
    // Setters and Getters
  };

};

#endif
