#include "lightning.h"
#include "unit.h"
#include "figure.h"

Lightning::Lightning(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 0, Qt::blue));
    units.push_back(new Unit(10, 0, Qt::blue));
    units.push_back(new Unit(0, 10, Qt::blue));
    units.push_back(new Unit(-10, 10, Qt::blue));
}

void Lightning::rotate()
{
    if(rotatePosition == 3) {
        rotatePosition = 0;
    } else {
        rotatePosition++;
    }

    switch(rotatePosition) {
        case 0:
            if(y + 20 >= 190 || x + 20 >=270) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(10, 0);
            units[2]->setOffsetXY(0, 10);
            units[3]->setOffsetXY(-10, 10);
        break;
        case 1:
            if(x + 20 >=270 ||y + 20 >= 190) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, -10);
            units[2]->setOffsetXY(10, 0);
            units[3]->setOffsetXY(10, 10);
            break;
    case 2:
        if(x - 20 < 0 || y+20 > 190) {
            break;
        }
        units[0]->setOffsetXY(0, 0);
        units[1]->setOffsetXY(0, -10);
        units[2]->setOffsetXY(-10, 0);
        units[3]->setOffsetXY(-10, 10);
        break;
    case 3:
        if(x - 20 <0 || x + 20 >=190 || y + 20 >=270) {
            break;
        }
        units[0]->setOffsetXY(0, 0);
        units[1]->setOffsetXY(-10, 0);
        units[2]->setOffsetXY(0, 10);
        units[3]->setOffsetXY(10, 10);
        break;
    }
}
