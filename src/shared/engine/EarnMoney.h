// Generated by dia2code
#ifndef ENGINE__EARNMONEY__H
#define ENGINE__EARNMONEY__H

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

#include "Action.h"
#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class EarnMoney - 
  class EarnMoney : public engine::Command {
    // Attributes
  public:
    int joueur;
    // Operations
  public:
    EarnMoney (int joueur);
    void execute (std::stack<std::shared_ptr<Action>>& actions, state::State& state);
    CommandTypeId getTypeId () const;
    // Setters and Getters
  };

};

#endif
