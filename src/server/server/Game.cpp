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
        
    void Game::addPlayer(Player* player) {
        players.push_back(*player);
    }
    
    void Game::removePlayer(int id) {
        players.erase(players.begin()+ id);
    }



}

