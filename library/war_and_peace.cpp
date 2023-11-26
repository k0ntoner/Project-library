#include "war_and_peace.h"
#include "ui_war_and_peace.h"
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
War_and_Peace::War_and_Peace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::War_and_Peace)
{
    ui->setupUi(this);
}

War_and_Peace::~War_and_Peace()
{
    delete ui;
}

void War_and_Peace::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), "Text Files (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // Создаем и записываем пустой текст в файл
            QTextStream stream(&file);
            stream << "This is an empty text file.";

            file.close();
            QMessageBox::information(this, "Download Complete", "The file has been downloaded successfully.");
        } else {
            QMessageBox::warning(this, "Error", "Unable to open the file for writing.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Invalid file name.");
    }
}

