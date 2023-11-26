#ifndef WAR_AND_PEACE_H
#define WAR_AND_PEACE_H

#include <QDialog>

namespace Ui {
class War_and_Peace;
}

class War_and_Peace : public QDialog
{
    Q_OBJECT

public:
    explicit War_and_Peace(QWidget *parent = nullptr);
    ~War_and_Peace();

private slots:
    void on_pushButton_clicked();

private:
    Ui::War_and_Peace *ui;
};

#endif // WAR_AND_PEACE_H
