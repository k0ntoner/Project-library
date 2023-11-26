#ifndef CATALOG_H
#define CATALOG_H

#include <QDialog>
#include<QVector>
#include "harry_potter__stone.h"
#include "crime_and_punishment.h"
#include "narnia.h"
#include "war_and_peace.h"
#include "a_game_of_thrones.h"
#include "galaxy.h"
#include "margarita.h"
#include "liked.h"
#include <QTimer>
#include <QDateTime>
#include <QTime>
#include <QScrollBar>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QCoreApplication>

namespace Ui {
class Catalog;
}

class Catalog : public QDialog
{
    Q_OBJECT

public:
    explicit Catalog(QWidget *parent = nullptr);
    ~Catalog();

private slots:

    void on_Harry_like_clicked();

    void on_Crime_Like_clicked();

    void on_Margarita_Like_clicked();

    void on_War_like_clicked();

    void on_Thrones_Like_clicked();

    void on_Galaxy_LIke_clicked();

    void on_Narnia_Like_clicked();

    void on_Open_Harry_clicked();

    void on_Open_Crime_clicked();

    void on_Open_Margarita_clicked();

    void on_Open_War_clicked();

    void on_Open_Thrones_clicked();

    void on_Open_Galaxy_clicked();

    void on_Open_Narnia_clicked();
    void timerTick();
    void onSearchTextChanged(const QString &text);


private:
    Ui::Catalog *ui;
    Harry_Potter__Stone *Harry_book;
    Crime_and_Punishment *crime_book;
    Narnia *narnia;
    War_and_Peace *war;
    A_Game_of_Thrones *Thrones;
    Galaxy *galaxy;
    Margarita *margarita;
    Liked *liked;
    QVector<QLabel*> Names_of_books;

    bool liked_open=0;
    QTimer *current_time;
    QTime currentTime;
    QDate currentDate;

};

#endif // CATALOG_H
