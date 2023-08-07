#ifndef GRAPHIKOBJEKT_H
#define GRAPHIKOBJEKT_H


#include <iostream>
#include <QPointF>
#include <QPainter>
#include <QtGlobal>


class GraphObjkt
{
protected:
    QPointF firstPunkt;
    QPointF lastPunkt;
    QColor color;
    bool showOutline;
    QPointF min,max;
    bool deko;

public:

    GraphObjkt(QPointF firstPunkt_, QPointF lastPunkt_, QColor color_):
        firstPunkt(firstPunkt_), lastPunkt(lastPunkt_), color(color_){}

    GraphObjkt(const GraphObjkt&);
    explicit GraphObjkt(bool deko_ = false ): deko(deko_){}


    // Verbieten den Kopierkonstruktor und den Zuweisungsoperator
    // GraphObj(const GraphObj&) = delete;
    GraphObjkt& operator=(const GraphObjkt&) = delete;
    void setLastPunkt(QPointF p) {
        lastPunkt = p;
    }
    QPointF getFirstPunkt() const {
        return firstPunkt;
    }
    QPointF getLastPunkt() const {
        return lastPunkt;
    }
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

    virtual ~GraphObjkt() = default;
};

#endif // GRAPHIKOBJEKT_H
