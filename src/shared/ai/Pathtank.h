// Generated by dia2code
#ifndef AI__PATHTANK__H
#define AI__PATHTANK__H


namespace state {
  class ElementTab;
};
namespace ai {
  class Pathmap;
}

#include "Pathmap.h"

namespace ai {

  /// class Pathtank - 
  class Pathtank : public ai::Pathmap {
    // Operations
  public:
    void init (state::ElementTab& grid);
    // Setters and Getters
  };

};

#endif
