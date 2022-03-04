/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settingswindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QPushButton *addPlayer;
    QLineEdit *lineAdd;
    QVBoxLayout *verticalLayout_8;
    QPushButton *removePlayer;
    QLineEdit *lineRemove;
    QVBoxLayout *verticalLayout_3;
    QPushButton *commanderDamage;
    QPushButton *infectDamage;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *dicebutton;
    QLineEdit *lineDice;
    QVBoxLayout *verticalLayout_6;
    QPushButton *initialHP;
    QLineEdit *lineHP;

    void setupUi(QWidget *Settingswindow)
    {
        if (Settingswindow->objectName().isEmpty())
            Settingswindow->setObjectName(QString::fromUtf8("Settingswindow"));
        Settingswindow->resize(949, 433);
        Settingswindow->setStyleSheet(QString::fromUtf8("background-color: rgb(35,39,42);"));
        verticalLayout = new QVBoxLayout(Settingswindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Settingswindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        addPlayer = new QPushButton(Settingswindow);
        addPlayer->setObjectName(QString::fromUtf8("addPlayer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addPlayer->sizePolicy().hasHeightForWidth());
        addPlayer->setSizePolicy(sizePolicy);
        addPlayer->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_7->addWidget(addPlayer);

        lineAdd = new QLineEdit(Settingswindow);
        lineAdd->setObjectName(QString::fromUtf8("lineAdd"));
        sizePolicy.setHeightForWidth(lineAdd->sizePolicy().hasHeightForWidth());
        lineAdd->setSizePolicy(sizePolicy);
        lineAdd->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_7->addWidget(lineAdd);

        verticalLayout_7->setStretch(0, 2);
        verticalLayout_7->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        removePlayer = new QPushButton(Settingswindow);
        removePlayer->setObjectName(QString::fromUtf8("removePlayer"));
        sizePolicy.setHeightForWidth(removePlayer->sizePolicy().hasHeightForWidth());
        removePlayer->setSizePolicy(sizePolicy);
        removePlayer->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_8->addWidget(removePlayer);

        lineRemove = new QLineEdit(Settingswindow);
        lineRemove->setObjectName(QString::fromUtf8("lineRemove"));
        sizePolicy.setHeightForWidth(lineRemove->sizePolicy().hasHeightForWidth());
        lineRemove->setSizePolicy(sizePolicy);
        lineRemove->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_8->addWidget(lineRemove);

        verticalLayout_8->setStretch(0, 2);
        verticalLayout_8->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        buttonLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        commanderDamage = new QPushButton(Settingswindow);
        commanderDamage->setObjectName(QString::fromUtf8("commanderDamage"));
        sizePolicy.setHeightForWidth(commanderDamage->sizePolicy().hasHeightForWidth());
        commanderDamage->setSizePolicy(sizePolicy);
        commanderDamage->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_3->addWidget(commanderDamage);

        infectDamage = new QPushButton(Settingswindow);
        infectDamage->setObjectName(QString::fromUtf8("infectDamage"));
        sizePolicy.setHeightForWidth(infectDamage->sizePolicy().hasHeightForWidth());
        infectDamage->setSizePolicy(sizePolicy);
        infectDamage->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_3->addWidget(infectDamage);


        buttonLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        dicebutton = new QPushButton(Settingswindow);
        dicebutton->setObjectName(QString::fromUtf8("dicebutton"));
        sizePolicy.setHeightForWidth(dicebutton->sizePolicy().hasHeightForWidth());
        dicebutton->setSizePolicy(sizePolicy);
        dicebutton->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_5->addWidget(dicebutton);

        lineDice = new QLineEdit(Settingswindow);
        lineDice->setObjectName(QString::fromUtf8("lineDice"));
        sizePolicy.setHeightForWidth(lineDice->sizePolicy().hasHeightForWidth());
        lineDice->setSizePolicy(sizePolicy);
        lineDice->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_5->addWidget(lineDice);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(1, 1);

        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        initialHP = new QPushButton(Settingswindow);
        initialHP->setObjectName(QString::fromUtf8("initialHP"));
        sizePolicy.setHeightForWidth(initialHP->sizePolicy().hasHeightForWidth());
        initialHP->setSizePolicy(sizePolicy);
        initialHP->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_6->addWidget(initialHP);

        lineHP = new QLineEdit(Settingswindow);
        lineHP->setObjectName(QString::fromUtf8("lineHP"));
        sizePolicy.setHeightForWidth(lineHP->sizePolicy().hasHeightForWidth());
        lineHP->setSizePolicy(sizePolicy);
        lineHP->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_6->addWidget(lineHP);

        verticalLayout_6->setStretch(0, 2);
        verticalLayout_6->setStretch(1, 1);

        verticalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 1);

        buttonLayout->addLayout(verticalLayout_4);

        buttonLayout->setStretch(0, 1);
        buttonLayout->setStretch(1, 1);
        buttonLayout->setStretch(2, 1);

        verticalLayout->addLayout(buttonLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);

        retranslateUi(Settingswindow);

        QMetaObject::connectSlotsByName(Settingswindow);
    } // setupUi

    void retranslateUi(QWidget *Settingswindow)
    {
        Settingswindow->setWindowTitle(QCoreApplication::translate("Settingswindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("Settingswindow", "Settings:", nullptr));
        addPlayer->setText(QCoreApplication::translate("Settingswindow", "Add Player", nullptr));
        removePlayer->setText(QCoreApplication::translate("Settingswindow", "Remove Player", nullptr));
        commanderDamage->setText(QCoreApplication::translate("Settingswindow", "Commander Damage", nullptr));
        infectDamage->setText(QCoreApplication::translate("Settingswindow", "Infect Damage", nullptr));
        dicebutton->setText(QCoreApplication::translate("Settingswindow", "Dice Value: ", nullptr));
        initialHP->setText(QCoreApplication::translate("Settingswindow", "Initial HP:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settingswindow: public Ui_Settingswindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
