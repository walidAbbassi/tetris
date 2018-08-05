#ifndef TETRIS_H
#define TETRIS_H

#include <QMainWindow>
#include <QPainter>
#include <gamelogic.h>
#include <QKeyEvent>
#include "game.h"
namespace Ui {
class Tetris;
}

class Tetris : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tetris(Game *game, QWidget *parent = 0);
    ~Tetris();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Game *game;
    Ui::Tetris *ui;
    GameLogic   *gameLogic;

private slots:

    void on_pushButton_start_clicked();
};
#endif // TETRIS_H
