#include "Layer.h"
#include "TileSet.h"
#include "GridTileSet.h"
#include "CharsTileSet.h"
#include "state/ElementTab.h"
#include "state/ElementChars.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/State.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace state;

namespace render {

    Layer::Layer(const state::State& state) : state(state) {
        this->surface = unique_ptr<Surface>(new Surface());
        this->surfaceplayer = unique_ptr<Surface>(new Surface());
        this->tileset = shared_ptr<GridTileSet>(new GridTileSet());
        this->tilesetChars = shared_ptr<CharsTileSet>(new CharsTileSet());
    }

    void Layer::initSurface() {

        int x;
        int y;
        this->surface->initQuads(400);
        this->surfaceplayer->initQuads(400);
        cout << "pb" << endl;
        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < 20; i++) {
                x = int(i / 20);
                y = i % 20;
                this->surface->loadTexture(this->tileset->getImageFile());
                cout << "pb1" << endl;
                this->surface->setSpriteLocation(i + j * state.grid->getWidth(), i, j);
                cout << "i : " << i + j * state.grid->getWidth() << "x : " << i << "y : " << j << endl;
                this->surface->setSpriteTexture(i + j * state.grid->getWidth(), this->tileset->getTile(*(state.grid->getElement(j, i))));
                cout << "pb3" << endl;
            }
        }
        cout << "pb" << endl;
        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < 20; i++) {
                x = int(i / 20);
                y = i % 20;
                this->surfaceplayer->loadTexture(this->tilesetChars->getImageFile());
                this->surfaceplayer->setSpriteLocation(i + j * state.grid->getWidth(), i, j);
                if (state.chars->getElement(i, j) != NULL) {
                    this->surfaceplayer->setSpriteTexture(i + j * state.grid->getWidth(), this->tilesetChars->getTile(*(state.chars->getElement(i, j))));
                } else {
                    // Tile tmp = new Tile(0,0,0,32);
                    this->surfaceplayer->setSpriteTexture(i + j * state.grid->getWidth(), Tile(0, 0, 0, 32));
                }
            }

        }
    }
}


