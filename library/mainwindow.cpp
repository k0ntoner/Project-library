#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    sigh_up= new Sigh_up(this);
    sigh_up->show();
}


void MainWindow::on_LOg_int_Button_clicked()
{
    log_in= new Log_in(this);
    log_in->show();
}

