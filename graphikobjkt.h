#ifndef GRAPHIKOBJKT_H
#define GRAPHIKOBJKT_H
#include <cmath>
#include <QPointF>
#include <QColor>
#include <QPainter>


class GraphikObjkt
{
protected:
    QPointF firstPunkt;
    QPointF lastPunkt;
    QColor color;
    bool showOutline;
    QPointF min,max;
    bool deko;
    int painterSize;

public:

    GraphikObjkt(QPointF firstPunkt_, QPointF lastPunkt_, QColor color_, int painterSize_):
        firstPunkt(firstPunkt_), lastPunkt(lastPunkt_), color(color_), painterSize(painterSize_){}

    GraphikObjkt(const GraphikObjkt&);
    explicit GraphikObjkt(bool deko_ = false ): deko(deko_){}

    GraphikObjkt& operator=(const GraphikObjkt&) = delete;
    void setLastPunkt(QPointF p) {
        lastPunkt = p;
    }
    QPointF getFirstPunkt() const {
        return firstPunkt;
    }
    QPointF getLastPunkt() const {
        return lastPunkt;
    }
    void setFirstPunkt(double ratioX, double ratioY);
    void setLastPunkt(double ratioX, double ratioY);
    qreal minF(qreal x, qreal y) const{
        return qMin(x, y);
    }

    qreal maxF(qreal x, qreal y) const{
        return qMax(x, y);
    }
    QColor getColor(){
        return color;
    }

    virtual void mallen(QPainter* objkt) = 0;

    virtual ~GraphikObjkt() = default;
};

#endif // GRAPHIKOBJKT_H
