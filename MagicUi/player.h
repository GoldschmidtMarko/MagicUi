#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class PlayerCommander{
    public:
        std::string playerName = "";
        int damage = 0;
};

class Player{
public:
    Player(std::string name);
    ~Player();
    std::string name =  "";
    int hp = 40;
    int infectdamage = 0;
    int r_back = 100;
    int g_back = 100;
    int b_back = 100;
    int r_font = 0;
    int g_font = 0;
    int b_font = 0;


    std::vector<PlayerCommander*> vecPlayerCommander;

    std::string getBackgroundColor();
    void addCommanderDamage(std::string player, int damage);
    void removeCommanderDamage(std::string player, int damageRemoved);


};

#endif // PLAYER_H
