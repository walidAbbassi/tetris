#include "gamelogic.h"
#include "objects/horse.h"
#include "objects/square.h"
#include "objects/straight.h"
#include "objects/lightning.h"
#include <QString>
#include "ui_tetris.h"
#include "objects/unit.h"
#include <time.h>
#include <map>
#include <vector>

GameLogic::GameLogic(Ui::Tetris *ui, QWidget *parent)
    : QGraphicsView(parent)
{
    this->ui = ui;

    setDefaultSettings();
    setSceneAndGroups();
    setCurrentFigure();
    initTimer();
}

void GameLogic::setDefaultSettings()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setMaximumWidth(GameLogic::BOARD_WIDTH);
    setMaximumHeight(GameLogic::BOARD_HEIGHT);
}

void GameLogic::setSceneAndGroups()
{
    scene = new QGraphicsScene();
    setScene(scene);

    unitsGroup = new QGraphicsItemGroup();
    scene->addItem(unitsGroup);
}

void GameLogic::initTimer()
{
    timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(startGameLoop()));
    timer->start(50);
    startTimer(750);
}

void GameLogic::startGameLoop()
{
    if (isGameStarted && !isGameOver) {
        drawCompleted = false;

        deleteItemsFromGroup(current);
        deleteItemsFromGroup(unitsGroup);

        int width = this->width();
        int height = this->height();
        scene->setSceneRect(0,0,width,height);

        current->drawUnits(scene);
        drawUnits();

        deleteOnelineUnits();
        drawCompleted = true;
    }
}


void GameLogic::resizeEvent(QResizeEvent *event)
{
    timer->start(50);
    QGraphicsView::resizeEvent(event);
}



void GameLogic::deleteItemsFromGroup(QGraphicsItemGroup *group)
{

    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
       if(item->group() == group ) {
          delete item;
       }
    }
}

void GameLogic::setCurrentFigure()
{
    if(current != NULL) {
        std::vector<Unit*> figureUnits = current->getUnits();
        units.insert(units.end(), figureUnits.begin(), figureUnits.end());

        delete current;
    }
    current = next;
    next = createRandomFigure();
    if(current == NULL){
        current = next;
        next = createRandomFigure();
    }
    current->setUnitsCoords();
    isGameOver = isBarrierBottom();

    if(isGameOver) {
        ui->lable_score->setText("Game over");
    }
    scene->addItem(current);

}

void GameLogic::countOneLineUnits(std::map< QString, int> &coords)
{
    for (unsigned int i = 0; i < units.size(); i++) {
        QString position = QString::number(units[i]->getY());
        if (coords.find(position) != coords.end()) {
            coords[position]++;
        } else {
            coords[position] = 1;
        }
    }
}

std::vector<int> GameLogic::deleteUnits(std::map< QString, int> &linesOfUnits, std::map< QString, int>::iterator &line)
{
    std::vector<int> deletedCoords;
    for ( line = linesOfUnits.begin(); line != linesOfUnits.end(); line++) {
        int currentPos = (line->first).toInt();
        int unitsInLine = line->second;
        if (unitsInLine == GameLogic::MAX_UNITS_PER_LINE) {
            std::vector< Unit*>::iterator unitsIterator = units.begin();
            while (unitsIterator != units.end()) {

                if((*unitsIterator)->getY() == currentPos) {
                    if (std::find(deletedCoords.begin(), deletedCoords.end(), currentPos) == deletedCoords.end()) {
                        deletedCoords.push_back(currentPos);
                    }

                    unitsIterator = units.erase(unitsIterator);
                } else {
                    unitsIterator++;
                }
            }
            score += GameLogic::MAX_UNITS_PER_LINE;
            ui->score_count->setText(QString::number(score));
        }
    }

    return deletedCoords;
}

void GameLogic::deleteOnelineUnits()
{
    std::map< QString, int> coords;

    countOneLineUnits(coords);

    std::map< QString, int>::iterator it;
    std::vector<int> deletedCoords;

    deletedCoords = deleteUnits(coords, it);
    moveAllUnitsDown(deletedCoords);
}

void GameLogic::moveAllUnitsDown(std::vector<int> deletedCoords)
{
    for(unsigned int i = 0; i < units.size(); i++) {
        for (unsigned int j = 0; j < deletedCoords.size(); j ++) {
            if(units[i]->getY() < deletedCoords[j]) {
                units[i]->setY(units[i]->getY() + Unit::HEIGHT);
            }
        }
    }
}

void GameLogic::drawUnits()
{
    for (unsigned int i = 0; i < units.size(); i++) {
        unitsGroup->addToGroup(units[i]->draw(this->scene));
    }

}

bool GameLogic::isBarrierBottom()
{
    std::vector<Unit*> figureUnits = current->getUnits();
    for (unsigned int i = 0; i < figureUnits.size(); i++) {
        if (figureUnits[i]->getY() + Unit::HEIGHT > 270) {
            return true;
        }
        for(unsigned int j = 0; j < units.size(); j++) {

            if ((figureUnits[i]->getY() + Unit::HEIGHT == units[j]->getY() &&
                figureUnits[i]->getX() == units[j]->getX())
                    ) {
                return true;
            }
        }
    }
    return false;
}

bool GameLogic::isBarrierLeft()
{
    std::vector<Unit*> figureUnits = current->getUnits();
    for (unsigned int i = 0; i < figureUnits.size(); i++) {
        if (figureUnits[i]->getX() - Unit::WIDTH < 0) {
            return true;
        }
        for(unsigned int j = 0; j < units.size(); j++) {

            if ((figureUnits[i]->getX() - Unit::WIDTH == units[j]->getX() &&
                figureUnits[i]->getY() == units[j]->getY())
                    ) {
                return true;
            }
        }
    }
    return false;
}

bool GameLogic::isBarrierRight()
{
    std::vector<Unit*> figureUnits = current->getUnits();
    for (unsigned int i = 0; i < figureUnits.size(); i++) {
        if (figureUnits[i]->getX() + Unit::WIDTH > 190) {
            return true;
        }
        for(unsigned int j = 0; j < units.size(); j++) {

            if ((figureUnits[i]->getX() + Unit::WIDTH == units[j]->getX() &&
                figureUnits[i]->getY() == units[j]->getY())
                    ) {
                return true;
            }
        }
    }
    return false;
}

void GameLogic::timerEvent(QTimerEvent*)
{
    if (drawCompleted) {
        bool isbottom = isBarrierBottom();
        if(isbottom) {
            setCurrentFigure();
        } else {
            current->shiftCoords(0,Unit::HEIGHT);
        }
    }
}

Figure *GameLogic:: createRandomFigure()
{
    int posX = 50;
    int posY = 0;
    srand(time(NULL));
    int randNum = 1 + rand() % 4;
    Figure *figure;
    QPixmap nextFigurePicture;
    switch (randNum) {
        case 1:
            nextFigurePicture = QPixmap(":/figures/images/images/square.png");
            figure = new Square(posX,posY);
        break;

        case 2:
            nextFigurePicture = QPixmap(":/figures/images/images/horse.png");
            figure = new Horse(posX,posY);
        break;

        case 3:
            nextFigurePicture = QPixmap(":/figures/images/images/straight.png");
            figure = new Straight(posX,posY);
        break;

        case 4:
            nextFigurePicture = QPixmap(":/figures/images/images/lightning.png");
            figure = new Lightning(posX,posY);
        break;
    }

    ui->next_figure->setPixmap(nextFigurePicture);
    return figure;
}

void GameLogic::resetGameState()
{
    setCurrentFigure();
    units.clear();
    
    deleteItemsFromGroup(current);
    deleteItemsFromGroup(unitsGroup);
    
    score = 0;
    ui->score_count->setText(QString::number(score));
    ui->lable_score->setText("Score");
}

bool GameLogic::moveCurrentFigure(QString key)
{
    if(key == "W") {
        current->shiftCoords(0,-Unit::HEIGHT);
    } else if(key == "S") {
        if (!isBarrierBottom()) {
            current->shiftCoords(0, Unit::HEIGHT);
            return false;
        }
        setCurrentFigure();
    } else if(key == "A") {
        if (!isBarrierLeft()) {
            current->shiftCoords(-Unit::WIDTH, 0);
        }
    } else if(key == "D") {
        if (!isBarrierRight()) {
            current->shiftCoords(Unit::WIDTH, 0);
        }
    } else if(key == "R") {
        drawCompleted = false;
        current->rotate();
    }
    return false;
}




