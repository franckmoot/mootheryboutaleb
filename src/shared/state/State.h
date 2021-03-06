// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H


namespace state {
  class ElementTab;
  class ElementChars;
  class Joueur;
}

#include "Joueur.h"
#include "ElementTab.h"
#include "ElementChars.h"

namespace state {

  /// class State - 
  class State {
    // Associations
    // Attributes
  public:
    ElementTab* grid;
    ElementChars* chars;
    Joueur*  joueur1;
    Joueur* joueur2;
    // Operations
  public:
    State ();
    ElementTab* getGrid ();
    ElementChars* getChars ();
    int getscore (int joueur);
    // Setters and Getters
  };

};

#endif
