#include "figure.h"
#include <QString>
#include <QDebug>
#include <vector>

Figure::Figure(int x, int y, int ey, int erx, int elx):
    x(x),
    y(y),
    edgeDownY(ey),
    edgeLeftX(elx),
    edgeRightX(erx)
{

}

Figure::Figure(){}

void Figure::setUnitsCoords()
{
    for(int i = 0; i < units.size(); i++)
    {
        units[i]->setXY(
                    this->x + units[i]->getOffsetX(),
                    this->y + units[i]->getOffsetY()
                    );
    }
}

Figure::~Figure()
{
   setUnitsCoords();
}

void Figure::drawUnits(QGraphicsScene *scene)
{
    for (int i = 0; i < units.size(); i++) {
        QGraphicsRectItem* item = units[i]->draw(scene, x, y);
        this->addToGroup(item);
    }

}

void Figure::rotate(){}

void Figure::setX(int x)
{
    this->x = x;
}

void Figure:: setY(int y)
{
    this->y = y;
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

    this->setUnitsCoords();

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

std::vector<Unit*> Figure::getUnits()
{
    return this->units;
}
