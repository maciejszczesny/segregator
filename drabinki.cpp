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

void Drabinki::on_ShowLadders_clicked()
{
    qDebug()<<"Start";

     QSqlQueryModel* modal = new QSqlQueryModel();
     QSqlQuery *qry = new QSqlQuery(db);
     qry->prepare("SELECT Imie,Nazwisko,Waga FROM zawodnicy WHERE  Waga > 60 AND Waga < 70 ORDER BY Waga;");
     qry->exec();
     modal->setQuery(*qry);
     ui->treeView->setModel(modal);
}

void Drabinki::on_CategoryList_currentIndexChanged(const QString &arg1)
{
    QString kategoria=ui->CategoryList->currentText();


    db.open();
    if(!db.open())
        qDebug()<<"Problem z otwarciem bazy";
    else
        qDebug()<<"Połączono z bazą";


    QSqlQuery qry;
        qry.prepare("SELECT * FROM zawodnicy WHERE  Kategoria='"+kategoria+"')");

    if(qry.exec())
    {
        while(qry.next())
        {
            QSqlQueryModel* modal = new QSqlQueryModel();
            QSqlQuery *qry = new QSqlQuery(db);
            modal->setQuery(*qry);
            ui->treeView->setModel(modal);
        }
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
