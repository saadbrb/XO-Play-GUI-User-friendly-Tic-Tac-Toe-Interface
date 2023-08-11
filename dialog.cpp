#include <QDebug>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QDateTime>
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::setGewinner(QString gewinner){
    this->gewinner = gewinner;
}

void Dialog::on_lineEdit_2_selectionChanged()
{
    //ui->get_number_punkten->setText(QString("Invalide Inpute"));
    ui->lineEdit_2->setText(QString(gewinner));

}


void Dialog::on_pushButton_2_clicked()
{
    type = 0;
    QCoreApplication::quit();

}

int Dialog::getType(){
    return type;
}
void Dialog::on_pushButton_clicked()
{
    type = 1;
    QCoreApplication::quit();

}

