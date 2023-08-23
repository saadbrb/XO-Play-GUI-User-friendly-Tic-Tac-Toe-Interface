#ifndef PAINT_H
#define PAINT_H

#include <QWidget>
#include "canvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Paint; }
QT_END_NAMESPACE

class Paint : public QWidget
{
    Q_OBJECT

public:
    Paint(QWidget *parent = nullptr);
    ~Paint();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Paint *ui;
    Canvas* canvas;

};
#endif // PAINT_H
