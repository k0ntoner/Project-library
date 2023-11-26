#ifndef FAVORITE_H
#define FAVORITE_H

#include <QDialog>

namespace Ui {
class favotite;
}

class favotite : public QDialog
{
    Q_OBJECT

public:
    explicit favotite(QWidget *parent = nullptr);
    ~favotite();

private:
    Ui::favotite *ui;
};

#endif // FAVORITE_H
