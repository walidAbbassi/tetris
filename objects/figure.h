#ifndef FIGURE_H
#define FIGURE_H
#include <QGraphicsItemGroup>
#include <vector>
#include "unit.h"
class Figure: public QGraphicsItemGroup
{
public:
    Figure(int x, int y, int edgeDownY, int edgeRightX, int edgeLeftX = 10);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

    int getEdgeY();
    int getEdgeRightX();
    int getEdgeLeftX();

    QString getCoords();
    void drawUnits(QGraphicsScene *scene);
    void shiftCoords(int x = 0, int y = 0);
    int getEdge();
protected:
    int x;
    int y;
    std::vector<Unit*> units;
    int edgeDownY;
    int edgeLeftX;
    int edgeRightX;
};

#endif // FIGURE_H
