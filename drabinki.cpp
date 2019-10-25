#include "drabinki.h"
#include "ui_drabinki.h"

Drabinki::Drabinki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Drabinki)
{
    ui->setupUi(this);
}

Drabinki::~Drabinki()
{
    delete ui;
}

void Drabinki::on_pushButton_3_clicked()
{
    hide();
        mainwindoww = new QMainWindow(this);
       mainwindoww->show();
}
