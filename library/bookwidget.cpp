#include "bookwidget.h"
#include <QLabel>
#include <QVBoxLayout>

BookWidget::BookWidget(const QString& title, QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    titleLabel = new QLabel(title, this);
    layout->addWidget(titleLabel);
}
