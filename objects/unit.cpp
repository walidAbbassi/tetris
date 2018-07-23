#include "unit.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPen>

Unit::Unit(int offsetX, int offsetY): offsetX(offsetX), offsetY(offsetY){}
Unit::~Unit(){};
QGraphicsRectItem *Unit::draw(QGraphicsScene *scene, int x, int y)
{
    QPen penRed(Qt::red);
    if(this->x != NULL || this->y != NULL) {
        return scene->addRect(this->x,this->y,10,10, penRed);
    } else {
        return scene->addRect(x+offsetX,y+offsetY,10,10, penRed);
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
