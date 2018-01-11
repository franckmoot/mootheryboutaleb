#include "Player.h"
#include "AbstractService.h"
#include "Game.h"


using namespace std;
namespace server{
    
    Game::Game(){
        
    }
    Player& Game::player (int i){
        
    }
    const Player* Game::getPlayer (int id) const{
        
    }
    int Game::addPlayer (std::unique_ptr<Player> player){
        
    }
    void Game:: setPlayer (int id, std::unique_ptr<Player> player){
        
    }
    void Game::removePlayer (int id){
        
    }
    // Setters and Getters
    const std::vector<Player>& Game::getPlayers() const{
        
    }
    void Game::setPlayers(const std::vector<Player>& players){
        
    }
    
    
    
    
}

