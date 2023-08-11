#ifndef CANVAS_H
#define CANVAS_H

#include <QFrame>
#include <QWidget>

#include "scene.h"

class Canvas : public QFrame
{
    Q_OBJECT
public:

    explicit Canvas(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void gridMallen();
    void malXIfPositionFound(QPointF);
    void malOIfPositionFound(QPointF);
    int getFeldX(QPointF);
    int getFeldY(QPointF);
    void checkPlayIfFinish();
    void ergebnisAnzeigen(char c);
    void neuSpiel();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool dragging;
    Scene gridScene;
    Scene playScene;
    int laenge, breite;
    QPointF firstPunkt, lastPunkt;
    int playerCounter = 0;
    char playFeld[3][3];

};

#endif // CANVAS_H
