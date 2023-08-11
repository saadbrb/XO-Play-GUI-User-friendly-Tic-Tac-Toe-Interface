#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setGewinner(QString gewinner);
    int getType();
    ~Dialog();

private slots:
    void on_lineEdit_2_selectionChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    int type = -1;
    QString gewinner;

};

#endif // DIALOG_H
