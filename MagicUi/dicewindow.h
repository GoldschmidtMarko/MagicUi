#ifndef DICEWINDOW_H
#define DICEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>
#include <stdlib.h>

#include "Define.h"

namespace Ui {
class DiceWindow;
}

class DiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DiceWindow(QWidget *parent = nullptr);
    ~DiceWindow();
    void dice(int amountPlayer);

private:
    Ui::DiceWindow *ui;
    int maxValue = 6;
    int timerId = 0;

    void maximizeFontSize(QObject* object);

    template <class T>
    void maximizeFontSizeTemplate(T* it);

    void resizeEvent(QResizeEvent* event) override;

    void timerEvent(QTimerEvent *te) override;
};

#endif // DICEWINDOW_H
