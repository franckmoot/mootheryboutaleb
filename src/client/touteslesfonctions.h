#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <sstream>
#include <thread>
#include "render/CharsTileSet.h"
#include "render/GridTileSet.h"
#include "render/Tile.h"
#include "state/Batiment.h"
#include "state/Champdebataille.h"
#include "state/Element.h"
#include "state/ElementChars.h"
#include "state/ElementTab.h"
#include "state/MobileElement.h"
#include "state/StaticElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"
#include "state/State.h"
#include "engine/Command.h"
#include "engine/AttaqueCharCommand.h"
#include "engine/LoadCommand.h"
#include "engine/MoveCharCommand.h"
#include "engine/CreateCharCommand.h"

using namespace std;
using namespace state;
using namespace render;

#ifndef TOUTESLESFONCTIONS_H
#define TOUTESLESFONCTIONS_H

   

void teststate ();
void testcreateelement();

void testrender();
void testload();
void testengine();
void testai();
void testcommande();
void testheuristicAI();
void testdeep_ai();
void testrollback();
void testthread();


    

#endif /* TOUTESLESFONCTIONS_H */