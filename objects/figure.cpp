#include "figure.h"
#include <QString>
#include <QDebug>

Figure::Figure(int x, int y, int ey, int erx, int elx):
    x(x),
    y(y),
    edgeDownY(ey),
    edgeLeftX(elx),
    edgeRightX(erx)
{

}

void Figure::drawUnits(QGraphicsScene *scene)
{
    for (int i = 0; i < units.size(); i++) {
        this->addToGroup(units[i]->draw(scene, x, y));
    }

}

void Figure::setX(int x)
{
    this->x = x;

    qDebug() << "changex X" + this->getCoords();
}

void Figure:: setY(int y)
{
    this->y = y;

    qDebug() << "changex X" + this->getCoords();
}

int Figure::getX()
{
    return x;
}

int Figure::getY()
{
    return y;
}

QString Figure::getCoords()
{
    return QString::number(this->x) + "|" + QString::number(this->y);
}

void Figure::shiftCoords(int x, int y)
{
    this->x +=x;
    this->y +=y;

}

int Figure::getEdgeY()
{
    return this->edgeDownY;
}
int Figure::getEdgeRightX()
{
    return this->edgeRightX;
}

int Figure::getEdgeLeftX()
{
    return this->edgeLeftX;
}
