#include "gameboard.h"
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

void Gameboard::setDefaultSettings()
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
    this->setMaximumWidth(200);
    this->setMaximumHeight(300);
}

void Gameboard::setSceneAndGroups()
{
    scene = new QGraphicsScene();
    this->setScene(scene);

    group_1 = new QGraphicsItemGroup();
    group_2 = new QGraphicsItemGroup();

    scene->addItem(group_1);
    scene->addItem(group_2);
}

void Gameboard::initTimer()
{
    timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);
    startTimer(750);
}

Gameboard::Gameboard(Ui::Tetris *ui, QWidget *parent)
    : QGraphicsView(parent)
{
    this->ui = ui;

    setDefaultSettings();
    setSceneAndGroups();
    setCurrentFigure();
    initTimer();
}

Gameboard::~Gameboard()
{

}

void Gameboard::slotAlarmTimer()
{
    if (!isGameOver) {
        drawCompleted = false;
        this->deleteItemsFromGroup(current);
        this->deleteItemsFromGroup(group_2);

        int width = this->width();
        int height = this->height();
        scene->setSceneRect(0,0,width,height);

        current->drawUnits(scene);
        this->drawUnits();
        drawCompleted = true;
        this->deleteOnelineUnits();
    }
}


void Gameboard::resizeEvent(QResizeEvent *event)
{
    timer->start(50);
    QGraphicsView::resizeEvent(event);
}



void Gameboard::deleteItemsFromGroup(QGraphicsItemGroup *group)
{

    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
       if(item->group() == group ) {
          delete item;
       }
    }
}

void Gameboard::setCurrentFigure()
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

void Gameboard::countOneLineUnits(std::map< QString, int> &coords)
{
    for (int i = 0; i < units.size(); i++) {
        QString position = QString::number(units[i]->getY());/**/
        if (coords.find(position) != coords.end()) {
            coords[position]++;
        } else {
            coords[position] = 1;
        }
    }
}

std::vector<int> Gameboard::deleteUnits(std::map< QString, int> &coords, std::map< QString, int>::iterator &it)
{
    std::vector<int> deletedCoords;
    for ( it = coords.begin(); it != coords.end(); it++) {
        int currentPos = (it->first).toInt();
        if (it->second ==20) {
            std::vector< Unit*>::iterator c = units.begin();
            while (c != units.end()) {

                if((*c)->getY() == currentPos) {
                    if (std::find(deletedCoords.begin(), deletedCoords.end(), currentPos) == deletedCoords.end()) {
                        deletedCoords.push_back(currentPos);
                    }

                    c = units.erase(c);
                } else {
                    c++;
                }
            }
            Score +=20;
            ui->score_count->setText(QString::number(Score));
        }
    }

    return deletedCoords;
}

void Gameboard::deleteOnelineUnits()
{
    std::map< QString, int> coords;

    countOneLineUnits(coords);

    std::map< QString, int>::iterator it;
    std::vector<int> deletedCoords;

    deletedCoords = deleteUnits(coords, it);
    moveAllUnitsDown(deletedCoords);
}

void Gameboard::moveAllUnitsDown(std::vector<int> deletedCoords)
{
    for(int i = 0; i < units.size(); i++) {
        for (int j = 0; j < deletedCoords.size(); j ++) {
            if(units[i]->getY() < deletedCoords[j]) {
                units[i]->setY(units[i]->getY() + 10);
            }
        }
    }
}

void Gameboard::drawUnits()
{
    for (int i = 0; i < units.size(); i++) {
        group_2->addToGroup(units[i]->draw(this->scene));
    }

}

bool Gameboard::isBarrierBottom()
{
    std::vector<Unit*> figureUnits = current->getUnits();
    for (int i = 0; i < figureUnits.size(); i++) {
        if (figureUnits[i]->getY() + 10 > 270) {
            return true;
        }
        for(int j = 0; j < units.size(); j++) {

            if ((figureUnits[i]->getY() + 10 == units[j]->getY() &&
                figureUnits[i]->getX() == units[j]->getX())
                    ) {
                return true;
            }
        }
    }
    return false;
}

bool Gameboard::isBarrierLeft()
{
    std::vector<Unit*> figureUnits = current->getUnits();
    for (int i = 0; i < figureUnits.size(); i++) {
        if (figureUnits[i]->getX() - 10 < 0) {
            return true;
        }
        for(int j = 0; j < units.size(); j++) {

            if ((figureUnits[i]->getX() - 10 == units[j]->getX() &&
                figureUnits[i]->getY() == units[j]->getY())
                    ) {
                return true;
            }
        }
    }
    return false;
}

bool Gameboard::isBarrierRight()
{
    std::vector<Unit*> figureUnits = current->getUnits();
    for (int i = 0; i < figureUnits.size(); i++) {
        if (figureUnits[i]->getX() + 10 > 190) {
            return true;
        }
        for(int j = 0; j < units.size(); j++) {

            if ((figureUnits[i]->getX() + 10 == units[j]->getX() &&
                figureUnits[i]->getY() == units[j]->getY())
                    ) {
                return true;
            }
        }
    }
    return false;
}

void Gameboard::timerEvent(QTimerEvent*)
{
    if (drawCompleted) {
        bool isbottom = isBarrierBottom();
        if(isbottom) {
            setCurrentFigure();
        } else {
            current->shiftCoords(0,10);
        }
    }
}

Figure *Gameboard:: createRandomFigure()
{
    int posX = 50;
    int posY = 0;
    srand(time(NULL));
    int randNum = 1 + rand() % 4;
    Figure *f;
    QPixmap pic1;
    switch (randNum) {
        case 1:
            pic1 = QPixmap(":/figures/images/images/square.png");
            f = new Square(posX,posY);
        break;

        case 2:
            pic1 = QPixmap(":/figures/images/images/horse.png");
            f = new Horse(posX,posY);
        break;

        case 3:
            pic1 = QPixmap(":/figures/images/images/straight.png");
            f = new Straight(posX,posY);
        break;

        case 4:
            pic1 = QPixmap(":/figures/images/images/lightning.png");
            f = new Lightning(posX,posY);
        break;
    }

    ui->next_figure->setPixmap(pic1);
    return f;
}

void Gameboard::resetGameState()
{
    setCurrentFigure();
    units.clear();
    Score = 0;
    ui->lable_score->setText("Score");

}
