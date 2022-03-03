#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class Settingswindow;
}

class Settingswindow : public QWidget
{
    Q_OBJECT

public:
    explicit Settingswindow(QWidget *parent = nullptr);
    void refreshUi();
    ~Settingswindow();

private:
    Ui::Settingswindow *ui;

    void maximizeFontSize(QObject* object);
    template <class T>
    void maximizeFontSizeTemplate(T* it);
};

#endif // SETTINGSWINDOW_H
