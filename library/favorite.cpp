#include "favorite.h"
#include "ui_favotite.h"

favotite::favotite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::favotite)
{
    ui->setupUi(this);
}

favotite::~favotite()
{
    delete ui;
}
