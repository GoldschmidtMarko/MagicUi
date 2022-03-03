#include "resetdialog.h"
#include "ui_resetdialog.h"

ResetDialog::ResetDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResetDialog)
{
    ui->setupUi(this);
}

ResetDialog::~ResetDialog()
{
    delete ui;
}

void ResetDialog::on_pushButtonNo_clicked(){
    this->close();
}

void ResetDialog::refreshUi(){
    for(auto it : children()){
        maximizeFontSize(it);
    }
}

void ResetDialog::maximizeFontSize(QObject* object){
    if(dynamic_cast<QPushButton*>(object)){
        ((QPushButton*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QPushButton*)object);
    }else if(dynamic_cast<QLabel*>(object)){
        ((QLabel*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QLabel*)object);
    }
}

template <class T>
void ResetDialog::maximizeFontSizeTemplate(T* it){

    QString string = it->text();
    QFont f("Arial",1);
    it->setFont(f);
    QFontMetrics fm(f);
    int width = fm.horizontalAdvance(string);   //Getting the width of the string
    int size = 1;
    int height = fm.height();
    int increment = 300;

    while(increment != 0){
        while(width <= it->width() && height <= it->height()){
            size = it->font().pointSize() + increment;
            f.setPointSize(size);
            it->setFont(f);
            fm = QFontMetrics(f);
            width = fm.horizontalAdvance(string);      //Get the new width
            height = fm.height();
        }

        size -= increment;
        f.setPointSize(size);
        it->setFont(f);
        fm = QFontMetrics(f);
        width = fm.horizontalAdvance(string);      //Get the new width
        height = fm.height();

        increment = increment/2;
    }
    size -= 3;
    if(size <= 0){
        size = 1;
    }
    f.setPointSize(size);
    it->setFont(f);
}


void ResetDialog::on_pushButtonYes_clicked(){

}

