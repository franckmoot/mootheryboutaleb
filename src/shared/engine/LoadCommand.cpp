#include <fstream>
#include <iostream>
#include <string>
#include "LoadCommand.h"
#include "state/State.h"
#include "state/Element.h"
#include "state/ElementTab.h"
#include "state/Champdebataille.h"
#include "state/Batiment.h"
#include <vector>
#include <sstream>

using namespace std;
using namespace state;

namespace engine {

    LoadCommand::LoadCommand(const char* f) {
        this->filename = f;

    }

    void LoadCommand::execute(std::stack<std::shared_ptr<Action> >& actions,state::State& state) {
        std::vector<int> carte;
        std::ifstream fichier;
        fichier.open(filename, std::ios::in);
        if (!fichier.good())
            throw std::runtime_error("Error opening!!");
        std::string ligne, valeur;

        while (!fichier.eof()) {
            std::getline(fichier, ligne);
            std::stringstream stream(ligne);
            //std::cout << ligne << std::endl;

            while (getline(stream, valeur, ',')) {
                carte.push_back(atoi(valeur.c_str()));
            }
        }
        int x,y;
        for (int i = 0; i<int(carte.size()); i++) {
            x=i%20;
            y=i/20;
            switch (carte[i]) {

                case ChampdebatailleTypeId::HERBE:
                    state.getGrid()->setElement(new Champdebataille(ChampdebatailleTypeId::HERBE));
                    break;

                case ChampdebatailleTypeId::ROUTE:
                    state.getGrid()->setElement(new Champdebataille(ChampdebatailleTypeId::ROUTE));
                    break;

                case ChampdebatailleTypeId::SABLE1:
                    state.getGrid()->setElement(new Champdebataille(ChampdebatailleTypeId::SABLE1));
                    break;

                case ChampdebatailleTypeId::SABLE2:
                    state.getGrid()->setElement(new state::Champdebataille(ChampdebatailleTypeId::SABLE2));
                    break;

                case ChampdebatailleTypeId::EAU:
                    state.getGrid()->setElement(new state::Champdebataille(ChampdebatailleTypeId::EAU));
                    break;

                case ChampdebatailleTypeId::MONTAGNE:
                    state.getGrid()->setElement(new state::Champdebataille(ChampdebatailleTypeId::MONTAGNE));
                    break;

                case 6://BatimentTypeId::QGROUGE = 0 
                    state.getGrid()->setElement(new state::Batiment(BatimentTypeId::QGROUGE));
                    state.getGrid()->getElement(x,y)->setJoueur(1);
                    break;

                case 7://BatimentTypeId::CASERNEROUGE = 1
                    state.getGrid()->setElement(new state::Batiment(BatimentTypeId::CASERNEROUGE));
                    state.getGrid()->getElement(x,y)->setJoueur(1);
                    break;

                case 8://BatimentTypeId::APPARTROUGE = 2
                    state.getGrid()->setElement(new state::Batiment(BatimentTypeId::APPARTROUGE));
                    state.getGrid()->getElement(x,y)->setJoueur(1);
                    break;

                case 9://BatimentTypeId::QGBLEU = 3
                    state.getGrid()->setElement(new state::Batiment(BatimentTypeId::QGBLEU));
                    state.getGrid()->getElement(x,y)->setJoueur(2);
                    break;

                case 10://BatimentTypeId::CASERNEBLEU = 4
                    state.getGrid()->setElement(new state::Batiment(BatimentTypeId::CASERNEBLEU));
                    state.getGrid()->getElement(x,y)->setJoueur(2);
                    break;

                case 11://BatimentTypeId::APPARTBLEU = 5
                    state.getGrid()->setElement(new state::Batiment(BatimentTypeId::APPARTBLEU));
                    state.getGrid()->getElement(x,y)->setJoueur(2);
                    break;

                default:
                    state.getGrid()->setElement(NULL);
                    break;
            }
        }

    }

    CommandTypeId LoadCommand::getTypeId() const {
        return CommandTypeId::LOAD;
    }
    
    void LoadCommand::serialise(Json::Value& out) const {
    }

    
}

