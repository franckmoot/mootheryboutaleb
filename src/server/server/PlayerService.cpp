#include "PlayerService.h"
#include "Player.h"
#include "ServiceException.h"
#include "AbstractService.h"
#include "Game.h"
#include "Game.hpp"
using namespace std;

namespace server {

    PlayerService::PlayerService(Game& game) : AbstractService("/user"), game(game) {

    }

    HttpStatus PlayerService::get(Json::Value& out, int id) const {
        const Player* player = game.player(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND, "Invalid player id");
        out["name"] = player->name;
        return HttpStatus::OK;

    }

    HttpStatus PlayerService::post(const Json::Value& in, int id) {
        const Player* player = game.player(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND, "Invalid player id");
        
        Player* usermod;
        //std::unique_ptr<Player> usermod (new Player(*player));
        if (in.isMember("name")) {
            usermod->name = in["name"].asString();
        }
        game.player(id);
        return HttpStatus::NO_CONTENT;
    }

    HttpStatus PlayerService::put(Json::Value& out, const Json::Value& in) {
        string name = in["name"].asString();
        out["id"] = game.player(make_unique<Player>(name));
        //out["id"] = game.addPlayer(unique_ptr<Player>(name));
        return HttpStatus::CREATED;

    }

    HttpStatus PlayerService::remove(int id) {

          const Player* player = game.player(id);
          if (!player)
              throw ServiceException(HttpStatus::NOT_FOUND, "Invalid player id");
          //game.removePlayer(id);
        return HttpStatus::NO_CONTENT;
    }



}