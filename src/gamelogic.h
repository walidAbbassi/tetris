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

class GameLogic : public QGraphicsView
{
    Q_OBJECT
public:
    Figure *current = NULL;
    const int MAX_UNITS_PER_LINE = 20;
    const int static BOARD_WIDTH = 200;
    const int static BOARD_HEIGHT = 300;
    bool drawCompleted = false;
    bool isGameStarted = false;

    explicit GameLogic(Ui::Tetris *ui, QWidget *parent = 0);
    void setCurrentFigure();
    bool isBarrierBottom();
    bool isBarrierLeft();
    bool isBarrierRight();
    void resetGameState();
    bool moveCurrentFigure(QString key);
protected:
    virtual void timerEvent(QTimerEvent*);

signals:

private slots:
    void startGameLoop();

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *unitsGroup;
    QTimer *timer;
    Ui::Tetris  *ui;
    Figure *next = NULL;
    std::vector<Unit*> units;
    int repaintCount = 0;
    int score = 0;
    bool isGameOver = false;
private:
    void resizeEvent(QResizeEvent *event);
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
    void setDefaultSettings();
    void setSceneAndGroups();
    void initTimer();
    void deleteOnelineUnits();
    void drawUnits();
    void countOneLineUnits(std::map< QString, int> &coords);
    void moveAllUnitsDown(std::vector<int> deletedCoords);
    Figure *createRandomFigure();
    std::vector<int> deleteUnits(std::map< QString, int> &coords, std::map< QString, int>::iterator &it);
};

#endif // GAMEBOARD_H
