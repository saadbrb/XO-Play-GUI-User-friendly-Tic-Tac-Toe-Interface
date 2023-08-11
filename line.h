#ifndef LINE_H
#define LINE_H


#include "graphikobjkt.h"

class Line : public GraphikObjkt
{
public:
    Line(QPointF firstPunkt_, QPointF lastPunkt_, QColor color_, int painterSize):
        GraphikObjkt(firstPunkt_, lastPunkt_, color_, painterSize) {}

    void mallen(QPainter* objkt) override;

};


#endif // LINE_H
