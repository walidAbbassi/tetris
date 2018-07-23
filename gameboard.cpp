
#include "gameboard.h"
#include "objects/horse.h"
#include "objects/square.h"
#include <QString>
#include "ui_tetris.h"
#include "objects/unit.h"
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

    this->deleteItemsFromGroup(current);
    this->deleteItemsFromGroup(group_2);


    int width = this->width();
    int height = this->height();


    scene->setSceneRect(0,0,width,height);

    repaintCount++;
    ui->statusBar->showMessage(QString::number(repaintCount));

    ui->lable_score->setText(current->getCoords());
    current->drawUnits(scene);
    this->drawUnits();
    this->deleteOnelineUnits();
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
       // ui->label_debug->setText(QString::number(units.size()));
        delete current;
    }

    current = new Square(10,10);
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

void Gameboard::deleteUnits(std::map< QString, int> &coords, std::map< QString, int>::iterator &it)
{
    for ( it = coords.begin(); it != coords.end(); it++) {
        int currentPos = (it->first).toInt();
        if (it->second ==20) {
            std::vector< Unit*>::iterator c = units.begin();
            while (c != units.end()) {

                if((*c)->getY() == currentPos) {
                    c = units.erase(c);
                } else {
                    c++;
                }
            }
        }
    }
}

void Gameboard::deleteOnelineUnits()
{
    std::map< QString, int> coords;

    countOneLineUnits(coords);

    std::map< QString, int>::iterator it;

    deleteUnits(coords, it);

}

void Gameboard::drawUnits()
{
    for (int i = 0; i < units.size(); i++) {
        group_2->addToGroup(units[i]->draw(this->scene));
    }

}
