#include "open.h"
#include "ui_open.h"
#include <QPixmap>
#include <QGridLayout>
#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include<QPushButton>
#include<QFile>
#include <QMessageBox>
#include <QFileDialog>
Open::Open(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Open)
{
    ui->setupUi(this);
}

Open::~Open()
{
    delete ui;
}
void Open::Fill_area(const QString &text)
{
    ui->Name->setText(text);
    QPixmap Img(":/img/picture/"+text+".jpg");
    ui->Img->setPixmap(Img);


}

void Open::on_Download_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), "Text Files (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // Создаем и записываем пустой текст в файл
            QTextStream stream(&file);
            stream << "This is an empty text file." ;

            file.close();
            QMessageBox::information(this, "Download Complete", "The file has been downloaded successfully.");
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file for writing.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Invalid file name.");
    }

}

