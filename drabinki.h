#ifndef DRABINKI_H
#define DRABINKI_H
#include <QDialog>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>
namespace Ui {
class Drabinki;
}

class Drabinki : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit Drabinki(QWidget *parent = nullptr);
    ~Drabinki();

private slots:
    void on_pushButton_3_clicked();

    void on_ShowLadders_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_CategoryList_currentIndexChanged(const QString &arg1);

private:
    Ui::Drabinki *ui;
      QMainWindow *mainwindoww;
};

#endif // DRABINKI_H
