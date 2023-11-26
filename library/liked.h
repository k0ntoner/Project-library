#ifndef LIKED_H
#define LIKED_H

#include <QDialog>
#include<QLabel>
#include<QVector>
#include<QPushButton>
#include "harry_potter__stone.h"
#include "crime_and_punishment.h"
#include "narnia.h"
#include "war_and_peace.h"
#include "a_game_of_thrones.h"
#include "galaxy.h"
#include "margarita.h"
#include "liked.h"
namespace Ui {
class Liked;
}

class Liked : public QDialog
{
    Q_OBJECT

public:
    explicit Liked(QWidget *parent = nullptr);
    ~Liked();
    void setLabelText(const QString &text, const QString &book_name,int size_bookname[],int size_bookimg[]);
private slots:
    void onDeleteButtonClicked();
    void updateUI();
    void Open_Book();
private:
    Ui::Liked *ui;
    int number_of_favorite=0;
    QLabel *BookName;
    QLabel *Bookimg;
    QVector<QLabel*> BookNames;
    QVector<QLabel*> BookImgs;
    QVector<QPushButton*> Open_buttons;
    QVector<QPushButton*> Delete_buttons;
    Harry_Potter__Stone *Harry_book;
    Crime_and_Punishment *crime_book;
    Narnia *narnia;
    War_and_Peace *war;
    A_Game_of_Thrones *Thrones;
    Galaxy *galaxy;
    Margarita *margarita;
    Liked *liked;
    QVector<QLabel*> Names_of_books;
};

#endif // LIKED_H
