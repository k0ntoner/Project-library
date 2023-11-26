#ifndef BOOKWIDGET_H
#define BOOKWIDGET_H

#include <QWidget>

class QLabel;
class QVBoxLayout;

class BookWidget : public QWidget {
    Q_OBJECT
public:
    BookWidget(const QString& title, QWidget* parent = nullptr);

private:
    QLabel* titleLabel;
};

#endif // BOOKWIDGET_H
