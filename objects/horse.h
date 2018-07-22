#ifndef HORSE_H
#define HORSE_H
#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <vector>
#include "unit.h"
class Horse: public QGraphicsItemGroup
{
public:
    Horse(int x, int y);
    void drawUnits(QGraphicsScene *scene);
private:
    int x;
    int y;
    std::vector<Unit*> units;
};

#endif // HORSE_H
