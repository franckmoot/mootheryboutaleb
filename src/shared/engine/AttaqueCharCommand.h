// Generated by dia2code
#ifndef ENGINE__ATTAQUECHARCOMMAND__H
#define ENGINE__ATTAQUECHARCOMMAND__H

#include <stack>
#include <memory>
#include <json/json.h>

namespace engine {
  class Action;
};
namespace state {
  class State;
};
namespace engine {
  class AttaqueCharCommand;
  class Command;
}

#include "CommandTypeId.h"
#include "Action.h"
#include "Command.h"

namespace engine {

  /// class AttaqueCharCommand - 
  class AttaqueCharCommand : public engine::Command {
    // Attributes
  private:
    int x1;
    int y1;
    int x2;
    int y2;
    // Operations
  public:
    CommandTypeId getTypeId () const;
    void execute (std::stack<std::shared_ptr<Action>>& actions, state::State& state);
    AttaqueCharCommand (int x1, int y1, int x2, int y2);
    void serialise (Json::Value& out) const;
    AttaqueCharCommand* deserialise (Json::Value& in);
    // Setters and Getters
  };

};

#endif
