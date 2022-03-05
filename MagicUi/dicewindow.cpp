#include "dicewindow.h"
#include "ui_dicewindow.h"

DiceWindow::DiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiceWindow)
{
    ui->setupUi(this);
}

DiceWindow::~DiceWindow()
{
    delete ui;
}

void DiceWindow::dice(std::vector<Player*> vec){
    QHBoxLayout* layoutDice = this->findChild<QHBoxLayout*>(QString::fromStdString("diceLayout"));
    if(layoutDice != nullptr){
        QLayoutItem* item;
        while( (item = layoutDice->takeAt(0)) != nullptr ){
            if(dynamic_cast<QVBoxLayout*>(item) != nullptr){
                QLayoutItem* item2;
                while( (item2 = ((QVBoxLayout*)item)->takeAt(0)) != nullptr ){
                    delete item2->widget();
                    delete item2;
                }
            }
            delete item->widget();
            delete item;
        }
    }
    std::vector<int> values;
    int max = 1;
    for(int i = 0; i < (int)vec.size(); ++i){
        int r = rand() % maxValue + 1;
        if(r > max){
            max = r;
        }
        values.push_back(r);
    }
    for(int i = 0; i < (int)vec.size(); ++i){
        QVBoxLayout* layout = new QVBoxLayout();
        layoutDice->addLayout(layout);

        QLabel* lName = new QLabel(this);
        lName->setText(QString::fromStdString(vec.at(i)->name));
        lName->setMinimumSize(1,1);
        lName->setAlignment(Qt::AlignCenter);
        layout->addWidget(lName,1);

        QLabel* l= new QLabel(this);
        l->setText(QString::fromStdString(std::to_string(values.at(i))));
        l->setMinimumSize(1,1);
        l->setAlignment(Qt::AlignCenter);
        if(values.at(i) == max){
            l->setStyleSheet(COLOR_LIGHTBLUE);
        }
        layout->addWidget(l,3);

    }
    timerId = startTimer(1);
}

void DiceWindow::resizeEvent(QResizeEvent* event){

    if (timerId){
        killTimer(timerId);
        timerId = 0;
    }
    timerId = startTimer(200);
}

void DiceWindow::timerEvent(QTimerEvent *te){
    auto childs = children();
    for(auto it : childs){
        maximizeFontSize(it);
    }
    killTimer(te->timerId());
    timerId = 0;
}


void DiceWindow::maximizeFontSize(QObject* object){
    if(dynamic_cast<QPushButton*>(object)){
        ((QPushButton*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QPushButton*)object);
    }else if(dynamic_cast<QLabel*>(object)){
        ((QLabel*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QLabel*)object);
    }
}

template <class T>
void DiceWindow::maximizeFontSizeTemplate(T* it){

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
