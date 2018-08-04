#include "straight.h"
#include "unit.h"
#include "figure.h"

Straight::Straight(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 0, Qt::green));
    units.push_back(new Unit(10,0, Qt::green));
    units.push_back(new Unit(20,0, Qt::green));
    units.push_back(new Unit(30,0, Qt::green));
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
            if(y + 40 >= 270) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, 10);
            units[2]->setOffsetXY(0, 20);
            units[3]->setOffsetXY(0, 30);
        break;
        case 1:
            if(x + 40 >=190) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(10, 0);
            units[2]->setOffsetXY(20, 0);
            units[3]->setOffsetXY(30, 0);
            break;
    }
}
