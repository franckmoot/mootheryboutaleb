// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H


namespace state {
  class ElementChars;
  class ElementTab;
}

#include "ElementChars.h"
#include "ElementTab.h"

namespace state {

  /// class State - 
  class State {
    // Associations
    // Attributes
  public:
    int grid;
    ElementChars chars;
    // Operations
  public:
    State ();
    int getGrid ();
    ElementChars& getChars ();
    void setGrid (int g);
    // Setters and Getters
  };

};

#endif
