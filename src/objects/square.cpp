#include "square.h"
#include "unit.h"
#include "figure.h"

Square::Square(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 0, Qt::yellow));
    units.push_back(new Unit(Unit::WIDTH,0, Qt::yellow));
    units.push_back(new Unit(0, Unit::HEIGHT, Qt::yellow));
    units.push_back(new Unit(Unit::WIDTH, Unit::HEIGHT, Qt::yellow));
}
