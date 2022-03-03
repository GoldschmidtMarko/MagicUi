#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontMetrics>
#include <iostream>
#include <QMouseEvent>
#include <QScreen>

#include "screen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Screen s;


    bool resizing = false;
    int timerId = 0;

    template <class T>
    void maximizeFontSizeTemplate(T* it);
    void maximizeFontSize(QObject* object);
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void timerEvent(QTimerEvent *te) override;
};
#endif // MAINWINDOW_H
