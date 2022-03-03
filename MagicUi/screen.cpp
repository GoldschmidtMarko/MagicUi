#include "screen.h"
#include "ui_screen.h"

Screen::Screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screen)
{
    ui->setupUi(this);


    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    setMinimumSize(1,1);
    setMaximumSize(width,height);


    auto childs = children();
    for(auto it : childs){
        if(dynamic_cast<QPushButton*>(it)){
            QPushButton* object = (QPushButton*)(it);
            object->setMinimumSize(1, 1);
        }else if(dynamic_cast<QLabel*>(it)){
            QLabel* object = (QLabel*)(it);
            object->setMinimumSize(1, 1);
        }
    }
}

Screen::~Screen()
{
    delete ui;
}

void Screen::resizeEvent(QResizeEvent* event){

    if (timerId2){
        killTimer(timerId2);
        timerId2 = 0;
    }
    timerId2 = startTimer(200);
}

void Screen::timerEvent(QTimerEvent *te){
    auto childs = children();
    for(auto it : childs){
        maximizeFontSize(it);
    }
    killTimer(te->timerId());
    timerId2 = 0;
}

void Screen::refreshUi(){
    for(auto it : vecPlayers){
        refreshUiPlayer(it);
    }
    timerId2 = startTimer(200);
}

void Screen::refreshUiPlayer(Player* p){
    std::string layoutPlayer = "layout" + p->name;
    QVBoxLayout* layout = this->findChild<QVBoxLayout*>(QString::fromStdString(layoutPlayer));
    if(layout != nullptr){
        QLayoutItem* item;
        while( (item = layout->takeAt(0)) != nullptr ){
            delete item->widget();
            delete item;
        }
        delete layout;
    }
    QHBoxLayout* layoutPlayers = this->findChild<QHBoxLayout*>(QString::fromStdString("layoutPlayers"));

    layout = new QVBoxLayout();
    layout->setObjectName(QString::fromStdString(layoutPlayer));

    layoutPlayers->addLayout(layout);
    QPushButton* playerName = new QPushButton(this);
    playerName->setObjectName(QString::fromStdString("button_" + p->name));
    playerName->setStyleSheet(QString::fromStdString(p->getBackgroundColor()));

    connect(playerName, &QPushButton::clicked, [=]() {
        int index = -1;
        for(int i = 0; i < (int)vecPlayers.size();++i){
            if(("button_" + vecPlayers.at(i)->name) == playerName->objectName().toStdString()){
                index = i;
                break;
            }
        }
        if(index < 0){
            std::cout << "Error, button did not find index from name" << std::endl;
            return;
        }

        for(int i = 0; i < (int)buttonsPressed.size();++i){
            if(buttonsPressed.at(i) == index){
                buttonsPressed.erase(buttonsPressed.begin() + i);
                playerName->setStyleSheet(QString::fromStdString(vecPlayers.at(index)->getBackgroundColor()));
                return;
            }
        }
        buttonsPressed.push_back(index);
        playerName->setStyleSheet("background-color: rgb(173,216,230);");
   });

    playerName->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    playerName->setText(QString::fromStdString(p->name));
    layout->addWidget(playerName);

    QLabel* playerHp = new QLabel(this);
    playerHp->setAlignment(Qt::AlignCenter);
    playerHp->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    playerHp->setText(QString::fromStdString("HP: " + std::to_string(p->hp)));
    playerHp->setStyleSheet(QString::fromStdString(p->getBackgroundColor()));
    layout->addWidget(playerHp);

    for(auto it : p->vecPlayerCommander){
        QLabel* playerCommanderDamage = new QLabel(this);
        playerCommanderDamage->setAlignment(Qt::AlignCenter);
        playerCommanderDamage->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        playerCommanderDamage->setText(QString::fromStdString("C_" + it->playerName + ": " + std::to_string(it->damage)));
        playerCommanderDamage->setStyleSheet(QString::fromStdString(p->getBackgroundColor()));
        layout->addWidget(playerCommanderDamage);
    }
    if(p->infectdamage > 0){
        QLabel* playerInfectDamage = new QLabel(this);
        playerInfectDamage->setAlignment(Qt::AlignCenter);
        playerInfectDamage->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        playerInfectDamage->setText(QString::fromStdString("Infect: " + std::to_string(p->infectdamage)));
        playerInfectDamage->setStyleSheet(QString::fromStdString(p->getBackgroundColor()));
        layout->addWidget(playerInfectDamage);
    }

}




void Screen::maximizeFontSize(QObject* object){
    if(dynamic_cast<QPushButton*>(object)){
        maximizeFontSizeTemplate((QPushButton*)object);
    }else if(dynamic_cast<QLabel*>(object)){
        maximizeFontSizeTemplate((QLabel*)object);
    }
}

template <class T>
void Screen::maximizeFontSizeTemplate(T* it){

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

void Screen::on_buttonEdit_clicked(){
    for(int i = 0;i < 5;++i){
        Player* p = new Player("Gero" + std::to_string(i));
        p->hp = 20;
        p->addCommanderDamage("Marko4",4);
        vecPlayers.push_back(p);
    }

    refreshUi();

}

