#ifndef HORSE_H
#define HORSE_H
#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <vector>
#include <QString>
#include "unit.h"
class Horse: public QGraphicsItemGroup
{
public:
    Horse(int x, int y);
    void setX(int x);
    void setY(int y);
    QString getCoords();
    void drawUnits(QGraphicsScene *scene);
    void deleteHorseDraws();
    void shiftCoords(int x = 0, int y = 0);
private:
    int x;
    int y;
    std::vector<Unit*> units;
};

#endif // HORSE_H
