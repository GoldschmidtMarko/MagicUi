#include "screen.h"
#include "ui_screen.h"

Screen::Screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screen)
{
    ui->setupUi(this);

    resetDialog = new ResetDialog();

    diceWindow = new DiceWindow();

    defaultSetting = new DefaultSetting();

    settingsWindow = new Settingswindow();

    setupSettingWindow();

    QPushButton* yesPushButton = resetDialog->findChild<QPushButton*>(QString::fromStdString("pushButtonYes"));

    connect(yesPushButton, &QPushButton::clicked, [=]() {
        resetStats();
        resetDialog->close();
    });


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

Screen::~Screen(){
    delete ui;
    delete diceWindow;
    delete resetDialog;
    delete defaultSetting;
    delete settingsWindow;

    for(auto it : vecPlayers){
        delete(it);
    }
}

void Screen::setupSettingWindow(){
    QPushButton* commanderDamage = settingsWindow->findChild<QPushButton*>(QString::fromStdString("commanderDamage"));

    connect(commanderDamage, &QPushButton::clicked, [commanderDamage,this]() {
        if(defaultSetting->commanderDamage == false){
            defaultSetting->commanderDamage = true;
            commanderDamage->setStyleSheet(COLOR_LIGHTBLUE);
        }else{
            defaultSetting->commanderDamage = false;
            commanderDamage->setStyleSheet(COLOR_WHITE);

        }
        refreshUi();
    });

    QPushButton* infectDamage = settingsWindow->findChild<QPushButton*>(QString::fromStdString("infectDamage"));
    connect(infectDamage, &QPushButton::clicked, [infectDamage,this]() {
        if(defaultSetting->infectDamage == false){
            defaultSetting->infectDamage = true;
            infectDamage->setStyleSheet(COLOR_LIGHTBLUE);
        }else{
            defaultSetting->infectDamage = false;
            infectDamage->setStyleSheet(COLOR_WHITE);

        }
        refreshUi();
    });

    QPushButton* diceValue = settingsWindow->findChild<QPushButton*>(QString::fromStdString("diceValue"));
    connect(infectDamage, &QPushButton::clicked, [=]() {

    });
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
    timerId2 = startTimer(1);
}

void Screen::resetStats(){
    for(auto it : vecPlayers){
        it->hp = defaultSetting->initialHp;
        for(auto it2 : it->vecPlayerCommander){
            it2->damage = 0;
        }
        it->infectdamage = 0;
    }
    refreshUi();
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
            std::cout << "Error, button 'playerName' did not find index from name" << std::endl;
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
        playerName->setStyleSheet(COLOR_LIGHTBLUE);
   });

    playerName->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    playerName->setText(QString::fromStdString(p->name));
    layout->addWidget(playerName);

    QPushButton* playerHp = new PushButtonCorner(this,p,ButtonType::hp,"");
    playerHp->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    playerHp->setText(QString::fromStdString("HP: " + std::to_string(p->hp)));
    playerHp->setStyleSheet(QString::fromStdString(p->getBackgroundColor()));
    playerHp->setObjectName(QString::fromStdString("buttonHP_" + p->name));

    layout->addWidget(playerHp);


    if(defaultSetting->commanderDamage == true){
        for(auto it : p->vecPlayerCommander){
            QPushButton* playerCommanderDamage = new PushButtonCorner(this,p,ButtonType::commanderDamage,it->playerName);
            playerCommanderDamage->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            playerCommanderDamage->setText(QString::fromStdString("C_" + it->playerName + ": " + std::to_string(it->damage)));
            playerCommanderDamage->setStyleSheet(QString::fromStdString(p->getBackgroundColor()));
            layout->addWidget(playerCommanderDamage);
        }
    }

    if(defaultSetting->infectDamage == true){
        QPushButton* playerInfectDamage = new PushButtonCorner(this,p,ButtonType::infect,"");
        playerInfectDamage->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        playerInfectDamage->setText(QString::fromStdString("Infect: " + std::to_string(p->infectdamage)));
        playerInfectDamage->setStyleSheet(QString::fromStdString(p->getBackgroundColor()));
        layout->addWidget(playerInfectDamage);
    }


}






void Screen::maximizeFontSize(QObject* object){
    if(dynamic_cast<QPushButton*>(object)){
        ((QPushButton*)(object))->setMinimumSize(1,1);
        maximizeFontSizeTemplate((QPushButton*)object);
    }else if(dynamic_cast<QLabel*>(object)){
        ((QLabel*)(object))->setMinimumSize(1,1);
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

Player* Screen::getPlayerByName(std::string name){
    for(auto it : vecPlayers){
        if(it->name == name){
            return it;
        }
    }
    return nullptr;

}

void Screen::on_buttonEdit_clicked(){
    for(int i = 0;i < 5;++i){
        Player* p = new Player("Gero" + std::to_string(i));
        p->hp = 20;
        p->infectdamage = 2;
        vecPlayers.push_back(p);
    }
    for(int i = 0;i < 4;++i){
        vecPlayers.at(i)->addCommanderDamage("Gero" + std::to_string(i+1),3);
    }



    refreshUi();

}


void Screen::on_buttonDice_clicked(){
    double factor = double(6)/8;
    diceWindow->resize(width() * factor, height() * factor);
    diceWindow->move(x() + (width() - diceWindow->width())/2 ,y() + (height() - diceWindow->height())/2 );
    diceWindow->setMaximumSize(width(),height());
    diceWindow->show();

    if(buttonsPressed.size() == 0){
        diceWindow->dice(vecPlayers.size());
    }else{
        diceWindow->dice(buttonsPressed.size());
    }
}


void Screen::on_buttonReset_clicked(){
    double factor = double(2)/8;

    resetDialog->resize(width() * factor, height() * factor);
    resetDialog->move(x() + (width() - resetDialog->width())/2 ,y() + (height() - resetDialog->height())/2 );
    resetDialog->setMaximumSize(width(),height());
    resetDialog->show();
    resetDialog->refreshUi();
}


void Screen::on_buttonSetting_clicked(){
    double factor = double(7)/8;
    settingsWindow->resize(width() * factor, height() * factor);
    settingsWindow->move(x() + (width() - settingsWindow->width())/2 ,y() + (height() - settingsWindow->height())/2 );
    settingsWindow->setMaximumSize(width(),height());
    settingsWindow->show();
    settingsWindow->refreshUi();
}

