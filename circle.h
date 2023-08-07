#ifndef CIRCLE_H
#define CIRCLE_H

#include "graphikobjekt.h"
#include <cmath>

class Circle : public GraphObjkt
{
private:
    double rad;

public:

    Circle(QPointF firstPunkt_, QPointF lastPunkt_, QColor color_):
        GraphObjkt(firstPunkt_, lastPunkt_, color_) {
        rad = std::hypot(firstPunkt.x() - lastPunkt.x(), firstPunkt.y() - lastPunkt.y());
    }

    void mallen(QPainter* objkt) override;


};

#endif // CIRCLE_H
