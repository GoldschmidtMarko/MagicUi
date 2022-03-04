#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QWidget>
#include <QRadioButton>
#include <iostream>
#include "player.h"

namespace Ui {
class Editwindow;
}

class Editwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Editwindow(QWidget *parent = nullptr);
    ~Editwindow();

    void generateColors();
    void setSelectedPlayers(std::vector<Player*> vec);
    std::vector<Player*> vecPlayers;


private:
    Ui::Editwindow *ui;

    void resizeEvent(QResizeEvent* event) override;

    void timerEvent(QTimerEvent *te) override;

    int timerId2 = 0;

    void maximizeFontSize(QObject* object);
    template <class T>
    void maximizeFontSizeTemplate(T* it);
};

#endif // EDITWINDOW_H
