#ifndef CIRCLE_H
#define CIRCLE_H


#include <cmath>
#include "graphikobjkt.h"

class Circle : public GraphikObjkt
{
private:
    double rad;

public:

    Circle(QPointF firstPunkt_, QPointF lastPunkt_, QColor color_, int painterSize):
        GraphikObjkt(firstPunkt_, lastPunkt_, color_, painterSize) {
        rad = std::hypot(firstPunkt.x() - lastPunkt.x(), firstPunkt.y() - lastPunkt.y());
    }

    void mallen(QPainter* objkt) override;


};

#endif // CIRCLE_H
