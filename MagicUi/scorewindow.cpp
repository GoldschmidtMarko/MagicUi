#include "scorewindow.h"
#include "ui_scorewindow.h"

Score::Score(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Score)
{
    ui->setupUi(this);


    setMinimumSize(1,1);

    scoreinputresult = new ScoreInputResult();

    timerId = startTimer(1);


    QPushButton* applyButton = scoreinputresult->findChild<QPushButton*>(QString::fromStdString("pushButton"));
    connect(applyButton, &QPushButton::clicked, [=]() {
        std::vector<Result*> vec;
        for(auto it : players){
            int v = ((QLineEdit*)scoreinputresult->findChild<QLineEdit*>(QString::fromStdString("l" + it)))->text().toInt();
            Result* r = new Result();
            r->name = it;
            r->place = v;
            vec.push_back(r);
        }
        rounds.push_back(vec);
        setupRoundsAndResult(vec);
        refreshTotalScore();
        startTimer(1);
   });
}

Score::~Score()
{
    delete(scoreinputresult);
    delete ui;
}

void Score::resizeEvent(QResizeEvent* event){
    if (timerId){
        killTimer(timerId);
        timerId = 0;
    }
    timerId = startTimer(200);
}

void Score::updatePlayers(std::vector<Player*> vec){
    for(auto it : vec){
        bool found = false;
        for(auto it2 : players){
            if(it->name == it2){
                found = true;
                break;
            }
        }
        if(!found){
            players.push_back(it->name);
        }
    }
}

void Score::timerEvent(QTimerEvent *te){
    refreshUi();
    killTimer(te->timerId());
    timerId = 0;
}

void Score::setupRoundsAndResult(std::vector<Result*>& vec){
    QVBoxLayout* layoutPlayers = this->findChild<QVBoxLayout*>(QString::fromStdString("layoutGamesPlayer"));
    for(auto it : vec){
        bool present = false;

        if(this->findChild<QLabel*>(QString::fromStdString(it->name)) != nullptr){
            present = true;
            break;
        }

        if(!present){
            QLabel* l = new QLabel(this);
            l->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            l->setText(QString::fromStdString(it->name));
            l->setStyleSheet(QString::fromStdString(COLOR_LIGHTBLUE));
            l->setAlignment(Qt::AlignCenter);
            l->setObjectName(QString::fromStdString(it->name));
            layoutPlayers->addWidget(l,1);
        }
    }

    QVBoxLayout* vLayout = new QVBoxLayout();
    QHBoxLayout* layoutGames = this->findChild<QHBoxLayout*>(QString::fromStdString("layoutGames"));

    layoutGames->addLayout(vLayout,3);

    for(int i = 0; i < layoutPlayers->count();++i){
        if(dynamic_cast<QLabel*>(layoutPlayers->itemAt(i)->widget()) != nullptr){
            std::string qLabelName = ((QLabel*)layoutPlayers->itemAt(i)->widget())->objectName().toStdString();
            bool found = false;
            for(auto it : vec){
                if(it->name == qLabelName){
                    found = true;
                    QLabel* l = new QLabel(this);
                    l->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
                    l->setText(QString::fromStdString(std::to_string(it->place)));
                    l->setStyleSheet(QString::fromStdString(COLOR_LIGHTBLUE));
                    l->setAlignment(Qt::AlignCenter);
                    vLayout->addWidget(l,1);
                    break;
                }
            }

            if(!found){
                std::cout << "spacer added" << std::endl;
                QSpacerItem* spacer = new QSpacerItem(QSizePolicy::Preferred, QSizePolicy::Preferred);
                vLayout->addSpacerItem(spacer);
            }
        }
    }
}

void Score::refreshUi(){
    for(auto it : children()){
        maximizeFontSize(it);
    }
}

void Score::refreshTotalScore(){
    QHBoxLayout* layoutResult = this->findChild<QHBoxLayout*>(QString::fromStdString("layoutResult"));
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


        std::map<std::string,int> map;
        for(auto it : rounds){
            for(auto it2 : it){
                if(map.find(it2->name) != map.end()){
                    map.at(it2->name) += 1 + it.size() - it2->place;
                }else{
                    map.insert({it2->name, 1 + it.size() - it2->place});
                }
            }
        }
        while(map.size() > 0){
            std::string charMax = "";
            int maxValue = 0;
            for(auto it : map){
                if(it.second > maxValue){
                    charMax = it.first;
                    maxValue = it.second;
                }
            }

            QVBoxLayout* vLayout = new QVBoxLayout();
            layoutResult->addLayout(vLayout,1);
            QLabel* name = new QLabel(this);
            name->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            name->setText(QString::fromStdString(charMax));
            name->setStyleSheet(QString::fromStdString(COLOR_LIGHTBLUE));
            name->setAlignment(Qt::AlignCenter);
            vLayout->addWidget(name,1);

            QLabel* score = new QLabel(this);
            score->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            score->setText(QString::fromStdString(std::to_string(maxValue)));
            score->setStyleSheet(QString::fromStdString(COLOR_LIGHTBLUE));
            score->setAlignment(Qt::AlignCenter);
            vLayout->addWidget(score,1);

            map.erase(map.find(charMax));
        }


    }
}

void Score::maximizeFontSize(QObject* object){
    if(dynamic_cast<QPushButton*>(object)){
        ((QPushButton*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QPushButton*)object);
    }else if(dynamic_cast<QLabel*>(object)){
        ((QLabel*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QLabel*)object);
    }
}

template <class T>
void Score::maximizeFontSizeTemplate(T* it){

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

void Score::on_pushButton_clicked(){
    double factor = double(6)/8;
    scoreinputresult->resize(width() * factor, height() * factor);
    scoreinputresult->move(x() + (width() - scoreinputresult->width())/2 ,y() + (height() - scoreinputresult->height())/2 );
    scoreinputresult->setMaximumSize(width(),height());
    scoreinputresult->updateLabelUi(players);
    scoreinputresult->startTimer(1);
    scoreinputresult->show();
}

void Score::on_pushButton_2_clicked(){
    if(rounds.size() > 0){
        for(auto it : rounds.back()){
            delete(it);
        }
        rounds.pop_back();
        QHBoxLayout* layoutGames = this->findChild<QHBoxLayout*>(QString::fromStdString("layoutGames"));
        QVBoxLayout* vlayout = (QVBoxLayout*)layoutGames->takeAt(layoutGames->count()-1);
        QLayoutItem* item;
        while( (item = vlayout->takeAt(0)) != nullptr ){
            if(item->widget() != nullptr){
                delete item->widget();
            }
            delete item;
        }
        delete vlayout;
     }

    refreshTotalScore();
    startTimer(1);
}

