#ifndef A_GAME_OF_THRONES_H
#define A_GAME_OF_THRONES_H

#include <QDialog>

namespace Ui {
class A_Game_of_Thrones;
}

class A_Game_of_Thrones : public QDialog
{
    Q_OBJECT

public:
    explicit A_Game_of_Thrones(QWidget *parent = nullptr);
    ~A_Game_of_Thrones();

private slots:
    void on_pushButton_clicked();

private:
    Ui::A_Game_of_Thrones *ui;
};

#endif // A_GAME_OF_THRONES_H
