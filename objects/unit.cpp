#include "unit.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPen>

Unit::Unit(int offsetX, int offsetY, QPen pen): offsetX(offsetX), offsetY(offsetY), pen(pen){}
Unit::~Unit(){};
QGraphicsRectItem *Unit::draw(QGraphicsScene *scene, int x, int y)
{
    if(this->x != NULL || this->y != NULL) {
        return scene->addRect(this->x,this->y,10,10, pen);
    } else {
        return scene->addRect(x+offsetX,y+offsetY,10,10, pen);
    }

}

void Unit::setXY(int x, int y)
{
    this->x = x;
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

int Unit::getX()
{
    return this->x;
}

int Unit::getY()
{
    return this->y;
}
