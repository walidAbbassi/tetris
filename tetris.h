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

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Tetris *ui;
    Gameboard   *gameboard;     // Наш кастомный виджет
private slots:
   /* void on_radioButton_red_clicked();

    void on_radioButton_green_clicked();

    void on_radioButton_blue_clicked();*/
    void on_pushButton_clicked();
};

#endif // TETRIS_H
