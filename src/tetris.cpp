#include "tetris.h"
#include "ui_tetris.h"
#include <QString>
#include "objects/figure.h"
#include "objects/square.h"
#include "game.h"

Tetris::Tetris(Game *game, QWidget *parent) :
    QMainWindow(parent),
    game(game),
    ui(new Ui::Tetris)
{
    ui->setupUi(this);
    gameLogic   = new GameLogic(ui);
    ui->gridLayout->addWidget(gameLogic);
}

Tetris::~Tetris()
{
    delete ui;
    delete gameLogic;
}

void Tetris::keyPressEvent(QKeyEvent *event)
{
    QString key = (QString)event->key();
    gameLogic->moveCurrentFigure(key);
}

void Tetris::on_pushButton_start_clicked()
{
    gameLogic->isGameStarted = true;
    gameLogic->resetGameState();
}
