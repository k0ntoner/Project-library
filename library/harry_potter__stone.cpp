#include "harry_potter__stone.h"
#include "ui_harry_potter__stone.h"
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
Harry_Potter__Stone::Harry_Potter__Stone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Harry_Potter__Stone)
{
    ui->setupUi(this);
    QPixmap pic(":/img/picture/Harry Potter and the Philosopher's Stone.jpg");
    ui->harry_img->setPixmap(pic);
}

Harry_Potter__Stone::~Harry_Potter__Stone()
{
    delete ui;
}

void Harry_Potter__Stone::on_pushButton_clicked()
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

