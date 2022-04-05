#ifndef SCOREINPUTRESULT_H
#define SCOREINPUTRESULT_H

#include <QWidget>
#include <QLineEdit>
#include <iostream>

namespace Ui {
class ScoreInputResult;
}

class ScoreInputResult : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreInputResult(QWidget *parent = nullptr);

    void updateLabelUi(std::vector<std::string> vec);

    ~ScoreInputResult();

private:
    Ui::ScoreInputResult *ui;

    void resizeEvent(QResizeEvent* event) override;

    void timerEvent(QTimerEvent *te) override;

    void refreshUi();

    void maximizeFontSize(QObject* object);

    template <class T>
    void maximizeFontSizeTemplate(T* it);

    int timerId = 0;


};

#endif // SCOREINPUTRESULT_H
