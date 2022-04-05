#include "scoreaddresult.h"
#include "ui_scoreaddresult.h"

ScoreAddResult::ScoreAddResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScoreAddResult)
{
    ui->setupUi(this);
}

ScoreAddResult::~ScoreAddResult()
{
    delete ui;
}
