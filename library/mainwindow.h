#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sigh_up.h"
#include "log_in.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_LOg_int_Button_clicked();

private:

    Ui::MainWindow *ui;
    Sigh_up *sigh_up;
    Log_in *log_in;

};
#endif // MAINWINDOW_H
