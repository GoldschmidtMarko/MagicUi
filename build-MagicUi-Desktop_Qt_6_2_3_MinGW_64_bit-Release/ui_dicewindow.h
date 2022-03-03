/********************************************************************************
** Form generated from reading UI file 'dicewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICEWINDOW_H
#define UI_DICEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiceWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *diceLayout;

    void setupUi(QWidget *DiceWindow)
    {
        if (DiceWindow->objectName().isEmpty())
            DiceWindow->setObjectName(QString::fromUtf8("DiceWindow"));
        DiceWindow->resize(400, 300);
        DiceWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(35,39,42);"));
        verticalLayout = new QVBoxLayout(DiceWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DiceWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        diceLayout = new QHBoxLayout();
        diceLayout->setObjectName(QString::fromUtf8("diceLayout"));

        verticalLayout->addLayout(diceLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 6);

        retranslateUi(DiceWindow);

        QMetaObject::connectSlotsByName(DiceWindow);
    } // setupUi

    void retranslateUi(QWidget *DiceWindow)
    {
        DiceWindow->setWindowTitle(QCoreApplication::translate("DiceWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("DiceWindow", "Dice results:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DiceWindow: public Ui_DiceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICEWINDOW_H
