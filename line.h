#ifndef LINE_H
#define LINE_H


#include "graphikobjkt.h"

class Line : public GraphObjkt
{
public:
    Line(QPointF firstPunkt_, QPointF lastPunkt_, QColor color_):
        GraphObjkt(firstPunkt_, lastPunkt_, color_) {}

    void mallen(QPainter* objkt) override;

};


#endif // LINE_H
