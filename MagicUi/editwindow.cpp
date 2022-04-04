#include "editwindow.h"
#include "ui_editwindow.h"

Editwindow::Editwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editwindow)
{
    ui->setupUi(this);
    setMinimumSize(1,1);

    timerId2 = startTimer(1);
}



void Editwindow::generateColors(){
    for(int i = 1; i < 10;++i){
        int r =  rand() % 256;
        int g =  rand() % 256;
        int b =  rand() % 256;
        QPushButton* button = findChild<QPushButton*>(QString::fromStdString("button" + std::to_string(i)));
        button->setStyleSheet(QString::fromStdString("background-color: rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ");"));
        connect(button, &QPushButton::clicked, [=]() {
            QLabel* displayColor = findChild<QLabel*>(QString::fromStdString("displayColor"));
            std::string background =  "background-color: " + displayColor->palette().button().color().name().toStdString();
            std::string font = "color: " + displayColor->palette().text().color().name().toStdString();

            QRadioButton* radioBackground = findChild<QRadioButton*>(QString::fromStdString("radioBackground"));
            if(radioBackground->isChecked()){
                background = "background-color: " + button->palette().button().color().name().toStdString();
            }else{
                font = "color: " + button->palette().button().color().name().toStdString();
            }
            displayColor->setStyleSheet(QString::fromStdString(background + ";" + font));

            QSlider* sliderR = findChild<QSlider*>(QString::fromStdString("sliderR"));
            sliderR->setSliderPosition(r);
            QSlider* sliderG = findChild<QSlider*>(QString::fromStdString("sliderG"));
            sliderG->setSliderPosition(g);
            QSlider* sliderB = findChild<QSlider*>(QString::fromStdString("sliderB"));
            sliderB->setSliderPosition(b);

        });
    }

    QPushButton* buttonGreen = findChild<QPushButton*>(QString::fromStdString("buttonGreen"));
    buttonGreen->setStyleSheet(QString::fromStdString("background-color: rgb(0,128,0);"));
    connect(buttonGreen, &QPushButton::clicked, [=]() {
        QLabel* displayColor = findChild<QLabel*>(QString::fromStdString("displayColor"));
        std::string background =  "background-color: " + displayColor->palette().button().color().name().toStdString();
        std::string font = "color: " + displayColor->palette().text().color().name().toStdString();

        QRadioButton* radioBackground = findChild<QRadioButton*>(QString::fromStdString("radioBackground"));
        if(radioBackground->isChecked()){
            background = "background-color: " + buttonGreen->palette().button().color().name().toStdString();
        }else{
            font = "color: " + buttonGreen->palette().button().color().name().toStdString();
        }
        displayColor->setStyleSheet(QString::fromStdString(background + ";" + font));

        QSlider* sliderR = findChild<QSlider*>(QString::fromStdString("sliderR"));
        sliderR->setSliderPosition(0);
        QSlider* sliderG = findChild<QSlider*>(QString::fromStdString("sliderG"));
        sliderG->setSliderPosition(128);
        QSlider* sliderB = findChild<QSlider*>(QString::fromStdString("sliderB"));
        sliderB->setSliderPosition(0);

    });

    QPushButton* buttonRed = findChild<QPushButton*>(QString::fromStdString("buttonRed"));
    buttonRed->setStyleSheet(QString::fromStdString("background-color: rgb(255,0,0);"));
    connect(buttonRed, &QPushButton::clicked, [=]() {
        QLabel* displayColor = findChild<QLabel*>(QString::fromStdString("displayColor"));
        std::string background =  "background-color: " + displayColor->palette().button().color().name().toStdString();
        std::string font = "color: " + displayColor->palette().text().color().name().toStdString();

        QRadioButton* radioBackground = findChild<QRadioButton*>(QString::fromStdString("radioBackground"));
        if(radioBackground->isChecked()){
            background = "background-color: " + buttonRed->palette().button().color().name().toStdString();
        }else{
            font = "color: " + buttonRed->palette().button().color().name().toStdString();
        }
        displayColor->setStyleSheet(QString::fromStdString(background + ";" + font));

        QSlider* sliderR = findChild<QSlider*>(QString::fromStdString("sliderR"));
        sliderR->setSliderPosition(255);
        QSlider* sliderG = findChild<QSlider*>(QString::fromStdString("sliderG"));
        sliderG->setSliderPosition(0);
        QSlider* sliderB = findChild<QSlider*>(QString::fromStdString("sliderB"));
        sliderB->setSliderPosition(0);

    });

    QPushButton* buttonBlue = findChild<QPushButton*>(QString::fromStdString("buttonBlue"));
    buttonBlue->setStyleSheet(QString::fromStdString("background-color: rgb(0,0,255);"));
    connect(buttonBlue, &QPushButton::clicked, [=]() {
        QLabel* displayColor = findChild<QLabel*>(QString::fromStdString("displayColor"));
        std::string background =  "background-color: " + displayColor->palette().button().color().name().toStdString();
        std::string font = "color: " + displayColor->palette().text().color().name().toStdString();

        QRadioButton* radioBackground = findChild<QRadioButton*>(QString::fromStdString("radioBackground"));
        if(radioBackground->isChecked()){
            background = "background-color: " + buttonBlue->palette().button().color().name().toStdString();
        }else{
            font = "color: " + buttonBlue->palette().button().color().name().toStdString();
        }
        displayColor->setStyleSheet(QString::fromStdString(background + ";" + font));

        QSlider* sliderR = findChild<QSlider*>(QString::fromStdString("sliderR"));
        sliderR->setSliderPosition(0);
        QSlider* sliderG = findChild<QSlider*>(QString::fromStdString("sliderG"));
        sliderG->setSliderPosition(0);
        QSlider* sliderB = findChild<QSlider*>(QString::fromStdString("sliderB"));
        sliderB->setSliderPosition(255);

    });

    QPushButton* buttonBlack = findChild<QPushButton*>(QString::fromStdString("buttonBlack"));
    buttonBlack->setStyleSheet(QString::fromStdString("background-color: rgb(0,0,0);"));
    connect(buttonBlack, &QPushButton::clicked, [=]() {
        QLabel* displayColor = findChild<QLabel*>(QString::fromStdString("displayColor"));
        std::string background =  "background-color: " + displayColor->palette().button().color().name().toStdString();
        std::string font = "color: " + displayColor->palette().text().color().name().toStdString();

        QRadioButton* radioBackground = findChild<QRadioButton*>(QString::fromStdString("radioBackground"));
        if(radioBackground->isChecked()){
            background = "background-color: " + buttonBlack->palette().button().color().name().toStdString();
        }else{
            font = "color: " + buttonBlack->palette().button().color().name().toStdString();
        }
        displayColor->setStyleSheet(QString::fromStdString(background + ";" + font));

        QSlider* sliderR = findChild<QSlider*>(QString::fromStdString("sliderR"));
        sliderR->setSliderPosition(0);
        QSlider* sliderG = findChild<QSlider*>(QString::fromStdString("sliderG"));
        sliderG->setSliderPosition(0);
        QSlider* sliderB = findChild<QSlider*>(QString::fromStdString("sliderB"));
        sliderB->setSliderPosition(0);

    });

    QPushButton* buttonWhite = findChild<QPushButton*>(QString::fromStdString("buttonWhite"));
    buttonWhite->setStyleSheet(QString::fromStdString("background-color: rgb(255,255,255);"));
    connect(buttonWhite, &QPushButton::clicked, [=]() {
        QLabel* displayColor = findChild<QLabel*>(QString::fromStdString("displayColor"));
        std::string background =  "background-color: " + displayColor->palette().button().color().name().toStdString();
        std::string font = "color: " + displayColor->palette().text().color().name().toStdString();

        QRadioButton* radioBackground = findChild<QRadioButton*>(QString::fromStdString("radioBackground"));
        if(radioBackground->isChecked()){
            background = "background-color: " + buttonWhite->palette().button().color().name().toStdString();
        }else{
            font = "color: " + buttonWhite->palette().button().color().name().toStdString();
        }
        displayColor->setStyleSheet(QString::fromStdString(background + ";" + font));

        QSlider* sliderR = findChild<QSlider*>(QString::fromStdString("sliderR"));
        sliderR->setSliderPosition(255);
        QSlider* sliderG = findChild<QSlider*>(QString::fromStdString("sliderG"));
        sliderG->setSliderPosition(255);
        QSlider* sliderB = findChild<QSlider*>(QString::fromStdString("sliderB"));
        sliderB->setSliderPosition(255);

    });



}

void Editwindow::setSelectedPlayers(std::vector<Player*> vec){
    vecPlayers.clear();
    for(auto it : vec){
        vecPlayers.push_back(it);
    }
}


Editwindow::~Editwindow()
{
    delete ui;
}


void Editwindow::resizeEvent(QResizeEvent* event){
    if (timerId2){
        killTimer(timerId2);
        timerId2 = 0;
    }
    timerId2 = startTimer(200);
}

void Editwindow::timerEvent(QTimerEvent *te){
    auto childs = children();
    for(auto it : childs){
        maximizeFontSize(it);
    }
    killTimer(te->timerId());
    timerId2 = 0;
}

void Editwindow::maximizeFontSize(QObject* object){
    if(dynamic_cast<QPushButton*>(object)){
        ((QPushButton*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QPushButton*)object);
    }else if(dynamic_cast<QLabel*>(object)){
        ((QLabel*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QLabel*)object);
    }else if(dynamic_cast<QRadioButton*>(object)){
        ((QRadioButton*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QRadioButton*)object);
    }
}

template <class T>
void Editwindow::maximizeFontSizeTemplate(T* it){

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
