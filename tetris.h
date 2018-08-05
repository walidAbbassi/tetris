#ifndef TETRIS_H
#define TETRIS_H

#include <QMainWindow>
#include <QPainter>
#include <gameboard.h>
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

    bool makeWay(QString key, Figure *current);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Tetris *ui;
    Gameboard   *gameboard;
    Game *game;
private slots:

    void on_pushButton_start_clicked();
};
#endif // TETRIS_H
