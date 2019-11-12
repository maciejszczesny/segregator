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
    ((QMainWindow*)this->parent())->show();
}


void Drabinki::on_WalkiButton_clicked()
{
    qDebug()<<"Start";

     QSqlQueryModel* modal = new QSqlQueryModel();
     QSqlQuery *qry = new QSqlQuery(db);
     qry->prepare("SELECT Imie,Nazwisko,Klub,Wiek,Waga FROM zawodnicy WHERE walki ='1' ORDER BY Wiek;");
     qry->exec();
     modal->setQuery(*qry);
     ui->treeView->setModel(modal);
}

void Drabinki::on_TechnikiButton_clicked()
{
    qDebug()<<"Start";

     QSqlQueryModel* modal = new QSqlQueryModel();
     QSqlQuery *qry = new QSqlQuery(db);
     qry->prepare("SELECT Imie,Nazwisko,Klub,Wiek,Wzrost FROM zawodnicy WHERE techniki ='1' ORDER BY Wzrost;");
     qry->exec();
     modal->setQuery(*qry);
     ui->treeView->setModel(modal);
}


void Drabinki::on_UkladyButton_clicked()
{
    qDebug()<<"Start";

     QSqlQueryModel* modal = new QSqlQueryModel();
     QSqlQuery *qry = new QSqlQuery(db);
     qry->prepare("SELECT Imie,Nazwisko,Klub,Wiek FROM zawodnicy WHERE uklady ='1' ORDER BY Wiek;");
     qry->exec();
     modal->setQuery(*qry);
     ui->treeView->setModel(modal);
}


//void Drabinki::on_ShowCategory_clicked()
//{
//    QString kategoria=ui->CategoryList->currentText();
//    QSqlQueryModel* modal = new QSqlQueryModel();

//        db.open();
//        if(!db.open())
//            qDebug()<<"Problem z otwarciem bazy";
//        else
//            qDebug()<<"Połączono z bazą";

//    QSqlQuery *qry = new QSqlQuery(db);

//            qry->prepare("SELECT Kategoria FROM zawodnicy");

//        if(qry->exec())
//        {
//            modal->setQuery(*qry);
//            ui->CategoryList->setModel(modal);
//            db.close();
//           // db.removeDatabase(QSqlDatabase::defaultConnection);

//        }
//        else
//        {
//           QMessageBox::critical(this,tr("Błąd"), qry->lastError().text());
//           db.close();
//           db.removeDatabase(QSqlDatabase::defaultConnection);
//        }

//        if(!db.open())
//            qDebug()<<"Zamknięto bazę";
//        else
//            qDebug()<<"Nie zamknięto bazy";
//}


