#ifndef DRABINKI_H
#define DRABINKI_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Drabinki;
}

class Drabinki : public QDialog
{
    Q_OBJECT

public:
    explicit Drabinki(QWidget *parent = nullptr);
    ~Drabinki();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Drabinki *ui;
    QMainWindow *mainwindow;
};

#endif // DRABINKI_H
