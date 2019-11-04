#include "drabinki.h"
#include "ui_drabinki.h"
#include <QMessageBox>
#include <QSqlError>
#include <QtSql>

Drabinki::Drabinki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Drabinki)
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

void Drabinki::on_ShowLadders_clicked()
{
    qDebug()<<"Start";

     QSqlQueryModel* modal = new QSqlQueryModel();
     QSqlQuery *qry = new QSqlQuery(db);
     qry->prepare("Select Id,Imie,Nazwisko,Klub,Wiek FROM zawodnicy");
     qry->exec();
     modal->setQuery(*qry);
     ui->treeView->setModel(modal);
}
