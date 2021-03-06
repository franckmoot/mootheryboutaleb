// Generated by dia2code
#ifndef STATE__ELEMENTCHARS__H
#define STATE__ELEMENTCHARS__H

#include <vector>
#include <stdlib.h>

namespace state {
  class ElementTab;
}

#include "ElementTab.h"

namespace state {

  /// class ElementChars - 
  class ElementChars : public state::ElementTab {
    // Operations
  public:
    ElementChars ();
    std::vector<int> const ElementToCarte (std::vector<int> carte);
    ElementChars (size_t width, size_t height);
    std::vector<int> createElementCharsCsv () const;
    // Setters and Getters
  };

};

#endif
