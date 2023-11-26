#ifndef NARNIA_H
#define NARNIA_H

#include <QDialog>

namespace Ui {
class Narnia;
}

class Narnia : public QDialog
{
    Q_OBJECT

public:
    explicit Narnia(QWidget *parent = nullptr);
    ~Narnia();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Narnia *ui;
};

#endif // NARNIA_H
