#ifndef SIGH_UP_H
#define SIGH_UP_H

#include <QDialog>
#include <QFile>
namespace Ui {
class Sigh_up;
}

class Sigh_up : public QDialog
{
    Q_OBJECT

public:
    explicit Sigh_up(QWidget *parent = nullptr);
    ~Sigh_up();

private slots:
    void on_Accept_Button_clicked();
    bool accountExists(const QString &email);

private:
    Ui::Sigh_up *ui;
};

#endif // SIGH_UP_H
