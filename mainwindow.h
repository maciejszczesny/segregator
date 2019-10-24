#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drabinki.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonAdd_clicked();

    void on_CreateTable_clicked();

private:
    Ui::MainWindow *ui;
    Drabinki *drabinki;
};
#endif // MAINWINDOW_H
