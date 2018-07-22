#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include "objects/figure.h"
#include "ui_tetris.h"
#include <vector>
// Расширяем класс QGraphicsView
class Gameboard : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Gameboard(Ui::Tetris *ui, QWidget *parent = 0);
    Figure               *current;

    void setCurrentFigure();
    ~Gameboard();

signals:

private slots:
    void slotAlarmTimer();

private:
    QGraphicsScene      *scene;
    QGraphicsItemGroup  *group_1;
    QGraphicsItemGroup  *group_2;
    QTimer              *timer;
    int repaintCount = 0;
    Ui::Tetris *ui;
    std::vector<Figure*> figures;

private:
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
    void setDefaultSettings();
    void setSceneAndGroups();
    void initTimer();
    void deleteOnelineUnits();

};

#endif // GAMEBOARD_H
