#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("zawodnicy.sqlite");
 // QSqlDatabase m_db=QSqlDatabase::AddDatabaseName("QSQLITE");
//  m_db.setDatabaseName("C:/Users/Maciek/Desktop/dbzawodnicy");

  if(!db.open())
     ui->CreateTable->setText("Nie udalo sie otworzyc bazy danych, nie można utworzyć drabinek :(");
  else
      ui->CreateTable->setText("Utwórz drabinki");

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

        QString id,Imie,Nazwisko,Wiek,Waga,Wzrost,Klub;
        Imie=ui->TxtName->text();
        Nazwisko=ui->TxtSurname->text();
        Wiek=ui->TxtAge->text();
        Waga=ui->TxtWeight->text();
        Wzrost=ui->TxtHeight->text();
        Klub=ui->TxtClub->text();



        db.open();
        QSqlQuery qry;
        qry.prepare("insert into zawodnicy (id,Imie,Nazwisko,Wiek,Waga,Wzrost) values ('"+id+"','"+Imie+"','"+Nazwisko+"','"+Wiek+"','"+Waga+"','"+Wzrost+"'");

        if(qry.exec())
        {
            QMessageBox::information(this,tr("Zapisz"),tr("Zapisano"));
            db.close();
        }
        else
            QMessageBox::critical(this,tr("Błąd!!!"),qry.lastError().text());
}

void MainWindow::on_CreateTable_clicked()
{
    hide();
      drabinki = new Drabinki(this);
      drabinki->show();

}
