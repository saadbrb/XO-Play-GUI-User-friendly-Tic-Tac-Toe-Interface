#include "graphikobjkt.h"


void GraphikObjkt::setFirstPunkt(double ratioX, double ratioY){
    firstPunkt.rx() = firstPunkt.x() * ratioX;
    firstPunkt.ry() = firstPunkt.y() * ratioY;
}
void GraphikObjkt::setLastPunkt(double ratioX, double ratioY){
    lastPunkt.rx() = lastPunkt.x() * ratioX;
    lastPunkt.ry() = lastPunkt.y() * ratioY;
}

