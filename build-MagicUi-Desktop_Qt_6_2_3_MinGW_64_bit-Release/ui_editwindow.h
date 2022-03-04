/********************************************************************************
** Form generated from reading UI file 'editwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWINDOW_H
#define UI_EDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editwindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QSlider *sliderR;
    QSlider *sliderG;
    QSlider *sliderB;
    QLabel *displayColor;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioBackground;
    QRadioButton *radioFont;
    QPushButton *rerollButton;
    QPushButton *applyButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;

    void setupUi(QWidget *Editwindow)
    {
        if (Editwindow->objectName().isEmpty())
            Editwindow->setObjectName(QString::fromUtf8("Editwindow"));
        Editwindow->resize(1185, 656);
        Editwindow->setStyleSheet(QString::fromUtf8("background-color: rgb(35,39,42);"));
        verticalLayout = new QVBoxLayout(Editwindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Editwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sliderR = new QSlider(Editwindow);
        sliderR->setObjectName(QString::fromUtf8("sliderR"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sliderR->sizePolicy().hasHeightForWidth());
        sliderR->setSizePolicy(sizePolicy);
        sliderR->setMaximum(255);
        sliderR->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(sliderR);

        sliderG = new QSlider(Editwindow);
        sliderG->setObjectName(QString::fromUtf8("sliderG"));
        sizePolicy.setHeightForWidth(sliderG->sizePolicy().hasHeightForWidth());
        sliderG->setSizePolicy(sizePolicy);
        sliderG->setMaximum(255);
        sliderG->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(sliderG);

        sliderB = new QSlider(Editwindow);
        sliderB->setObjectName(QString::fromUtf8("sliderB"));
        sizePolicy.setHeightForWidth(sliderB->sizePolicy().hasHeightForWidth());
        sliderB->setSizePolicy(sizePolicy);
        sliderB->setMaximum(255);
        sliderB->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(sliderB);


        horizontalLayout->addLayout(verticalLayout_2);

        displayColor = new QLabel(Editwindow);
        displayColor->setObjectName(QString::fromUtf8("displayColor"));
        displayColor->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(displayColor);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        radioBackground = new QRadioButton(Editwindow);
        radioBackground->setObjectName(QString::fromUtf8("radioBackground"));
        sizePolicy.setHeightForWidth(radioBackground->sizePolicy().hasHeightForWidth());
        radioBackground->setSizePolicy(sizePolicy);
        radioBackground->setStyleSheet(QString::fromUtf8("background-color:White;"));

        horizontalLayout_5->addWidget(radioBackground);

        radioFont = new QRadioButton(Editwindow);
        radioFont->setObjectName(QString::fromUtf8("radioFont"));
        sizePolicy.setHeightForWidth(radioFont->sizePolicy().hasHeightForWidth());
        radioFont->setSizePolicy(sizePolicy);
        radioFont->setStyleSheet(QString::fromUtf8("background-color:White;"));

        horizontalLayout_5->addWidget(radioFont);

        rerollButton = new QPushButton(Editwindow);
        rerollButton->setObjectName(QString::fromUtf8("rerollButton"));
        sizePolicy.setHeightForWidth(rerollButton->sizePolicy().hasHeightForWidth());
        rerollButton->setSizePolicy(sizePolicy);
        rerollButton->setStyleSheet(QString::fromUtf8("background-color:White;"));

        horizontalLayout_5->addWidget(rerollButton);

        applyButton = new QPushButton(Editwindow);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        sizePolicy.setHeightForWidth(applyButton->sizePolicy().hasHeightForWidth());
        applyButton->setSizePolicy(sizePolicy);
        applyButton->setStyleSheet(QString::fromUtf8("background-color:White;"));

        horizontalLayout_5->addWidget(applyButton);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        button1 = new QPushButton(Editwindow);
        button1->setObjectName(QString::fromUtf8("button1"));
        sizePolicy.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(button1);

        button2 = new QPushButton(Editwindow);
        button2->setObjectName(QString::fromUtf8("button2"));
        sizePolicy.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(button2);

        button3 = new QPushButton(Editwindow);
        button3->setObjectName(QString::fromUtf8("button3"));
        sizePolicy.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(button3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        button4 = new QPushButton(Editwindow);
        button4->setObjectName(QString::fromUtf8("button4"));
        sizePolicy.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(button4);

        button5 = new QPushButton(Editwindow);
        button5->setObjectName(QString::fromUtf8("button5"));
        sizePolicy.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(button5);

        button6 = new QPushButton(Editwindow);
        button6->setObjectName(QString::fromUtf8("button6"));
        sizePolicy.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(button6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        button7 = new QPushButton(Editwindow);
        button7->setObjectName(QString::fromUtf8("button7"));
        sizePolicy.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(button7);

        button8 = new QPushButton(Editwindow);
        button8->setObjectName(QString::fromUtf8("button8"));
        sizePolicy.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(button8);

        button9 = new QPushButton(Editwindow);
        button9->setObjectName(QString::fromUtf8("button9"));
        sizePolicy.setHeightForWidth(button9->sizePolicy().hasHeightForWidth());
        button9->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(button9);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 3);
        verticalLayout->setStretch(4, 3);
        verticalLayout->setStretch(5, 3);

        retranslateUi(Editwindow);

        QMetaObject::connectSlotsByName(Editwindow);
    } // setupUi

    void retranslateUi(QWidget *Editwindow)
    {
        Editwindow->setWindowTitle(QCoreApplication::translate("Editwindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("Editwindow", "Editing:", nullptr));
        displayColor->setText(QCoreApplication::translate("Editwindow", "Display Color", nullptr));
        radioBackground->setText(QCoreApplication::translate("Editwindow", "Background Color", nullptr));
        radioFont->setText(QCoreApplication::translate("Editwindow", "Font Color", nullptr));
        rerollButton->setText(QCoreApplication::translate("Editwindow", "Reroll Color", nullptr));
        applyButton->setText(QCoreApplication::translate("Editwindow", "Apply Color", nullptr));
        button1->setText(QString());
        button2->setText(QString());
        button3->setText(QString());
        button4->setText(QString());
        button5->setText(QString());
        button6->setText(QString());
        button7->setText(QString());
        button8->setText(QString());
        button9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Editwindow: public Ui_Editwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
