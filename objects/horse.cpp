#include "horse.h"
#include "unit.h"
#include <QString>
#include <QDebug>
Horse::Horse(int x, int y): x(x), y(y)
{
    units.push_back(new Unit(0, 0));
    units.push_back(new Unit(10,0));
    units.push_back(new Unit(0, 10));
    units.push_back(new Unit(0, 20));
}

void Horse::drawUnits(QGraphicsScene *scene)
{
    for (int i = 0; i < units.size(); i++) {
        this->addToGroup(units[i]->draw(scene, x, y));
    }

}

void Horse::setX(int x)
{
    this->x = x;

    qDebug() << "changex X" + this->getCoords();
}

void Horse:: setY(int y)
{
    this->y = y;

    qDebug() << "changex X" + this->getCoords();
}

QString Horse::getCoords()
{
    return QString::number(this->x) + "|" + QString::number(this->y);
}

void Horse::deleteHorseDraws()
{
    foreach( QGraphicsItem *item, this->childItems()) {
        //  delete item;
    }
}

void Horse::shiftCoords(int x, int y)
{
    this->x +=x;
    this->y +=y;

}
