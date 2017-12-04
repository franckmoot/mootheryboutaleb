// Generated by dia2code
#ifndef ENGINE__MOVECHARCOMMAND__H
#define ENGINE__MOVECHARCOMMAND__H

#include <stack>
#include <memory>

namespace engine {
  class Action;
};
namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Action.h"
#include "Command.h"

namespace engine {

  /// class MoveCharCommand - 
  class MoveCharCommand : public engine::Command {
    // Attributes
  private:
    int x1;
    int y1;
    int x2;
    int y2;
    // Operations
  public:
    CommandTypeId getTypeId () const;
    MoveCharCommand (int x1, int y1, int x2, int y2);
    void execute (std::stack<std::shared_ptr<Action>>& actions, state::State& state);
    // Setters and Getters
  };

};

#endif
