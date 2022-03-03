#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player{
    class PlayerCommander{
        public:
            std::string playerName = "";
            int damage = 0;
    };


public:
    Player(std::string name);
    ~Player();
    std::string name =  "";
    int hp = 40;
    int infectdamage = 0;
    int r = 100;
    int g = 100;
    int b = 100;


    std::vector<PlayerCommander*> vecPlayerCommander;

    std::string getBackgroundColor();
    void addCommanderDamage(std::string player, int damage);
    void removeCommanderDamage(std::string player, int damageRemoved);


};

#endif // PLAYER_H
