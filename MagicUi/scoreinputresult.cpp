#include "scoreinputresult.h"
#include "ui_scoreinputresult.h"

ScoreInputResult::ScoreInputResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScoreInputResult)
{
    ui->setupUi(this);
}

ScoreInputResult::~ScoreInputResult()
{
    delete ui;
}

void ScoreInputResult::resizeEvent(QResizeEvent* event){
    if (timerId){
        killTimer(timerId);
        timerId = 0;
    }
    timerId = startTimer(200);
}



void ScoreInputResult::timerEvent(QTimerEvent *te){
    refreshUi();
    killTimer(te->timerId());
    timerId = 0;
}


void ScoreInputResult::refreshUi(){
    for(auto it : children()){
        maximizeFontSize(it);
    }
}

void ScoreInputResult::updateLabelUi(std::vector<std::string> vec){
    QHBoxLayout* layoutResult = this->findChild<QHBoxLayout*>(QString::fromStdString("layout"));
    if(layoutResult != nullptr){
        QLayoutItem* item;
        while( (item = layoutResult->takeAt(0)) != nullptr ){
            if(dynamic_cast<QVBoxLayout*>(item) != nullptr){
                QLayoutItem* item2;
                while( (item2 = ((QVBoxLayout*)item)->takeAt(0)) != nullptr ){
                    if(item2->widget() != nullptr){
                        delete item2->widget();
                    }
                    delete item2;
                }
            }
            if(item->widget() != nullptr){
                delete item->widget();
            }
            delete item;
        }


        for(auto it : vec){
            QVBoxLayout* hLayout = new QVBoxLayout();
            layoutResult->addLayout(hLayout);
            QLabel* lName = new QLabel(this);
            lName->setText(QString::fromStdString(it));
            lName->setMinimumSize(1,1);
            lName->setAlignment(Qt::AlignCenter);
            hLayout->addWidget(lName,1);

            QLineEdit* l= new QLineEdit(this);
            l->setObjectName(QString::fromStdString("l"+it));
            l->setMinimumSize(1,1);
            l->setAlignment(Qt::AlignCenter);
            l->setText("0");
            l->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
            hLayout->addWidget(l,1);
        }

    }

}

void ScoreInputResult::maximizeFontSize(QObject* object){
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
void ScoreInputResult::maximizeFontSizeTemplate(T* it){

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
