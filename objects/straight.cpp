#include "straight.h"
#include "unit.h"
#include "figure.h"

Straight::Straight(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 0));
    units.push_back(new Unit(10,0));
    units.push_back(new Unit(20,0));
    units.push_back(new Unit(30,0));
}
