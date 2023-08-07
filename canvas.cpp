#include <QPainter>
#include <QMouseEvent>
#include <QColor>
#include "canvas.h"
#include "line.h"

Canvas::Canvas(QWidget *parent)
    : QFrame(parent)
{
    dragging = false;
    objkt =nullptr;


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
    gridMallen();
    gridScene.paintAllObjects(&painter);



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
    int cellX = this->width()/3;
    int cellY = this->height()/3;
    for(int x=0; x<this->height(); x+=cellX){
        for(int y=0; y<this->width(); y+=cellY){


            QPointF firstPunkt;
            QPointF lastPunkt;
            //Zeilen Zeichnen
            firstPunkt.rx() = x;
            firstPunkt.ry() = 0;
            lastPunkt.rx() = x;
            lastPunkt.ry() = this->height();
            objkt = new Line(firstPunkt, lastPunkt, Qt::black);
            gridScene.addObjkt(objkt);
            //Spalten Zeichnen
            firstPunkt.rx() = 0;
            firstPunkt.ry() = y;
            lastPunkt.rx() = this->width();
            lastPunkt.ry() = y;
            objkt = new Line(firstPunkt, lastPunkt, Qt::black);
            gridScene.addObjkt(objkt);

        }
    }

}

