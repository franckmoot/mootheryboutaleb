#include "Batiment.h"
#include <iostream>

using namespace std;

namespace state {

    /* Constructeur */
    Batiment::Batiment() {
        this->pdv = 50;
    }

    Batiment::Batiment(BatimentTypeId id) {

        if (id == BatimentTypeId::CASERNEROUGE) {
            batimentTypeId = BatimentTypeId::CASERNEROUGE;

        }
        else if (id == BatimentTypeId::QGROUGE) {
            batimentTypeId = BatimentTypeId::QGROUGE;

        }
        else if (id == BatimentTypeId::APPARTROUGE) {
            batimentTypeId = BatimentTypeId::APPARTROUGE;

        }
        else if (id == BatimentTypeId::QGBLEU) {
            batimentTypeId = BatimentTypeId::QGBLEU;

        }
        else if (id == BatimentTypeId::CASERNEBLEU) {
            batimentTypeId = BatimentTypeId::CASERNEBLEU;

        }
        else if (id == BatimentTypeId::APPARTBLEU) {
            batimentTypeId = BatimentTypeId::APPARTBLEU;

        }

    }

    TypeId Batiment::getTypeId() const {
        return TypeId::BATIMENT;
    }

    /* Getter de capture */
    int Batiment::getCapture() const {
        return capture;
    }

    /* Setter de capture */
    void Batiment::setCapture(int capture) {
        this->capture = capture;
    }

    /* Differenci le champdebataille au batiment*/
    bool Batiment::isChampdebataille() const {
        return false;
    }

    /* Getter de BatimentTypeId */
    BatimentTypeId Batiment::getBatimentTypeId() const {
        return batimentTypeId;
    }

    int Batiment::getPdv() const {
        return pdv;
    }

    void Batiment::setPdv(int pdv) {
        this ->pdv = pdv;
    }

}