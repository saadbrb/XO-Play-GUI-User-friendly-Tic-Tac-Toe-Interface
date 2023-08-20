#include <QPainter>
#include <QMouseEvent>
#include <QColor>
#include <QApplication>
#include <QDebug>
#include <QFrame>
#include <QDialog>
#include <QAction>

#include "canvas.h"
#include "line.h"
#include "circle.h"
#include "dialog.h"

Canvas::Canvas(QWidget *parent)
    : QFrame(parent)
{
    dragging = false;
    laenge = this->height();
    breite = this->width();
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            playFeld[i][j] = ' ';
        }
    }
}

void Canvas::neuSpiel(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            playFeld[i][j] = ' ';
        }
    }
    playScene.removeAllObjects();
    playerCounter = 0;
    gridMallen();
    dragging = false;
    update();
}
QSize Canvas::minimumSizeHint() const
{
    return QSize(200,200);
}

QSize Canvas::sizeHint() const
{
    return QSize(640,480);
}


void Canvas::ergebnisAnzeigen(char c)
{
    Dialog  secdialog;
    QString gewinner;
    if(c == 'x'){
        gewinner = "\tPlayer    X";
    }
    else if (c == 'o') {
        gewinner = "\tPlayer    O";
    }
    else {
        return;
    }
    secdialog.setGewinner(gewinner);
    secdialog.on_lineEdit_2_selectionChanged();
    secdialog.setModal(true);
    secdialog.show();
    secdialog.exec();
    qDebug()<<"type is = "<<secdialog.getType();
    if(secdialog.getType() == 0){
        exit(0);
        qDebug()<<"type is = "<<secdialog.getType();

    }
    else if (secdialog.getType() == 1) {
        neuSpiel();
        qDebug()<<"type is = "<<secdialog.getType();

    }
    else {
        return;
    }

}
void Canvas::checkPlayIfFinish(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(playFeld[i][0] == playFeld[i][1] && playFeld[i][1] == playFeld[i][2] && playFeld[i][2] != ' '){
                ergebnisAnzeigen(playFeld[i][0]);
            }
            else if(playFeld[0][j] == playFeld[1][j] && playFeld[1][j] == playFeld[2][j] && playFeld[2][j] != ' '){
                ergebnisAnzeigen(playFeld[1][j]);
            }
            else if(playFeld[0][0] == playFeld[1][1] && playFeld[1][1] == playFeld[2][2] && playFeld[2][2] != ' '){
                ergebnisAnzeigen(playFeld[0][0]);
            }
            else if(playFeld[0][2] == playFeld[1][1] && playFeld[1][1] == playFeld[2][0] && playFeld[2][0] != ' '){
                ergebnisAnzeigen(playFeld[2][0]);
            }
        }
    }
}

void Canvas::paintEvent(QPaintEvent *event) {

    checkPlayIfFinish();
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
    // wenn playerCounter % 2 == 0 dann der Player is X ansonsten O
    if(dragging && firstPunkt == lastPunkt ){
        if(playerCounter % 2 == 0){
            int row = getFeldX(firstPunkt);
            int col = getFeldY(firstPunkt);
            if(playFeld[row][col] != 'x' && playFeld[row][col] != 'o'){
                malXIfPositionFound(firstPunkt);
                playFeld[row][col] = 'x';
                playerCounter++;
            }
        }
        else if(playerCounter % 2 != 0){
            int row = getFeldX(firstPunkt);
            int col = getFeldY(firstPunkt);
            if(playFeld[row][col] != 'x' && playFeld[row][col] != 'o'){
                malOIfPositionFound(firstPunkt);
                playFeld[row][col] = 'o';
                playerCounter++;
            }
        }
    }
    gridScene.paintAllObjects(&painter);
    playScene.paintAllObjects(&painter);
    painter.end();
}

void Canvas::mousePressEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        dragging = true;
        firstPunkt = event->pos();
        lastPunkt = firstPunkt;
        update();
    }
}
void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && dragging) {
        lastPunkt = event->pos();
        dragging = true;
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton && dragging) {
        lastPunkt = event->pos();
        dragging = false;
        update();
    }

}

int Canvas::getFeldX(QPointF p){
    float cellSizeX = width() / 3;
    float col = std::min(int(p.x() / cellSizeX), 3 - 1);
    return col;
}
int Canvas::getFeldY(QPointF p){
    float cellSizeY = height() / 3;
    float row = std::min(int(p.y() / cellSizeY), 3 - 1);
    return row;
}
void Canvas::gridMallen(){
    gridScene.removeAllObjects();

    for(int i = 1; i < 3; ++i){
        double x = i * this->width() / 3;
        QPointF firstPunkt(x, 0.0);
        QPointF lastPunkt(x, this->height());
        gridScene.addObjkt(new Line(firstPunkt, lastPunkt, Qt::black, 2));
    }
    for (int i = 1; i < 3; ++i){
        double y = i * this->height() / 3;
        QPointF firstPunkt(0.0, y);
        QPointF lastPunkt(this->width(), y);
        gridScene.addObjkt(new Line(firstPunkt, lastPunkt, Qt::black, 2));
    }

}

void Canvas::malOIfPositionFound(QPointF p){
    float cellSizeX = width() / 3;
    float cellSizeY = height() / 3;
    float col = std::min(int(p.x() / cellSizeX), 3 - 1);

    float row = std::min(int(p.y() / cellSizeY), 3 - 1);

    QPointF firstPunkt;
    double xPosition = ((col*this->width())/3) + (((col+1)*this->width())/3);
    xPosition = xPosition/2;
    double yPosition = ((row*this->height())/3) + (((row+1)*this->height())/3);
    yPosition = yPosition /2;
    firstPunkt.rx() = xPosition;
    firstPunkt.ry() = yPosition;
    QPointF lastPunkt;
    lastPunkt.rx() = firstPunkt.x() + 67;
    lastPunkt.ry() = firstPunkt.y() + 67;
    playScene.addObjkt(new Circle(firstPunkt, lastPunkt, Qt::red, 7));

}

void Canvas::malXIfPositionFound(QPointF p){
    float cellSizeX = width() / 3;
    float cellSizeY = height() / 3;
    float col = std::min(int(p.x() / cellSizeX), 3 - 1);
    float row = std::min(int(p.y() / cellSizeY), 3 - 1);
    QPointF firstPunkt;
    firstPunkt.rx() = (col*this->width())/3;
    firstPunkt.ry() = (row*this->height())/3;
    QPointF lastPunkt;
    lastPunkt.rx() = ((col+1)*this->width())/3;
    lastPunkt.ry() = ((row+1)*this->height())/3;
    playScene.addObjkt((new Line(firstPunkt, lastPunkt,Qt::blue, 7)));

    firstPunkt.rx() = ((col+1)*this->width())/3;
    firstPunkt.ry() = (row*this->height())/3;

    lastPunkt.rx() = (col*this->width())/3;
    lastPunkt.ry() = ((row+1)*this->height())/3;
    playScene.addObjkt((new Line(firstPunkt, lastPunkt,Qt::blue, 7)));

}
