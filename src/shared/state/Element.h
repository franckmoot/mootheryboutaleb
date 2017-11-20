// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H


namespace state {
  class ElementTab;
}

#include "TypeId.h"
#include "ElementTab.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    state::TypeId typeId;
    // Attributes
  private:
    int type;
  protected:
    int joueur;
    int x;
    int y;
    // Operations
  public:
    Element ( );
    ~Element ();
    virtual TypeId getTypeId () const = 0;
    virtual bool isStatic () const = 0;
    void setType (int type);
    int getType ();
    int getJoueur ();
    void setJoueur (int joueur);
    // Setters and Getters
    void setTypeId(TypeId typeId);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
  };

};

#endif
