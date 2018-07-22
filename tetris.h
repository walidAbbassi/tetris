#ifndef TETRIS_H
#define TETRIS_H

#include <QMainWindow>
#include <QPainter>
#include <gameboard.h>
#include <QKeyEvent>
namespace Ui {
class Tetris;
}

class Tetris : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tetris(QWidget *parent = 0);
    ~Tetris();

    bool makeWay(QString key, Figure *current);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Tetris *ui;
    Gameboard   *gameboard;     // Наш кастомный виджет
    bool noway = false;
private slots:

};

#endif // TETRIS_H
