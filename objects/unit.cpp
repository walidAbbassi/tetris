#include "unit.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPen>

Unit::Unit(int offsetX, int offsetY): offsetX(offsetX), offsetY(offsetY){}

QGraphicsRectItem *Unit::draw(QGraphicsScene *scene, int x, int y)
{
    QPen penRed(Qt::red);
    return scene->addRect(x+offsetX,y+offsetY,10,10, penRed);
}
