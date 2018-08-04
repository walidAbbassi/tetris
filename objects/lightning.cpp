#include "lightning.h"
#include "unit.h"
#include "figure.h"
#include "gameboard.h"

Lightning::Lightning(int x, int y, int ey, int erx) : Figure(x, y, ey, erx)
{
    units.push_back(new Unit(0, 0, Qt::blue));
    units.push_back(new Unit(Unit::WIDTH, 0, Qt::blue));
    units.push_back(new Unit(0, Unit::HEIGHT, Qt::blue));
    units.push_back(new Unit(-Unit::WIDTH, Unit::HEIGHT, Qt::blue));
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
            if(y + 2 * Unit::HEIGHT >= Gameboard::HEIGHT - 2 * Unit::HEIGHT || x + 2 * Unit::WIDTH >=270) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(Unit::WIDTH, 0);
            units[2]->setOffsetXY(0, Unit::HEIGHT);
            units[3]->setOffsetXY(-Unit::WIDTH, Unit::WIDTH);
        break;
        case 1:
            if(x + 2 * Unit::WIDTH >=270 ||y + 2 * Unit::HEIGHT >= 190) {
                break;
            }
            units[0]->setOffsetXY(0, 0);
            units[1]->setOffsetXY(0, -Unit::HEIGHT);
            units[2]->setOffsetXY(Unit::WIDTH, 0);
            units[3]->setOffsetXY(Unit::WIDTH, Unit::HEIGHT);
            break;
    case 2:
        if(
                (x - 2 * Unit::WIDTH < 0) ||
                (y + 2 * Unit::HEIGHT > 190)
        ) {
            break;
        }
        units[0]->setOffsetXY(0, 0);
        units[1]->setOffsetXY(0, -Unit::HEIGHT);
        units[2]->setOffsetXY(-Unit::WIDTH, 0);
        units[3]->setOffsetXY(-Unit::WIDTH, Unit::HEIGHT);
        break;
    case 3:
        if(x - 2 * Unit::WIDTH <0 || x + 2 * Unit::WIDTH >=190 || y + 2 * Unit::HEIGHT >=270) {
            break;
        }
        units[0]->setOffsetXY(0, 0);
        units[1]->setOffsetXY(-Unit::WIDTH, 0);
        units[2]->setOffsetXY(0, Unit::HEIGHT);
        units[3]->setOffsetXY(Unit::WIDTH, Unit::HEIGHT);
        break;
    }
}
