#ifndef DRABINKI_H
#define DRABINKI_H

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

private:
    Ui::Drabinki *ui;
};

#endif // DRABINKI_H
