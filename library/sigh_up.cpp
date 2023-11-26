#include "sigh_up.h"
#include "ui_sigh_up.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Sigh_up::Sigh_up(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sigh_up)
{
    ui->setupUi(this);
}

Sigh_up::~Sigh_up()
{
    delete ui;
}

void Sigh_up::on_Accept_Button_clicked()
{
    // Открываем файл в режиме дополнения
    if(ui->Password_Line->text()==ui->RepeatPaswword_Line->text()){
    QFile file("C:/Users/Andrew/Documents/library/Accaunts.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        // Проверяем, есть ли уже аккаунт с таким email
        if (accountExists(ui->Email_Line->text())) {
            ui->Error->setText("Account with this email already exists");
        } else {
            // Если такого аккаунта нет, добавляем новый
            QTextStream out(&file);
            out << "E:" << ui->Email_Line->text() << '\n';
            out << "P:" << ui->Password_Line->text() << '\n';
            file.close();
            hide();
        }
    }
    }
    else
    {
        ui->Error->setText("Passwords are not the same");
    }
}

bool Sigh_up::accountExists(const QString &email)
{
    // Проверяем, есть ли аккаунт с таким email в файле
    QFile file("C:/Users/Andrew/Documents/library/Accaunts.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("E:")) {
                QString storedEmail = line.mid(2); // Удаляем "E:" из начала строки
                if (storedEmail == email) {
                    file.close();
                    return true; // Аккаунт с таким email уже существует
                }
            }
        }
        file.close();
    }
    return false; // Аккаунт с таким email не найден
}
