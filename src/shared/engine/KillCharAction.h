// Generated by dia2code
#ifndef ENGINE__KILLCHARACTION__H
#define ENGINE__KILLCHARACTION__H


namespace state {
  class State;
};
namespace engine {
  class Action;
}

#include "state/TypeId.h"
#include "Action.h"

namespace engine {

  /// class KillCharAction - 
  class KillCharAction : public engine::Action {
    // Attributes
  public:
    int x;
    int y;
    state::TypeId elementId;
    int joueur;
    // Operations
  public:
    void apply (state::State& state);
    void undo (state::State& state);
    KillCharAction (int x, int y, state::TypeId elementId, int joueur);
    // Setters and Getters
  };

};

#endif
