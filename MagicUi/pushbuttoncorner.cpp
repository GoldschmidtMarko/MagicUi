#include "pushbuttoncorner.h"

PushButtonCorner::PushButtonCorner(QWidget *parent, Player* p, ButtonType type, std::string commanderPlayer) : QPushButton(parent) {
    this->p = p;
    this->type = type;
    this->commanderPlayerName = commanderPlayer;
}

void PushButtonCorner::mousePressEvent(QMouseEvent *ev){
    int height = size().height();
    int width = size().width();

    int x = ev->position().x();
    int y = ev->position().y();

    if(type == hp){
        if(x < height/2){
            if(y < width/2){
                p->hp += 1;
            }else{
                p->hp -= 1;
            }
        }else{
            if(y < width/2){
                p->hp += 5;
            }else{
                p->hp -= 5;
            }
        }
    }else if(type == commanderDamage){
        for(auto it : p->vecPlayerCommander){
            if(it->playerName == commanderPlayerName){
                if(x < height/2){
                    if(y < width/2){
                        it->damage += 1;
                    }else{
                        it->damage -= 1;
                    }
                }else{
                    if(y < width/2){
                        it->damage += 5;
                    }else{
                        it->damage -= 5;
                    }
                }
                if(x < height/2){
                    if(y < width/2){
                        p->hp -= 1;
                    }else{
                        p->hp += 1;
                    }
                }else{
                    if(y < width/2){
                        p->hp -= 5;
                    }else{
                        p->hp += 5;
                    }
                }

                break;
            }
        }
    }else if(type == infect){
        if(x < height/2){
            if(y < width/2){
                p->infectdamage += 1;
            }else{
                p->infectdamage -= 1;
            }
        }else{
            if(y < width/2){
                p->infectdamage += 5;
            }else{
                p->infectdamage -= 5;
            }
        }
        if(x < height/2){
            if(y < width/2){
                p->hp -= 1;
            }else{
                p->hp += 1;
            }
        }else{
            if(y < width/2){
                p->hp -= 5;
            }else{
                p->hp += 5;
            }
        }
    }

    if(dynamic_cast<Screen*>(parent()) != nullptr){
        ((Screen*)(parent()))->refreshUi();
    }
}

void PushButtonCorner::mouseReleaseEvent(QMouseEvent *ev){
    if(ev->button() == Qt::LeftButton){
        //std::cout  << "Left released" << std::endl;
    }
}

