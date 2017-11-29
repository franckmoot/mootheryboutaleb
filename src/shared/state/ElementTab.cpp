#include "ElementTab.h"
#include "Champdebataille.h"
#include "Batiment.h"
#include "Element.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

namespace state {

    ElementTab::ElementTab() {
    }

    ElementTab::ElementTab(size_t width, size_t height) : width(width), height(height), list(width*height) {
    }

    int ElementTab::sizeList() {
        return list.size();
    }

    void ElementTab::setElement(Element* e) {
        list.push_back(unique_ptr<Element>(e));
    }

    void ElementTab::setElementXY(Element* e, int x, int y) {
        if (list[x + y * width] == NULL) {
            list[x + y * width] = unique_ptr<Element>(e);
            e->setPosition(x, y);
        }
    }

    Element * ElementTab::getElement(int x, int y) const {
        if (x < 0 || x >= int(width) || y < 0 || y >= int(height))
            return nullptr;
        return list[x + y * width].get();
    }

    size_t ElementTab::getHeight() {
        return height;
    }

    size_t ElementTab::getWidth() {
        return width;
    }

    ElementTab::~ElementTab() {
    }

    void ElementTab::chgList(int i, Element * e) {
        if (list[i] == NULL) list[i] = unique_ptr<Element>(e);
    }

    void ElementTab::chgList2(int i, int j) {
        if (int(list.size()) >= i && int(list.size()) >= j) {
            if (list[i] != NULL) {
                if (list[j] == NULL) {
                    list[j].swap(list[i]);
                }
            } else std::cout << "Erreur sur le deplacement !" << std::endl;
        } else std::cout << "Deplacement hors list" << std::endl;
    }

    void ElementTab::chgPosition(int x1, int y1, int x2, int y2) {

        if (getElement(x1, y1) != NULL) {
            if (getElement(x2, y2) == NULL) {
                list[x2 + y2 * width].swap(list[x1 + y1 * width]);
                getElement(x2, y2)->setPosition(x2, y2);
            }
        } else std::cout << "Erreur sur le deplacement !" << std::endl;
    }

    const std::vector<int> ElementTab::createElementCsv(std::vector<int> carte) {
        std::ifstream fichier;
        fichier.open("res/map.csv", std::ios::in);
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

        for (int i = 0; i<int(carte.size()); i++) {


            switch (carte[i]) {

                case EAU:
                    this->setElement(new Champdebataille(EAU));
                    break;

                case HERBE:
                    this->setElement(new Champdebataille(HERBE));
                    break;

                case MONTAGNE:
                    this->setElement(new Champdebataille(MONTAGNE));
                    break;

                case ROUTE:
                    this->setElement(new Champdebataille(ROUTE));
                    break;

                case SABLE1:
                    this->setElement(new Champdebataille(SABLE1));
                    break;
                case SABLE2:
                    this->setElement(new Champdebataille(SABLE2));
                    break;

                case 6://BatimentTypeId::QGROUGE = 0 
                    this->setElement(new Batiment(QGROUGE));
                    this->getElement(i%20,i/20)->setJoueur(1);
                    break;

                case 7://BatimentTypeId::CASERNEROUGE = 1
                    this->setElement(new Batiment(CASERNEROUGE));
                    this->getElement(i%20,i/20)->setJoueur(1);
                    break;

                case 8://BatimentTypeId::APPARTROUGE = 2
                    this->setElement(new Batiment(APPARTROUGE));
                    this->getElement(i%20,i/20)->setJoueur(1);
                    break;

                case 9://BatimentTypeId::QGBLEU = 3
                    this->setElement(new Batiment(QGBLEU));
                    this->getElement(i%20,i/20)->setJoueur(2);
                    break;

                case 10://BatimentTypeId::CASERNEBLEU = 4
                    this->setElement(new Batiment(CASERNEBLEU));
                    this->getElement(i%20,i/20)->setJoueur(2);
                    break;

                case 11://BatimentTypeId::APPARTBLEU = 5
                    this->setElement(new Batiment(APPARTBLEU));
                    this->getElement(i%20,i/20)->setJoueur(2);
                    break;

                default:
                    this->setElement(NULL);
                    break;
            }
        }
        return carte;
    }

    void ElementTab::killElement(int i, int j) {
        list[i + j * width] = NULL;

    }

}