#include <cmath>
#include "line.h"

void Line::mallen(QPainter* objkt) {
    objkt->setPen(QPen(color,2,Qt::SolidLine));

    objkt->drawLine(firstPunkt, lastPunkt);

}
