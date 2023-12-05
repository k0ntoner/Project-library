#ifndef OPEN_H
#define OPEN_H

#include <QDialog>

namespace Ui {
class Open;
}

class Open : public QDialog
{
    Q_OBJECT

public:
    explicit Open(QWidget *parent = nullptr);
    ~Open();
public slots:
    void Fill_area(const QString &text);
private slots:
    void on_Download_clicked();

private:
    Ui::Open *ui;
};

#endif // OPEN_H
