// Generated by dia2code
#ifndef ENGINE__CAPTURCHARCOMMAND__H
#define ENGINE__CAPTURCHARCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "state/State.h"
#include "Command.h"

namespace engine {

  /// class CapturCharCommand - 
  class CapturCharCommand : public engine::Command {
    // Operations
  public:
    CommandTypeId getTypeId () const;
    void execute (state::State state);
    // Setters and Getters
  };

};

#endif