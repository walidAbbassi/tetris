#ifndef FIGURE_H
#define FIGURE_H
#include <QGraphicsItemGroup>
#include <vector>
#include "unit.h"
class Figure: public QGraphicsItemGroup
{
public:
    Figure(int x, int y, int edgeDownY, int edgeRightX, int edgeLeftX = 10);
    ~Figure();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

    int getEdgeY();
    int getEdgeRightX();
    int getEdgeLeftX();
    std::vector<Unit*> getUnits();

    QString getCoords();
    void drawUnits(QGraphicsScene *scene);
    void shiftCoords(int x = 0, int y = 0);
    int getEdge();

    void setUnitsCoords();
protected:
    int x;
    int y;
    std::vector<Unit*> units;
    int edgeDownY;
    int edgeLeftX;
    int edgeRightX;
private:
};

#endif // FIGURE_H
