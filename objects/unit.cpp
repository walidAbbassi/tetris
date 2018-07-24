#include "unit.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPen>

Unit::Unit(int offsetX, int offsetY, QBrush brush): offsetX(offsetX), offsetY(offsetY), brush(brush){}
Unit::~Unit(){}
QGraphicsRectItem *Unit::draw(QGraphicsScene *scene, int x, int y)
{
    if(this->x != NULL || this->y != NULL) {
        QGraphicsRectItem *item = scene->addRect(this->x,this->y,10,10);
        item->setBrush(brush);
        return item;
    } else {
        QGraphicsRectItem *item = scene->addRect(x+offsetX,y+offsetY,10,10);
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
