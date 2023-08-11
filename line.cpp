#include <cmath>
#include "line.h"

void Line::mallen(QPainter* objkt) {
    objkt->setPen(QPen(color,painterSize,Qt::SolidLine));

    objkt->drawLine(firstPunkt, lastPunkt);

}
