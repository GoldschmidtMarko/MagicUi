/********************************************************************************
** Form generated from reading UI file 'screen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_H
#define UI_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Screen
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QPushButton *buttonEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *buttonReset;
    QPushButton *buttonSetting;
    QPushButton *buttonDice;
    QHBoxLayout *layoutPlayers;

    void setupUi(QWidget *Screen)
    {
        if (Screen->objectName().isEmpty())
            Screen->setObjectName(QString::fromUtf8("Screen"));
        Screen->resize(895, 569);
        Screen->setStyleSheet(QString::fromUtf8("background-color:Green;"));
        verticalLayout = new QVBoxLayout(Screen);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(Screen);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        buttonEdit = new QPushButton(Screen);
        buttonEdit->setObjectName(QString::fromUtf8("buttonEdit"));
        sizePolicy.setHeightForWidth(buttonEdit->sizePolicy().hasHeightForWidth());
        buttonEdit->setSizePolicy(sizePolicy);
        buttonEdit->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_3->addWidget(buttonEdit);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        buttonReset = new QPushButton(Screen);
        buttonReset->setObjectName(QString::fromUtf8("buttonReset"));
        sizePolicy.setHeightForWidth(buttonReset->sizePolicy().hasHeightForWidth());
        buttonReset->setSizePolicy(sizePolicy);
        buttonReset->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_2->addWidget(buttonReset);

        buttonSetting = new QPushButton(Screen);
        buttonSetting->setObjectName(QString::fromUtf8("buttonSetting"));
        sizePolicy.setHeightForWidth(buttonSetting->sizePolicy().hasHeightForWidth());
        buttonSetting->setSizePolicy(sizePolicy);
        buttonSetting->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_2->addWidget(buttonSetting);

        buttonDice = new QPushButton(Screen);
        buttonDice->setObjectName(QString::fromUtf8("buttonDice"));
        sizePolicy.setHeightForWidth(buttonDice->sizePolicy().hasHeightForWidth());
        buttonDice->setSizePolicy(sizePolicy);
        buttonDice->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_2->addWidget(buttonDice);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        layoutPlayers = new QHBoxLayout();
        layoutPlayers->setObjectName(QString::fromUtf8("layoutPlayers"));

        verticalLayout->addLayout(layoutPlayers);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 6);

        retranslateUi(Screen);

        QMetaObject::connectSlotsByName(Screen);
    } // setupUi

    void retranslateUi(QWidget *Screen)
    {
        Screen->setWindowTitle(QCoreApplication::translate("Screen", "Form", nullptr));
        label->setText(QCoreApplication::translate("Screen", "Magic the Gathering Displayer", nullptr));
        buttonEdit->setText(QCoreApplication::translate("Screen", "Edit", nullptr));
        buttonReset->setText(QCoreApplication::translate("Screen", "Reset", nullptr));
        buttonSetting->setText(QCoreApplication::translate("Screen", "Settings", nullptr));
        buttonDice->setText(QCoreApplication::translate("Screen", "Dice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Screen: public Ui_Screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_H
