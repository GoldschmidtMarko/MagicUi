#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QWidget>
#include <QSpacerItem>
#include <map>

#include <player.h>
#include "scoreinputresult.h"
#include "Define.h"

namespace Ui {
class Score;
}

class Score : public QWidget
{
    Q_OBJECT

    class Result{
    public:
        int place;
        std::string name;
    };

public:
    explicit Score(QWidget *parent = nullptr);

    void updatePlayers(std::vector<Player*> vec);

    int timerId = 0;

    ~Score();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Score *ui;
    ScoreInputResult* scoreinputresult;

    std::vector<std::string> players;

    std::vector<std::vector<Result*>> rounds;

    void refreshUi();

    void refreshTotalScore();

    void setupRoundsAndResult(std::vector<Result*>& vec);

    void resizeEvent(QResizeEvent* event) override;

    void timerEvent(QTimerEvent *te) override;

    void maximizeFontSize(QObject* object);

    template <class T>
    void maximizeFontSizeTemplate(T* it);

};

#endif // SCOREWINDOW_H
