// Generated by dia2code
#ifndef ENGINE__CREATEHELIACTION__H
#define ENGINE__CREATEHELIACTION__H


namespace state {
  class State;
};
namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class CreateHeliAction - 
  class CreateHeliAction : public engine::Action {
    // Attributes
  private:
    int x;
    int y;
    int joueur;
    // Operations
  public:
    void apply (state::State& state);
    void undo (state::State& state);
    CreateHeliAction (int x, int y, int joueur);
    // Setters and Getters
  };

};

#endif
