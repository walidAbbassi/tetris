#include "tetris.h"
#include "ui_tetris.h"
#include <QString>
#include <objects/figure.h>
#include <objects/square.h>
#include "game.h"
Tetris::Tetris(Game *game, QWidget *parent) :
    game(game),
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
        current->shiftCoords(0,-Unit::HEIGHT);
    } else if(key == "S") {
        if (!gameboard->isBarrierBottom()) {
            current->shiftCoords(0, Unit::HEIGHT);
            return false;
        }
        gameboard->setCurrentFigure();
    } else if(key == "A") {
        if (!gameboard->isBarrierLeft()) {
            current->shiftCoords(-Unit::WIDTH, 0);
        }
    } else if(key == "D") {
        if (!gameboard->isBarrierRight()) {
            current->shiftCoords(Unit::WIDTH, 0);
        }
    } else if(key == "R") {
        gameboard->drawCompleted = false;
        gameboard->current->rotate();
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
