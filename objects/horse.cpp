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

void Horse::rotate()
{
    if(rotatePosition == 3) {
        rotatePosition = 0;
    } else {
        rotatePosition++;
    }

    int fx = this->x;
    int fy = this->y;

    switch(rotatePosition) {
        case 0:
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(10, 0);
            units[2]->setOffsetXY(0, 10);
            units[3]->setOffsetXY(0, 20);
        break;
        case 1:
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(10, 0);
            units[2]->setOffsetXY(20, 0);
            units[3]->setOffsetXY(20, 10);
            break;
        case 2:
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, 10);
            units[2]->setOffsetXY(0, 20);
            units[3]->setOffsetXY(-10, 20);
        break;
        case 3:
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(-10, 0);
            units[2]->setOffsetXY(-20, 0);
            units[3]->setOffsetXY(-20, -10);
        break;
    }
}
