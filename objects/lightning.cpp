#include "lightning.h"
#include "unit.h"
#include "figure.h"

Lightning::Lightning(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 10, QPen(Qt::blue)));
    units.push_back(new Unit(10, 10, QPen(Qt::blue)));
    units.push_back(new Unit(10, 0, QPen(Qt::blue)));
    units.push_back(new Unit(20, 0, QPen(Qt::blue)));
}
