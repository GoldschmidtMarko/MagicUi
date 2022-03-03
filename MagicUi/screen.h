#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QScreen>
#include <iostream>
#include "player.h"

namespace Ui {
class Screen;
}

class Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Screen(QWidget *parent = nullptr);
    ~Screen();

private slots:
    void on_buttonEdit_clicked();

private:
    Ui::Screen *ui;
    int timerId2 = 0;

    std::vector<Player*> vecPlayers;
    std::vector<int> buttonsPressed;

    void refreshUi();

    void refreshUiPlayer(Player* p);

    void maximizeFontSize(QObject* object);
    template <class T>
    void maximizeFontSizeTemplate(T* it);

    void resizeEvent(QResizeEvent* event) override;

    void timerEvent(QTimerEvent *te) override;
};

#endif // SCREEN_H
