#include "mainwindow.h"
#include "ui_mainwindow.h"
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

}

void MainWindow::on_CreateTable_clicked()
{
    hide();
      drabinki = new Drabinki(this);
      drabinki->show();

}
