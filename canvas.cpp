#include <QPainter>
#include <QMouseEvent>
#include <QColor>
#include <QFrame>
#include "canvas.h"
#include "line.h"

Canvas::Canvas(QWidget *parent)
    : QFrame(parent)
{
    dragging = false;
    objkt =nullptr;

    laenge = this->height();
    breite = this->width();
}
QSize Canvas::minimumSizeHint() const
{
    return QSize(200,200);
}

QSize Canvas::sizeHint() const
{
    return QSize(640,480);
}


void Canvas::paintEvent(QPaintEvent *event) {


    QFrame::paintEvent(event);  // parent class draws border

    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.fillRect(QRectF(0,0, width() -1, height() -1), Qt::white);
    painter.drawRect(QRectF(0,0, width() -1, height() -1));
    if( laenge != this->height() || breite != this->width()){
        gridMallen();
        laenge = this->height();
        breite = this->width();
    }


    gridScene.paintAllObjects(&painter);

    update();


}

void Canvas::mousePressEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        dragging = true;

        update();
    }
}
void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && dragging) {


        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton && dragging) {

        update();
    }

}
void Canvas::gridMallen(){
    gridScene.removeAllObjects();
    int cellSizeX = width() / 3;
    int cellSizeY = height() / 3;
    for(int i = 1; i < 3; ++i){
        double x = i * width() / 3;
        QPointF firstPunkt(x, 0.0);
        QPointF lastPunkt(x, height());
        gridScene.addObjkt(new Line(firstPunkt, lastPunkt, Qt::black));
    }
    for (int i = 1; i < 3; ++i){
        double y = i * height() / 3;
        QPointF firstPunkt(0.0, y);
        QPointF lastPunkt(width(), y);
        gridScene.addObjkt(new Line(firstPunkt, lastPunkt, Qt::black));
    }

}

