#include "log_in.h"
#include "ui_log_in.h"
#include <QFile>
#include<QTextStream>
#include <QTextEdit>
#include <QDialog>
Log_in::Log_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log_in)
{
    ui->setupUi(this);
    setWindowTitle("Login Window");
}

Log_in::~Log_in()
{
    delete ui;
}

void Log_in::on_pushButton_clicked()
{
    bool autorizetion= false;
    QFile file("C:/Users/Andrew/Documents/library/Accaunts.txt");
    QString text;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString Email=in.readLine();
            QString Password=in.readLine();
            QString Saves=in.readLine();
            Email.remove(0,2);
            Password.remove(0,2);
            if(ui->Email_lineEdit->text() == Email && ui->Password_lineEdit->text()==Password){
                file.close();
                qDebug() << "Вход выполнен успешно!";
                autorizetion = true;
                QFile file_saves("C:/Users/Andrew/Documents/library/Accaunts_saves.txt");
                if (file_saves.open(QIODevice::Append | QIODevice::Text)) {
                    QTextStream out(&file_saves);
                    out << "E:" << ui->Email_lineEdit->text() << '\n';
                    out << "P:" << ui->Password_lineEdit->text() << '\n';
                    out << Saves;
                    qDebug() << Saves;
                    file_saves.close();
                    break;
                }
            }
        }
        if(autorizetion == true){
            hide();
            catalog= new Catalog(this);
            catalog->show();
        }
        else{
            ui->Error->setText("Account doesnt found");
        }
    }
}

