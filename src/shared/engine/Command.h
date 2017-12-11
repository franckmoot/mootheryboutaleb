// Generated by dia2code
#ifndef ENGINE__COMMAND__H
#define ENGINE__COMMAND__H

#include <stack>
#include <memory>
#include <json/json.h>

namespace engine {
  class Action;
};
namespace state {
  class State;
}

#include "CommandTypeId.h"
#include "Action.h"
#include "state/State.h"

namespace engine {

  /// class Command - 
  class Command {
    // Operations
  public:
    Command ();
    virtual CommandTypeId getTypeId () const = 0;
    virtual void execute (std::stack<std::shared_ptr<Action>>& actions, state::State& state) = 0;
    virtual void serialise (Json::Value& out) const = 0;
    // Setters and Getters
  };

};

#endif
