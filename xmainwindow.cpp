#include "xmainwindow.h"
#include "ui_xmainwindow.h"
#include <xmainwindow.h>
XMainWindow::XMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::XMainWindow)
{
    ui->setupUi(this);
}

XMainWindow::~XMainWindow()
{
    delete ui;
}

void XMainWindow::on_Adding_clicked()
{
    XMainWindow XMainWindow;
    XMainWindow.setModal(true);
    XMainWindow.exec();
}
