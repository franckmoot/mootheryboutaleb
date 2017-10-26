#include "Tilemap.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace render {

       void Tilemap::draw (sf::RenderTarget& target, sf::RenderStates states) const 
      {
    
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
    }

std::vector<int> Tilemap::lirefichiercsv(std::vector<int> vcarte) {
            std::ifstream fichier;
            
    	
      
            fichier.open("res/map1.csv",std::ios::in);
            if(!fichier.good())
                 throw std::runtime_error("Error opening!!");
        std::string ligne,valeur;
       
       // int i = 0;
		
        while(!fichier.eof()){
            std::getline(fichier,ligne);
            std::stringstream stream(ligne);
            //std::cout << ligne << std::endl;

		
            while(getline(stream, valeur,',')){
			
                vcarte.push_back(atoi(valeur.c_str()));
			
            }
        }
        return vcarte;
}

        
bool Tilemap:: load ( const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
{
    
    
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset)) {
            cout << "Erreur lecture " << tileset << endl;
            return false;
        }
            
            //sreturn false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }
}