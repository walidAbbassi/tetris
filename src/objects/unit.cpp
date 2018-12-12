#include "unit.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPen>

Unit::Unit(int offsetX, int offsetY, QBrush brush): offsetX(offsetX), offsetY(offsetY), brush(brush){}
Unit::~Unit(){}
QGraphicsRectItem *Unit::draw(QGraphicsScene *scene, int x, int y)
{
    if(this->x != 0 || this->y != 0) {
        QGraphicsRectItem *item = scene->addRect(this->x,this->y,Unit::WIDTH,Unit::HEIGHT);
        item->setBrush(brush);
        return item;
    } else {
        QGraphicsRectItem *item = scene->addRect(x+offsetX,y+offsetY,Unit::WIDTH,Unit::HEIGHT);
        item->setBrush(brush);
        return item;
    }
}

void Unit::setXY(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Unit::setX(int x)
{
    this->x = x;
}

void Unit::setY(int y)
{
    this->y = y;
}


int Unit::getOffsetX()
{
    return this->offsetX;
}

int Unit::getOffsetY()
{
    return this->offsetY;
}

void Unit::setOffsetXY(int x, int y)
{
    this->offsetX = x;
    this->offsetY = y;
}

int Unit::getX()
{
    return this->x;
}

int Unit::getY()
{
    return this->y;
}
