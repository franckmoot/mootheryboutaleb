// Generated by dia2code
#ifndef AI__RANDOMAI__H
#define AI__RANDOMAI__H


namespace state {
  class State;
};
namespace ai {
  class AI;
}

#include "AI.h"

namespace ai {

  /// class RandomAI - 
  class RandomAI : public ai::AI {
    // Operations
  public:
    void run (state::State& state, int joueur);
    RandomAI ();
    // Setters and Getters
  };

};

#endif
