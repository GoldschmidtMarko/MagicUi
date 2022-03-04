#include "player.h"

Player::Player(std::string name){
    this->name = name;
}

Player::~Player(){
    for(auto it : vecPlayerCommander){
        delete(it);
    }
}

void Player::addCommanderDamage(std::string player, int damage){
    for(auto it : vecPlayerCommander){
        if(it->playerName == player){
            it->damage += damage;
            return;
        }
    }
    PlayerCommander* pc = new PlayerCommander();
    pc->playerName = player;
    pc->damage = damage;
    vecPlayerCommander.push_back(pc);
}

void Player::removeCommanderDamage(std::string player, int damageRemoved){
    for(auto it : vecPlayerCommander){
        if(it->playerName == player){
            it->damage -= damageRemoved;
            return;
        }
    }
}

std::string Player::getBackgroundColor(){
    return "background-color: rgb(" + std::to_string(r_back) + "," + std::to_string(g_back) + "," + std::to_string(b_back) + ");" + "color: rgb(" +  std::to_string(r_font) + "," + std::to_string(g_font) + "," + std::to_string(b_font) + ");";
}

