// Generated by dia2code
#ifndef ENGINE__MOVECHARCOMMAND__H
#define ENGINE__MOVECHARCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "Command.h"

namespace engine {

  /// class MovecharCommand - 
  class MovecharCommand : public engine::Command {
    // Operations
  public:
    CommandTypeId const getTypeId ();
    void execute (state::State& state);
    void MoveCharCommand (state::State& state, int i, int j);
    // Setters and Getters
  };

};

#endif
