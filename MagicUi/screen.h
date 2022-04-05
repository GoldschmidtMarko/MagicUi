#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QScreen>
#include <iostream>
#include <QMouseEvent>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QSlider>

#include "scorewindow.h"
#include "player.h"
#include "pushbuttoncorner.h"
#include "dicewindow.h"
#include "Define.h"
#include "resetdialog.h"
#include "defaultsetting.h"
#include "settingswindow.h"
#include "editwindow.h"

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
    void refreshUiPlayer(Player* p);

private slots:
    void on_buttonEdit_clicked();

    void on_buttonDice_clicked();

    void on_buttonReset_clicked();

    void on_buttonSetting_clicked();

    void on_buttonScore_clicked();

private:
    Ui::Screen *ui;
    DiceWindow *diceWindow;
    ResetDialog *resetDialog;
    DefaultSetting* defaultSetting;
    Settingswindow* settingsWindow;
    Editwindow* editwindow;
    Score* score;

    int timerId2 = 0;

    std::vector<int> buttonsPressed;

    void setupSettingWindow();

    void maximizeFontSize(QObject* object);
    template <class T>
    void maximizeFontSizeTemplate(T* it);

    void refreshPlayerCommander();

    Player* getPlayerByName(std::string name);

    void resizeEvent(QResizeEvent* event) override;

    void timerEvent(QTimerEvent *te) override;

    void setupEditWindow();

    void resetStats();
};

#endif // SCREEN_H
