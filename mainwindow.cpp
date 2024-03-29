#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QtSql>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Maciek/Documents/qt cpp/segregator/zawodnicy.db");

//    if(!db.open())
//    {
//       ui->CheckBase->setText("Nie udalo sie otworzyc bazy danych.");
//      }
//    else
//    {
//        ui->CheckBase->setText("Połączono z bazą.");
//      }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonClose_clicked()
{

}

void MainWindow::on_pushButtonAdd_clicked()
{

    qDebug()<<"Start";

    QString Imie,Nazwisko,Wiek,Klub,Waga,Wzrost;
     Imie=ui->TxtName->text();
     Nazwisko=ui->TxtSurname->text();
     Wiek=ui->TxtAge->text();
     Klub=ui->TxtClub->text();
     Waga=ui->TxtWeight->text();
     Wzrost=ui->TxtHeight->text();

    int Plec=0; //<<<Mężczyzna przypisany jako "0"
    if (ui->RadioWoman->isChecked()){Plec=1;}

    int walki=0;
   if(ui->checkBox->isChecked()){walki=1;}

    int uklady=0;
    if(ui->checkBox_2->isChecked()){uklady=1;}

    int techniki=0;
    if(ui->checkBox_3->isChecked()){techniki=1;}
   // qDebug()<<ui->checkBox_3->isChecked();





     db.open();
     if(!db.open())
         qDebug()<<"Problem z otwarciem bazy";
     else
         qDebug()<<"Połączono z bazą";

     QSqlQuery qry;

       qry.prepare("insert into zawodnicy (Imie,Nazwisko,Wiek,Klub,Waga,Wzrost,Plec,Walki,Uklady,Techniki) values ('"+Imie+"','"+Nazwisko+"','"+Wiek+"','"+Klub+"','"+Waga+"','"+Wzrost+"','"+QString::number(Plec)+"','"+QString::number(walki)+"','"+QString::number(uklady)+"','"+QString::number(techniki)+"')");

     if(qry.exec())
     {
         QMessageBox::information(this,tr("Zapis"),tr("Zapisano"));
         db.close();
        // db.removeDatabase(QSqlDatabase::defaultConnection);

     }
     else
     {
        QMessageBox::critical(this,tr("Błąd"), qry.lastError().text());
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
     }

     if(!db.open())
         qDebug()<<"Zamknięto bazę";
     else
         qDebug()<<"Nie zamknięto bazy";
}

void MainWindow::on_CreateTable_clicked()
{
    hide();
      drabinki = new Drabinki(this);
      drabinki->show();

}
