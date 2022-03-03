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
    QPushButton *addPlayer;
    QPushButton *removePlayer;
    QVBoxLayout *verticalLayout_3;
    QPushButton *commanderDamage;
    QPushButton *infectDamage;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *diceValue;
    QLineEdit *lineEdit;
    QLabel *label_2;

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
        addPlayer = new QPushButton(Settingswindow);
        addPlayer->setObjectName(QString::fromUtf8("addPlayer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addPlayer->sizePolicy().hasHeightForWidth());
        addPlayer->setSizePolicy(sizePolicy);
        addPlayer->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_2->addWidget(addPlayer);

        removePlayer = new QPushButton(Settingswindow);
        removePlayer->setObjectName(QString::fromUtf8("removePlayer"));
        sizePolicy.setHeightForWidth(removePlayer->sizePolicy().hasHeightForWidth());
        removePlayer->setSizePolicy(sizePolicy);
        removePlayer->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_2->addWidget(removePlayer);


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
        diceValue = new QPushButton(Settingswindow);
        diceValue->setObjectName(QString::fromUtf8("diceValue"));
        sizePolicy.setHeightForWidth(diceValue->sizePolicy().hasHeightForWidth());
        diceValue->setSizePolicy(sizePolicy);
        diceValue->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_5->addWidget(diceValue);

        lineEdit = new QLineEdit(Settingswindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:White;"));

        verticalLayout_5->addWidget(lineEdit);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(1, 1);

        verticalLayout_4->addLayout(verticalLayout_5);

        label_2 = new QLabel(Settingswindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

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
        diceValue->setText(QCoreApplication::translate("Settingswindow", "Dice Value", nullptr));
        label_2->setText(QCoreApplication::translate("Settingswindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settingswindow: public Ui_Settingswindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
