#include "straight.h"
#include "unit.h"
#include "figure.h"

Straight::Straight(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 0, Qt::green));
    units.push_back(new Unit(Unit::WIDTH,0, Qt::green));
    units.push_back(new Unit(2 * Unit::WIDTH,0, Qt::green));
    units.push_back(new Unit(3 * Unit::WIDTH,0, Qt::green));
}

void Straight::rotate()
{
    if(rotatePosition == 1) {
        rotatePosition = 0;
    } else {
        rotatePosition++;
    }

    switch(rotatePosition) {
        case 0:
            if(y + 4 * Unit::HEIGHT >= 270) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, Unit::HEIGHT);
            units[2]->setOffsetXY(0, 2 * Unit::HEIGHT);
            units[3]->setOffsetXY(0, 3 * Unit::HEIGHT);
        break;
        case 1:
            if(x + 4 * Unit::WIDTH >=190) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(Unit::WIDTH, 0);
            units[2]->setOffsetXY(2 * Unit::WIDTH, 0);
            units[3]->setOffsetXY(3 * Unit::WIDTH, 0);
            break;
    }
}
