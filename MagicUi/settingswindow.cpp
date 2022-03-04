#include "settingswindow.h"
#include "ui_settingswindow.h"

Settingswindow::Settingswindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settingswindow)
{
    ui->setupUi(this);
}

Settingswindow::~Settingswindow()
{
    delete ui;
}

void Settingswindow::refreshUi(){
    for(auto it : children()){
        maximizeFontSize(it);
    }
}

void Settingswindow::maximizeFontSize(QObject* object){
    if(dynamic_cast<QPushButton*>(object)){
        ((QPushButton*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QPushButton*)object);
    }else if(dynamic_cast<QLabel*>(object)){
        ((QLabel*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QLabel*)object);
    }else if(dynamic_cast<QLineEdit*>(object)){
        ((QLineEdit*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QLineEdit*)object);
    }
}

template <class T>
void Settingswindow::maximizeFontSizeTemplate(T* it){

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
