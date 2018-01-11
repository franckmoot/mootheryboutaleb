#include "Player.h"
#include "AbstractService.h"
#include "Game.hpp"


using namespace std;
namespace server {

    Game::Game() {

    }

    Player* Game::player(int i) {
        Player *p=&(players[i]);
        return p;
    }

}

