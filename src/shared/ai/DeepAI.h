// Generated by dia2code
#ifndef AI__DEEPAI__H
#define AI__DEEPAI__H


namespace engine {
  class Engine;
};
namespace ai {
  class AI;
}

#include "AI.h"

namespace ai {

  /// class DeepAI - 
  class DeepAI : public ai::AI {
    // Operations
  public:
    void run (int joueur, engine::Engine& engine, int profondeur);
    DeepAI ();
    int max (engine::Engine& engine, int joueur, int profondeur, int x, int y);
    // Setters and Getters
  };

};

#endif
