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

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    bool dragging;
    Scene gridScene;
    Scene playScene;
    GraphObjkt* objkt;
    int laenge, breite;

};

#endif // CANVAS_H
