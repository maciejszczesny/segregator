#ifndef XMAINWINDOW_H
#define XMAINWINDOW_H

#include <QDialog>

namespace Ui {
class XMainWindow;
}

class XMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit XMainWindow(QWidget *parent = nullptr);
    ~XMainWindow();

private slots:
    void on_Adding_clicked();

private:
    Ui::XMainWindow *ui;

};

#endif // XMAINWINDOW_H
