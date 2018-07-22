#include "tetris.h"
#include "ui_tetris.h"
#include <QString>
Tetris::Tetris(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tetris)
{
    ui->setupUi(this);
    /* Инициализируем виджет с графикой */
    gameboard   = new Gameboard(ui);
    /* и добавляем его на слой */
    ui->gridLayout->addWidget(gameboard);
}

Tetris::~Tetris()
{
    delete ui;
}

/*void Tetris::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Создаём объект отрисовщика
    // Устанавливаем кисть абриса
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));


    if(ui->radioButton_red->isChecked()){
        // Если красный, то отрисовываем красный круг
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        painter.drawEllipse(100, 50, 150, 150);
    } else if(ui->radioButton_green->isChecked()){
        // Если зелёный, то отрисовываем зеленый круг
        painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
        painter.drawEllipse(100, 50, 150, 150);
    } else if(ui->radioButton_blue->isChecked()){
        // Если синий, то отрисовываем синий круг
        painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
        painter.drawEllipse(100, 50, 150, 150);
    } else {
        // Если ничего не выбрано, то отрисовываем белый круг
        painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        painter.drawEllipse(100, 50, 150, 150);
    }
}


void Tetris::on_radioButton_red_clicked()
{
    repaint();
}

void Tetris::on_radioButton_green_clicked()
{
    repaint();
}

void Tetris::on_radioButton_blue_clicked()
{
    repaint();
}*/


void Tetris::on_pushButton_clicked()
{

}

void Tetris::keyPressEvent(QKeyEvent *event)
{
    QString key= (QString)event->key();
    ui->score_count->setText(key);
    if(key == "W") {
        ui->statusBar->showMessage("Pressed W");
        gameboard->current->shiftCoords(0, -10);
    } else if(key == "S") {
        gameboard->current->shiftCoords(0, 10);
    } else if(key == "A") {
        gameboard->current->shiftCoords(-10, 0);
    } else if(key == "D") {
        ui->statusBar->showMessage("Pressed D");
        gameboard->current->shiftCoords(10, 0);
    }

}
