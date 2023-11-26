#ifndef HARRY_POTTER__STONE_H
#define HARRY_POTTER__STONE_H

#include <QDialog>

namespace Ui {
class Harry_Potter__Stone;
}

class Harry_Potter__Stone : public QDialog
{
    Q_OBJECT

public:
    explicit Harry_Potter__Stone(QWidget *parent = nullptr);
    ~Harry_Potter__Stone();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Harry_Potter__Stone *ui;
};

#endif // HARRY_POTTER__STONE_H
