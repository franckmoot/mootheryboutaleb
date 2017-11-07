// Generated by dia2code
#ifndef ENGINE__COMMAND__H
#define ENGINE__COMMAND__H


namespace state {
  class State;
}

#include "CommandTypeId.h"

namespace engine {

  /// class Command - 
  class Command {
    // Operations
  public:
    Command ();
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
  };

};

#endif
