#include "booksearchwidget.h"

#include "bookwidget.h"
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QDebug>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QLabel>
BookSearchWidget::BookSearchWidget(QLineEdit* lineForFind,QPushButton* Find, QVector<QLabel*> books, QWidget* parent) : QWidget(parent), lineForFind(lineForFind) {


    connect( Find, &QPushButton::clicked, this, &BookSearchWidget::searchBook);
}

void BookSearchWidget::searchBook() {
    QString searchText = lineForFind->text().trimmed().toLower();

    for (QLabel* label :  books) {
        QString bookTitle = label->text().toLower();
        if (bookTitle.contains(searchText)) {
            emit bookFound(bookTitle);
            // Дополнительные действия при нахождении книги
            return;
        }
    }

    qDebug() << "No";
}

void BookSearchWidget::setScrollArea(QScrollArea* scrollArea) {
    this->scrollArea = scrollArea;
}

void BookSearchWidget::scrollToWidget(QWidget* widget) {
    QScrollBar* verticalScrollBar = scrollArea->verticalScrollBar();
    verticalScrollBar->setValue(widget->geometry().top());
}
