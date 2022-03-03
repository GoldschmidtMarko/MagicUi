#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QScreen>
#include <iostream>
#include <QMouseEvent>
#include <QDialogButtonBox>
#include "player.h"
#include "pushbuttoncorner.h"
#include "dicewindow.h"
#include "Define.h"
#include "resetdialog.h"
#include "defaultsetting.h"
#include "settingswindow.h"

namespace Ui {
class Screen;
}

class Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Screen(QWidget *parent = nullptr);
    ~Screen();
    void refreshUi();
    std::vector<Player*> vecPlayers;

private slots:
    void on_buttonEdit_clicked();

    void on_buttonDice_clicked();

    void on_buttonReset_clicked();

    void on_buttonSetting_clicked();

private:
    Ui::Screen *ui;
    DiceWindow *diceWindow;
    ResetDialog *resetDialog;
    DefaultSetting* defaultSetting;
    Settingswindow* settingsWindow;

    int timerId2 = 0;

    std::vector<int> buttonsPressed;

    void setupSettingWindow();

    void refreshUiPlayer(Player* p);

    void maximizeFontSize(QObject* object);
    template <class T>
    void maximizeFontSizeTemplate(T* it);

    Player* getPlayerByName(std::string name);

    void resizeEvent(QResizeEvent* event) override;

    void timerEvent(QTimerEvent *te) override;

    void resetStats();
};

#endif // SCREEN_H
