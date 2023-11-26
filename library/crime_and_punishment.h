#ifndef CRIME_AND_PUNISHMENT_H
#define CRIME_AND_PUNISHMENT_H

#include <QDialog>

namespace Ui {
class Crime_and_Punishment;
}

class Crime_and_Punishment : public QDialog
{
    Q_OBJECT

public:
    explicit Crime_and_Punishment(QWidget *parent = nullptr);
    ~Crime_and_Punishment();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Crime_and_Punishment *ui;
};

#endif // CRIME_AND_PUNISHMENT_H
