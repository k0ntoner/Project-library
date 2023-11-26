#ifndef MARGARITA_H
#define MARGARITA_H

#include <QDialog>

namespace Ui {
class Margarita;
}

class Margarita : public QDialog
{
    Q_OBJECT

public:
    explicit Margarita(QWidget *parent = nullptr);
    ~Margarita();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Margarita *ui;
};

#endif // MARGARITA_H
