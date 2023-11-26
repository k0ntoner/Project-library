#ifndef BOOKSEARCHWIDGET_H
#define BOOKSEARCHWIDGET_H

#include <QWidget>
#include <QLabel>
class QLineEdit;
class QPushButton;
class QScrollArea;

class BookSearchWidget : public QWidget {
    Q_OBJECT
public:
    BookSearchWidget(QLineEdit* lineForFind,QPushButton* Find,QVector<QLabel*> books, QWidget* parent = nullptr);

signals:
    void bookFound(QString title);

public slots:
    void searchBook();
    void setScrollArea(QScrollArea* scrollArea);

private:
    QLineEdit* lineForFind;  // Добавляем указатель на QLineEdit
    QPushButton* searchButton;
    QScrollArea* scrollArea;
    QVector<QLabel*> books;
    void scrollToWidget(QWidget* widget);
};

#endif // BOOKSEARCHWIDGET_H
