#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    setMinimumSize(1,1);
    setMaximumSize(width,height);


    auto childs = ui->centralwidget->children();
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

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(){
    s.resize(width(),height());
    s.move(x(),y());

    s.show();
    this->close();

}


void MainWindow::mousePressEvent(QMouseEvent *event){
    std::cout << "mousePressEvent" << std::endl;

}



void MainWindow:: mouseReleaseEvent(QMouseEvent *event){
    std::cout << "mouseReleaseEvent" << std::endl;

}


void MainWindow::resizeEvent(QResizeEvent* event){

    if (timerId){
        killTimer(timerId);
        timerId = 0;
    }
    timerId = startTimer(200);


    QMainWindow::resizeEvent(event);
}

void MainWindow::timerEvent(QTimerEvent *te){
    auto childs = ui->centralwidget->children();
    for(auto it : childs){
        maximizeFontSize(it);
    }

    killTimer(te->timerId());
    timerId = 0;
}

void MainWindow::maximizeFontSize(QObject* object){
    if(dynamic_cast<QPushButton*>(object)){
        maximizeFontSizeTemplate((QPushButton*)object);
    }else if(dynamic_cast<QLabel*>(object)){
        maximizeFontSizeTemplate((QLabel*)object);
    }
}

template <class T>
void MainWindow::maximizeFontSizeTemplate(T* it){

    QString string = it->text();
    QFont f("Arial",1);
    it->setFont(f);
    QFontMetrics fm(f);
    int width = fm.horizontalAdvance(string);   //Getting the width of the string
    int height = fm.height();
    int size = 1;
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
        height = fm.height();
        width = fm.horizontalAdvance(string);      //Get the new width

        increment = increment/2;
    }
    size -= 3;
    if(size <= 0){
        size = 1;
    }
    f.setPointSize(size);
    it->setFont(f);
}





