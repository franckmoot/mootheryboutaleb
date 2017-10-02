// Generated by dia2code
#ifndef STATE__MOBILEELEMENT__H
#define STATE__MOBILEELEMENT__H


namespace state {
  class Element;
}

namespace state {

  /// class MobileElement - 
  class MobileElement {
    // Attributes
  protected:
    int position;
    int pdv;
    int mouvement;
    int defense;
    int attaque;
    // Operations
  public:
    MobileElement (MobileElementTypeId id);
    int diffUnite ();
    bool const equals (const Element& other);
    bool const isStatic ();
    // Setters and Getters
    int getPosition() const;
    void setPosition(int position);
    int getPdv() const;
    void setPdv(int pdv);
    int getMouvement() const;
    void setMouvement(int mouvement);
    int getDefense() const;
    void setDefense(int defense);
    int getAttaque() const;
    void setAttaque(int attaque);
  };

};

#endif
