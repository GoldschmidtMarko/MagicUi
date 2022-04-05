#ifndef SCOREADDRESULT_H
#define SCOREADDRESULT_H

#include <QWidget>

namespace Ui {
class ScoreAddResult;
}

class ScoreAddResult : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreAddResult(QWidget *parent = nullptr);
    ~ScoreAddResult();

private:
    Ui::ScoreAddResult *ui;
};

#endif // SCOREADDRESULT_H
