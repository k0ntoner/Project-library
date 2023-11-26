#ifndef GALAXY_H
#define GALAXY_H

#include <QDialog>

namespace Ui {
class Galaxy;
}

class Galaxy : public QDialog
{
    Q_OBJECT

public:
    explicit Galaxy(QWidget *parent = nullptr);
    ~Galaxy();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Galaxy *ui;
};

#endif // GALAXY_H
