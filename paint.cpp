#include "paint.h"
#include "ui_paint.h"

Paint::Paint(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Paint)
{
    ui->setupUi(this);
    canvas = new Canvas();
    ui->verticalLayout_3->replaceWidget(ui->frame, canvas);
    delete ui->frame;
    ui->frame = canvas;

}

Paint::~Paint()
{
    delete ui;
}


void Paint::on_pushButton_clicked()
{
   // canvas->neuSpiel();

}

