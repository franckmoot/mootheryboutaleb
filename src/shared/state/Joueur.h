// Generated by dia2code
#ifndef STATE__JOUEUR__H
#define STATE__JOUEUR__H


namespace state {
  class Element;
}

#include "Element.h"

namespace state {

  /// class Joueur - 
  class Joueur {
    // Associations
    // Attributes
  private:
    int money;
    // Operations
  public:
    Joueur ();
    int getMoney ( );
    void setMoney (int money);
    void addMoney (int money);
    void lessMoney (int money);
    // Setters and Getters
  };

};

#endif
