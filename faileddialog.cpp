#include "faileddialog.h"
#include "ui_faileddialog.h"

FailedDialog::FailedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FailedDialog)
{
    ui->setupUi(this);
}

FailedDialog::~FailedDialog()
{
    delete ui;
}

void FailedDialog::on_replay_clicked()
{
    hide();
}


void FailedDialog::on_beenden_clicked()
{
    QCoreApplication::quit();
}

