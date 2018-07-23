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
        current->shiftCoords(0, 10);
        if (!gameboard->isBarrierBottom()) {
            return false;
        }
        gameboard->setCurrentFigure();
    } else if(key == "A") {

        if (current->getX() - current->getEdgeLeftX() >= 0) {
            current->shiftCoords(-10, 0);
        }
    } else if(key == "D") {

        if (current->getX() + current->getEdgeRightX() <= 190) {
            current->shiftCoords(10, 0);
        }
    }
    return false;
}

void Tetris::keyPressEvent(QKeyEvent *event)
{
    QString key = (QString)event->key();
    ui->score_count->setText(key);
    makeWay(key, gameboard->current);
}

