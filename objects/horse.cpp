#include "horse.h"
#include "unit.h"
#include "figure.h"

Horse::Horse(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 0, Qt::red));
    units.push_back(new Unit(10,0, Qt::red));
    units.push_back(new Unit(0, 10, Qt::red));
    units.push_back(new Unit(0, 20, Qt::red));
}
