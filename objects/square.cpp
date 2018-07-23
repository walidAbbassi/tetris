#include "square.h"
#include "unit.h"
#include "figure.h"

Square::Square(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 0, QPen(Qt::black)));
    units.push_back(new Unit(10,0, QPen(Qt::black)));
    units.push_back(new Unit(0, 10, QPen(Qt::black)));
    units.push_back(new Unit(10, 10, QPen(Qt::black)));
}
