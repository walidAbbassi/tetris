#ifndef UNIT_H
#define UNIT_H
#include <QGraphicsScene>
class Unit
{
public:
    Unit(int offsetX, int offsetY);
    ~Unit();
    void setXY(int x, int y);
    int getOffsetX();
    int getOffsetY();
    int getX();
    int getY();
    QGraphicsRectItem *draw(QGraphicsScene *scene, int x = 0, int y = 0);
private:
    int offsetX;
    int offsetY;
    int x = NULL;
    int y = NULL;
    int width = 10;
    int height = 10;
};

#endif // UNIT_H
