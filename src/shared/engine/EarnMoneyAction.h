// Generated by dia2code
#ifndef ENGINE__EARNMONEYACTION__H
#define ENGINE__EARNMONEYACTION__H


namespace state {
  class State;
};
namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class EarnMoneyAction - 
  class EarnMoneyAction : public engine::Action {
    // Attributes
  public:
    int joueur;
    // Operations
  public:
    void apply (state::State& state);
    void undo (state::State& state);
    EarnMoneyAction (int joueur);
    // Setters and Getters
  };

};

#endif
