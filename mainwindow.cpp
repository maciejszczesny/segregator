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


    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Maciek/Documents/qt cpp/segregator/zawodnicy.db");

    if(!db.open())
    {
       ui->CheckBase->setText("Nie udalo sie otworzyc bazy danych.");
      }
    else
    {
        ui->CheckBase->setText("Połączono z bazą.");
      }
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

    QString Imie,Nazwisko,Wiek,Plec;
     Imie=ui->TxtName->text();
     Nazwisko=ui->TxtSurname->text();
     Wiek=ui->TxtAge->text();
 //    Plec=ui->checkBoxWoman->text();
//     Plec=ui->checkBoxMan->text();



     db.open();
     if(!db.open())
         qDebug()<<"Problem z otwarciem bazy";
     else
         qDebug()<<"Połączono z bazą";

     QSqlQuery qry;
     qry.prepare("insert into zawodnicy (Imie,Nazwisko,Wiek) values ('"+Imie+"','"+Nazwisko+"','"+Wiek+"')");

     if(qry.exec())
     {
         QMessageBox::information(this,tr("Zapis"),tr("Zapisano"));
         db.close();
         db.removeDatabase(QSqlDatabase::defaultConnection);

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
