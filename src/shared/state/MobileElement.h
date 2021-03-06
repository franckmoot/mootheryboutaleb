// Generated by dia2code
#ifndef STATE__MOBILEELEMENT__H
#define STATE__MOBILEELEMENT__H


namespace state {
  class Element;
}

#include "Element.h"

namespace state {

  /// class MobileElement - 
  class MobileElement : public state::Element {
    // Attributes
  protected:
    int pdv;
    int porteeMvt;
    int defense;
    int attaque;
    int porteeAtq;
    // Operations
  public:
    MobileElement ( );
    ~MobileElement ();
    virtual int diffUnite () = 0;
    bool isStatic () const;
    // Setters and Getters
    int getPdv() const;
    void setPdv(int pdv);
    int getPorteeMvt() const;
    void setPorteeMvt(int porteeMvt);
    int getDefense() const;
    void setDefense(int defense);
    int getAttaque() const;
    void setAttaque(int attaque);
    int getPorteeAtq() const;
    void setPorteeAtq(int porteeAtq);
  };

};

#endif
