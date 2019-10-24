#include "drabinki.h"
#include "ui_drabinki.h"
#include "mainwindow.h"

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
  mainwindow = new MainWindow(this);
    mainwindow->show();
}
