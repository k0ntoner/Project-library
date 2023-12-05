#ifndef LIST_BOOKS_H
#define LIST_BOOKS_H

#include <QDialog>
#include <QFile>
#include <QScrollBar>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QCoreApplication>
#include<QVector>
#include<QString>
#include<QList>
#include<QLabel>
#include "liked.h"
namespace Ui {
class List_books;
}
class Book {
public:
    QString title;
    QString author;

    Book(const QString& title, const QString& author)
        : title(title), author(author) {}
};
class List_books : public QDialog
{
    Q_OBJECT

public:
    explicit List_books(QWidget *parent = nullptr);
    ~List_books();
    void setLikedInstance(Liked* likedInstance);
    void Fill_books();
    void Fill_area();
    void Open_Buttonclicked();
    void Like_Buttonclicked();
    void SearchBook();

private:
    Ui::List_books *ui;
    QVector<QLabel*> Names_of_books;
    QVector<QLabel*> Img_of_books;
    QMap<QString, QList<Book>> genreBooks;
    int number_of_favorite=0;
    QLabel *BookName;
    QLabel *Bookimg;
    QVector<QPushButton*> Download_buttons;
    QVector<QPushButton*> Like_buttons;
    Liked *liked;
};

#endif // LIST_BOOKS_H
