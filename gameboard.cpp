
#include "gameboard.h"
#include "objects/horse.h"
#include "objects/square.h"
#include <QString>
#include "ui_tetris.h"
#include "objects/unit.h"
#include <map>
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
   // current->deleteHorseDraws();

    int width = this->width();
    int height = this->height();


    scene->setSceneRect(0,0,width,height);

    repaintCount++;
    ui->statusBar->showMessage(QString::number(repaintCount));

    ui->lable_score->setText(current->getCoords());
    current->drawUnits(scene);
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
    current = new Square(10,10);
    scene->addItem(current);
    figures.push_back(current);
}

void Gameboard::deleteOnelineUnits()
{
  /*  std::map< QString, std::vector<Unit*> > coords;

    for (int i = 0; i < figures.size(); i++) {
        for(int j = 0; j < figures[i]->units; j++) {

        }
    }*/
}
