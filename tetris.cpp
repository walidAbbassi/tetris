#include "tetris.h"
#include "ui_tetris.h"
#include <QString>
#include <objects/figure.h>
#include <objects/square.h>
Tetris::Tetris(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tetris)
{
    ui->setupUi(this);
    gameboard   = new Gameboard(ui);
    ui->gridLayout->addWidget(gameboard);
}

Tetris::~Tetris()
{
    delete ui;
}


bool Tetris::makeWay(QString key, Figure *current)
{
    if(key == "W") {
        ui->statusBar->showMessage("Pressed W");


    } else if(key == "S") {
        if (!gameboard->isBarrierBottom()) {

            current->shiftCoords(0, 10);
            return false;
        }

        gameboard->setCurrentFigure();
    } else if(key == "A") {

        if (!gameboard->isBarrierLeft()) {
            current->shiftCoords(-10, 0);
        }
    } else if(key == "D") {

        if (!gameboard->isBarrierRight()) {
            current->shiftCoords(10, 0);
        }
    }
    return false;
}

void Tetris::keyPressEvent(QKeyEvent *event)
{
    QString key = (QString)event->key();
    makeWay(key, gameboard->current);
}


void Tetris::on_pushButton_start_clicked()
{
    gameboard->resetGameState();
}
