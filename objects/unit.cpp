#include "unit.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPen>

Unit::Unit(int x, int y): x(x), y(y){}

QGraphicsRectItem *Unit::draw(QGraphicsScene *scene)
{
    QPen penRed(Qt::red);
    return scene->addRect(x,y,10,10, penRed);
}
