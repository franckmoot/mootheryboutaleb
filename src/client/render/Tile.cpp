#include "Tile.h"

using namespace std;

namespace render {
    
    Tile::Tile(int x, int y, int w, int h) {
        this->x=x;
        this->y=y;
        this->width=w;
        this->height=h;  
    }
   
    int Tile::getHeight() const {
        return height;
    }

    int Tile::getWidth() const {
        return width;
    }
    int Tile::getX() const {
        return x;
    }

    int Tile::getY() const {
        return y;
    }

    void Tile::setHeight(int height) {
        this->height=height;
    }

    void Tile::setWidth(int width) {
        this->width=width;
    }

    void Tile::setX(int x) {
        this->x=x;
    }

    void Tile::setY(int y) {
        this->y=y;
    }

}