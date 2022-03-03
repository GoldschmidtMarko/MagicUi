#ifndef RESETDIALOG_H
#define RESETDIALOG_H

#include <QWidget>

namespace Ui {
class ResetDialog;
}

class ResetDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ResetDialog(QWidget *parent = nullptr);
    ~ResetDialog();

    void refreshUi();

private slots:
    void on_pushButtonNo_clicked();

    void on_pushButtonYes_clicked();

private:
    Ui::ResetDialog *ui;

    void maximizeFontSize(QObject* object);
    template <class T>
    void maximizeFontSizeTemplate(T* it);
};

#endif // RESETDIALOG_H
