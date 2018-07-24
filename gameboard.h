#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include "objects/figure.h"
#include "ui_tetris.h"
#include "objects/unit.h"
#include <vector>
// Расширяем класс QGraphicsView
class Gameboard : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Gameboard(Ui::Tetris *ui, QWidget *parent = 0);
    Figure               *current = NULL;

    void setCurrentFigure();
    bool isBarrierBottom();
    bool isBarrierLeft();
    bool isBarrierRight();
    ~Gameboard();

protected:
    virtual void timerEvent(QTimerEvent*);

signals:

private slots:
    void slotAlarmTimer();

private:
    QGraphicsScene      *scene;
    QGraphicsItemGroup  *group_1;
    QGraphicsItemGroup  *group_2;
    QTimer              *timer;
    int repaintCount = 0;
    int Score = 0;
    Ui::Tetris *ui;
    std::vector<Unit*> units;
    bool drawCompleted = false;
private:
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
    void setDefaultSettings();
    void setSceneAndGroups();
    void initTimer();
    void deleteOnelineUnits();
    void drawUnits();
    void createRandomFigure();
    void countOneLineUnits(std::map< QString, int> &coords);
    std::vector<int> deleteUnits(std::map< QString, int> &coords, std::map< QString, int>::iterator &it);
    void moveAllUnitsDown(std::vector<int> deletedCoords);
};

#endif // GAMEBOARD_H
