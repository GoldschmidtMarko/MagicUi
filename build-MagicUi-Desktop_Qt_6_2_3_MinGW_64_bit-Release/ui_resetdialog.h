/********************************************************************************
** Form generated from reading UI file 'resetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETDIALOG_H
#define UI_RESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonYes;
    QPushButton *pushButtonNo;

    void setupUi(QWidget *ResetDialog)
    {
        if (ResetDialog->objectName().isEmpty())
            ResetDialog->setObjectName(QString::fromUtf8("ResetDialog"));
        ResetDialog->resize(400, 300);
        ResetDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(35,39,42);"));
        verticalLayout = new QVBoxLayout(ResetDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ResetDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonYes = new QPushButton(ResetDialog);
        pushButtonYes->setObjectName(QString::fromUtf8("pushButtonYes"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonYes->sizePolicy().hasHeightForWidth());
        pushButtonYes->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonYes);

        pushButtonNo = new QPushButton(ResetDialog);
        pushButtonNo->setObjectName(QString::fromUtf8("pushButtonNo"));
        sizePolicy.setHeightForWidth(pushButtonNo->sizePolicy().hasHeightForWidth());
        pushButtonNo->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonNo);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ResetDialog);

        QMetaObject::connectSlotsByName(ResetDialog);
    } // setupUi

    void retranslateUi(QWidget *ResetDialog)
    {
        ResetDialog->setWindowTitle(QCoreApplication::translate("ResetDialog", "Form", nullptr));
        label->setText(QCoreApplication::translate("ResetDialog", "Reset?", nullptr));
        pushButtonYes->setText(QCoreApplication::translate("ResetDialog", "Yes", nullptr));
        pushButtonNo->setText(QCoreApplication::translate("ResetDialog", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetDialog: public Ui_ResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETDIALOG_H
