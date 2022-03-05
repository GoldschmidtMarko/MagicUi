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

    editwindow = new Editwindow();

    setupSettingWindow();

    setupEditWindow();

    QPushButton* yesPushButton = resetDialog->findChild<QPushButton*>(QString::fromStdString("pushButtonYes"));

    connect(yesPushButton, &QPushButton::clicked, [=]() {
        resetStats();
        resetDialog->close();
    });


    //QScreen *screen = QGuiApplication::primaryScreen();
    //QRect screenGeometry = screen->geometry();
    //int height = screenGeometry.height();
    //int width = screenGeometry.width();
    setMinimumSize(1,1);
    //setMaximumSize(width,height);


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

void Screen::setupEditWindow(){
    QRadioButton* radioBackground = editwindow->findChild<QRadioButton*>(QString::fromStdString("radioBackground"));
    radioBackground->setChecked(true);

    QPushButton* rerollButton = editwindow->findChild<QPushButton*>(QString::fromStdString("rerollButton"));
    connect(rerollButton, &QPushButton::clicked, [this]() {
        editwindow->generateColors();
    });

    QPushButton* applyButton = editwindow->findChild<QPushButton*>(QString::fromStdString("applyButton"));
    connect(applyButton, &QPushButton::clicked, [this]() {
        QLabel* displayColor = editwindow->findChild<QLabel*>(QString::fromStdString("displayColor"));
        std::string background =  displayColor->palette().button().color().name().toStdString();
        std::string font = displayColor->palette().text().color().name().toStdString();
        background.erase(0,1);
        font.erase(0,1);
        int r_b, g_b, b_b;
        int r_f, g_f, b_f;
        std::sscanf(background.c_str(), "%02x%02x%02x", &r_b, &g_b, &b_b);
        std::sscanf(font.c_str(), "%02x%02x%02x", &r_f, &g_f, &b_f);
        for(auto it : editwindow->vecPlayers){
            it->r_back = r_b;
            it->r_font = r_f;
            it->g_back = g_b;
            it->g_font = g_f;
            it->b_back = b_b;
            it->b_font = b_f;
        }
        editwindow->vecPlayers.clear();
        buttonsPressed.clear();
        refreshUi();
        editwindow->close();


    });

    QSlider* sliderR = editwindow->findChild<QSlider*>(QString::fromStdString("sliderR"));
    connect(sliderR, &QSlider::sliderMoved, [=]() {
        QLabel* displayColor = editwindow->findChild<QLabel*>(QString::fromStdString("displayColor"));
        std::string background =  "background-color: " + displayColor->palette().button().color().name().toStdString();
        std::string font = "color: " + displayColor->palette().text().color().name().toStdString();

        QSlider* sliderG = editwindow->findChild<QSlider*>(QString::fromStdString("sliderG"));
        QSlider* sliderB = editwindow->findChild<QSlider*>(QString::fromStdString("sliderB"));

        QRadioButton* radioBackground = editwindow->findChild<QRadioButton*>(QString::fromStdString("radioBackground"));
        if(radioBackground->isChecked()){
            background = "background-color: rgb(" + std::to_string(sliderR->sliderPosition()) + "," + std::to_string(sliderG->sliderPosition()) + "," + std::to_string(sliderB->sliderPosition())  + ");";
        }else{
            font = "color: rgb(" + std::to_string(sliderR->sliderPosition()) + "," + std::to_string(sliderG->sliderPosition()) + "," + std::to_string(sliderB->sliderPosition())  + ");";
        }
        displayColor->setStyleSheet(QString::fromStdString(background + ";" + font));
    });

    QSlider* sliderG = editwindow->findChild<QSlider*>(QString::fromStdString("sliderG"));
    connect(sliderG, &QSlider::sliderMoved, [=]() {
        QLabel* displayColor = editwindow->findChild<QLabel*>(QString::fromStdString("displayColor"));
        std::string background =  "background-color: " + displayColor->palette().button().color().name().toStdString();
        std::string font = "color: " + displayColor->palette().text().color().name().toStdString();

        QSlider* sliderR = editwindow->findChild<QSlider*>(QString::fromStdString("sliderR"));
        QSlider* sliderB = editwindow->findChild<QSlider*>(QString::fromStdString("sliderB"));

        QRadioButton* radioBackground = editwindow->findChild<QRadioButton*>(QString::fromStdString("radioBackground"));
        if(radioBackground->isChecked()){
            background = "background-color: rgb(" + std::to_string(sliderR->sliderPosition()) + "," + std::to_string(sliderG->sliderPosition()) + "," + std::to_string(sliderB->sliderPosition())  + ");";
        }else{
            font = "color: rgb(" + std::to_string(sliderR->sliderPosition()) + "," + std::to_string(sliderG->sliderPosition()) + "," + std::to_string(sliderB->sliderPosition())  + ");";
        }
        displayColor->setStyleSheet(QString::fromStdString(background + ";" + font));
    });

    QSlider* sliderB = editwindow->findChild<QSlider*>(QString::fromStdString("sliderB"));
    connect(sliderB, &QSlider::sliderMoved, [=]() {
        QLabel* displayColor = editwindow->findChild<QLabel*>(QString::fromStdString("displayColor"));
        std::string background =  "background-color: " + displayColor->palette().button().color().name().toStdString();
        std::string font = "color: " + displayColor->palette().text().color().name().toStdString();

        QSlider* sliderG = editwindow->findChild<QSlider*>(QString::fromStdString("sliderG"));
        QSlider* sliderR = editwindow->findChild<QSlider*>(QString::fromStdString("sliderR"));

        QRadioButton* radioBackground = editwindow->findChild<QRadioButton*>(QString::fromStdString("radioBackground"));
        if(radioBackground->isChecked()){
            background = "background-color: rgb(" + std::to_string(sliderR->sliderPosition()) + "," + std::to_string(sliderG->sliderPosition()) + "," + std::to_string(sliderB->sliderPosition())  + ");";
        }else{
            font = "color: rgb(" + std::to_string(sliderR->sliderPosition()) + "," + std::to_string(sliderG->sliderPosition()) + "," + std::to_string(sliderB->sliderPosition())  + ");";
        }
        displayColor->setStyleSheet(QString::fromStdString(background + ";" + font));
    });
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

    QPushButton* dicebutton = settingsWindow->findChild<QPushButton*>(QString::fromStdString("dicebutton"));
    connect(dicebutton, &QPushButton::clicked, [=]() {
        QLineEdit* lineDice = settingsWindow->findChild<QLineEdit*>(QString::fromStdString("lineDice"));
        int newValue = diceWindow->maxValue;
        if(lineDice->text().toInt() > 0){
            newValue = lineDice->text().toInt();
        }
        diceWindow->maxValue = newValue;
        dicebutton->setText(QString::fromStdString("Dice Value: " + std::to_string(diceWindow->maxValue)));
        lineDice->setText("");
    });


    QPushButton* initialHP = settingsWindow->findChild<QPushButton*>(QString::fromStdString("initialHP"));
    connect(initialHP, &QPushButton::clicked, [=]() {
        QLineEdit* lineHP = settingsWindow->findChild<QLineEdit*>(QString::fromStdString("lineHP"));
        int newValue = defaultSetting->initialHp;
        if(lineHP->text().toInt() > 0){
            newValue = lineHP->text().toInt();
        }
        defaultSetting->initialHp = newValue;
        initialHP->setText(QString::fromStdString("Initial HP: " + std::to_string(defaultSetting->initialHp)));
        lineHP->setText("");
    });

    QPushButton* addPlayer = settingsWindow->findChild<QPushButton*>(QString::fromStdString("addPlayer"));
    connect(addPlayer, &QPushButton::clicked, [this]() {
        QLineEdit* lineAdd = settingsWindow->findChild<QLineEdit*>(QString::fromStdString("lineAdd"));
        std::string newName = lineAdd->text().toStdString();
        if(newName.size() > 0 && newName != "Error"){
            for(auto it : vecPlayers){
                if(it->name == newName){
                    lineAdd->setText("Error");
                    return;
                }
            }
            Player* p = new Player(newName);
            vecPlayers.push_back(p);
            refreshPlayerCommander();
            refreshUi();
            lineAdd->setText("");
        }
    });

    QPushButton* removePlayer = settingsWindow->findChild<QPushButton*>(QString::fromStdString("removePlayer"));
    connect(removePlayer, &QPushButton::clicked, [this]() {
        QLineEdit* lineRemove = settingsWindow->findChild<QLineEdit*>(QString::fromStdString("lineRemove"));
        std::string deletingName = lineRemove->text().toStdString();
        if(deletingName.size() > 0){
            for(int i = 0; i < (int)vecPlayers.size();++i){
                if(vecPlayers.at(i)->name == deletingName){
                    delete(vecPlayers.at(i));
                    vecPlayers.erase(vecPlayers.begin() + i);

                    QVBoxLayout* layout = this->findChild<QVBoxLayout*>(QString::fromStdString("layout" + deletingName));
                    if(layout != nullptr){
                        QLayoutItem* item;
                        while( (item = layout->takeAt(0)) != nullptr ){
                            delete item->widget();
                            delete item;
                        }
                        delete layout;
                    }

                    for(int j = 0; j < (int)buttonsPressed.size();++j){
                        if(buttonsPressed.at(j) == i){
                            buttonsPressed.erase(buttonsPressed.begin() + j);
                        }
                    }

                    refreshPlayerCommander();
                    refreshUi();

                    lineRemove->setText("");

                    return;
                }
            }
            lineRemove->setText("Error");
        }
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
    for(auto it : buttonsPressed){
        if(vecPlayers.at(it)->name == p->name){
            playerName->setStyleSheet(COLOR_LIGHTBLUE);
            break;
        }
    }


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
        QLabel* titel = new QLabel(this);
        titel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        titel->setText(QString::fromStdString("CommanderDamage"));
        titel->setStyleSheet(QString::fromStdString(p->getBackgroundColor()));
        titel->setAlignment(Qt::AlignCenter);
        layout->addWidget(titel);

        for(auto it : p->vecPlayerCommander){
            QPushButton* playerCommanderDamage = new PushButtonCorner(this,p,ButtonType::commanderDamage,it->playerName);
            playerCommanderDamage->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            playerCommanderDamage->setText(QString::fromStdString(it->playerName + ": " + std::to_string(it->damage)));
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
    double factor = double(6)/8;

    editwindow->resize(width() * factor, height() * factor);
    editwindow->move(x() + (width() - editwindow->width())/2 ,y() + (height() - editwindow->height())/2 );
    editwindow->setMaximumSize(width(),height());
    editwindow->generateColors();
    for(auto it : buttonsPressed){
        editwindow->vecPlayers.push_back(vecPlayers.at(it));
    }

    editwindow->show();

}

void Screen::refreshPlayerCommander(){
    for(auto it : vecPlayers){
        for(auto it2 : vecPlayers){
            if(it->name != it2->name){
                bool contains = false;
                for(auto it3 : it2->vecPlayerCommander){
                    if(it3->playerName == it->name){
                        contains = true;
                        break;
                    }
                }
                if(!contains){
                    PlayerCommander* p = new PlayerCommander();
                    p->playerName = it->name;
                    it2->vecPlayerCommander.push_back(p);
                }
            }
        }
    }
    for(auto it : vecPlayers){
        for(int i = 0; i < (int)it->vecPlayerCommander.size();++i){
            bool valid = false;
            for(auto it3 : vecPlayers){
                if(it->vecPlayerCommander.at(i)->playerName == it3->name){
                    valid = true;
                }
            }
            if(valid == false) {
                delete(it->vecPlayerCommander.at(i));
                it->vecPlayerCommander.erase(it->vecPlayerCommander.begin() + i);
            }
        }
    }

}


void Screen::on_buttonDice_clicked(){
    double factor = double(4)/8;
    diceWindow->resize(width() * factor, height() * factor);
    diceWindow->move(x() + (width() - diceWindow->width())/2 ,y() + (height() - diceWindow->height())/2 );
    diceWindow->setMaximumSize(width(),height());
    diceWindow->show();

    if(buttonsPressed.size() == 0){
        diceWindow->dice(vecPlayers);
    }else{
        std::vector<Player*> vec;
        for(auto it : buttonsPressed){
            vec.push_back(vecPlayers.at(it));
        }
        diceWindow->dice(vec);
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
    double factor = double(4)/8;


    QPushButton* dicebutton = settingsWindow->findChild<QPushButton*>(QString::fromStdString("dicebutton"));
    dicebutton->setText(QString::fromStdString("Dice Value: " + std::to_string(diceWindow->maxValue)));

    QPushButton* initialHP = settingsWindow->findChild<QPushButton*>(QString::fromStdString("initialHP"));
    initialHP->setText(QString::fromStdString("Initial HP: " + std::to_string(defaultSetting->initialHp)));


    settingsWindow->resize(width() * factor, height() * factor);
    settingsWindow->move(x() + (width() - settingsWindow->width())/2 ,y() + (height() - settingsWindow->height())/2 );
    settingsWindow->setMaximumSize(width(),height());
    settingsWindow->show();
    settingsWindow->refreshUi();
}

