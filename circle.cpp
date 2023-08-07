#include "circle.h"


void Circle::mallen(QPainter* objkt){
    rad = std::hypot(firstPunkt.x() - lastPunkt.x(), firstPunkt.y() - lastPunkt.y());
    objkt->setPen(QPen(color, 2, Qt::SolidLine));
    if(!showOutline){
        objkt->setBrush(color);
    }
    else {
        objkt->setBrush(Qt::NoBrush);
    }
    double x = firstPunkt.x() - rad;
    double y = firstPunkt.y() - rad;
    double diameter = rad * 2;

    objkt->drawEllipse(QRectF(x, y, diameter, diameter));
}


