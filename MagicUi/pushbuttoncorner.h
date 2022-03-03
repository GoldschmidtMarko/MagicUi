#ifndef PUSHBUTTONCORNER_H
#define PUSHBUTTONCORNER_H

#include <QPushButton>
#include <QMouseEvent>
#include <iostream>
#include "player.h"
#include "screen.h"

enum ButtonType{
    hp,
    commanderDamage,
    infect
};


class PushButtonCorner : public QPushButton{
protected:
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
public:
    PushButtonCorner(QWidget *parent, Player* p, ButtonType hp, std::string commanderPlayer);

    Player* p = nullptr;
    std::string commanderPlayerName = "";
    ButtonType type = hp;



};

#endif // PUSHBUTTONCORNER_H
