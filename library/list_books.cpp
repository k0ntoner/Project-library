#include "list_books.h"
#include "ui_list_books.h"
#include "liked.h"
#include <QPixmap>
#include <QGridLayout>
#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include<QPushButton>
#include <QCoreApplication>
#include<QFile>
List_books::List_books(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::List_books)
{
    ui->setupUi(this);
    setWindowTitle("List of book");
    Fill_books();
    Fill_area();
    connect(ui->SearchButton, &QPushButton::clicked, this, &List_books::SearchBook);
}

List_books::~List_books()
{
    delete ui;
}
void List_books::setLikedInstance(Liked* likedInstance)
{
    liked = likedInstance;
}
void List_books::SearchBook(){
    QString text=ui->SearchlineEdit->text();
    int k=0;
    for (const auto& genre : genreBooks.keys()) {
        if(genre.contains(text)){
            int y = k *432*5; // Adjust this based on your layout
            ui->scrollArea->verticalScrollBar()->setValue(y);
        }
        k++;
        const QList<Book>& booksInGenre = genreBooks[genre];
        int y=0;
        for (const Book& book : booksInGenre) {
            if(book.title.contains(text) ){
                for (int i = 0; i < Names_of_books.size(); ++i) {
                    if (Names_of_books[i]->text().contains(text, Qt::CaseInsensitive)) {

                        ui->scrollArea->verticalScrollBar()->setValue(y);
                        qDebug() << "Book found at index " << i;
                        return;
                    }
                    qDebug()<< Names_of_books[i]->height();
                    qDebug()<< Img_of_books[i]->height();
                    qDebug()<< Like_buttons[i]->height();
                    qDebug()<< Download_buttons[i]->height();
                    y+=Names_of_books[i]->height()+Img_of_books[i]->height()+Like_buttons[i]->height()+Download_buttons[i]->height()+20;
                }
            }
            y=0;
            if(book.author.contains(text)){
                for (int i = 0; i < Names_of_books.size(); ++i) {
                    if (Names_of_books[i]->text().contains(book.title, Qt::CaseInsensitive)) {

                        ui->scrollArea->verticalScrollBar()->setValue(y);
                        return;
                    }
                    y+=Names_of_books[i]->height()+Img_of_books[i]->height()+Like_buttons[i]->height()+Download_buttons[i]->height();
                }
            }



        }
    }

}
void List_books::Fill_books(){
    QFile file("C:/Users/Andrew/Documents/library/Books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
        return;
    }
    QTextStream in(&file);
    QString genre;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.contains(":")){
            line.chop(-1);
            genre=line;
        }
        else{
            QStringList parts = line.split(" by ");
            if (parts.size() == 2) {
                QString title = parts[0].mid(1, parts[0].size() - 2);
                QString author = parts[1];

                genreBooks[genre].append(Book(title, author));
            }
        }
    }

    file.close();
    for (const auto& genre : genreBooks.keys()) {
        qDebug() << "Genre:" << genre;
            const QList<Book>& booksInGenre = genreBooks[genre];
        for (const Book& book : booksInGenre) {
            qDebug() << "  Book:" << book.title << "Author:" << book.author;
        }
    }
}
void List_books::Fill_area()
{

    for (const auto& genre : genreBooks.keys()) {
        const QList<Book>& booksInGenre = genreBooks[genre];
        for (const Book& book : booksInGenre) {
            number_of_favorite++;
            BookName = new QLabel( this);
            BookName->setGeometry(9, 9, 266,63);
            Bookimg = new QLabel( this);
            Bookimg->setGeometry(9, 39,266,277);
            BookName->setText(book.title);
            QString name=book.title;
            qDebug()<<":/img/picture/"+name+".jpg";
            QPixmap Img(":/img/picture/"+name+".jpg");
            Bookimg->setPixmap(Img);
            QPushButton* Open_button = new QPushButton("Download", this);
            QPushButton* Like_button = new QPushButton("Like", this);
            connect(Like_button, &QPushButton::clicked, this, &List_books::Like_Buttonclicked);
            connect(Open_button, &QPushButton::clicked, this, &List_books::Open_Buttonclicked);
            Names_of_books.push_back(BookName);
            Img_of_books.push_back(Bookimg);
            Download_buttons.push_back(Open_button);
            Like_buttons.push_back(Like_button);


        }
    }
    QWidget* contentWidget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout(contentWidget);
    for(int number=0; number<number_of_favorite;number++){
        qDebug() <<"start";
        Download_buttons[number]->setStyleSheet("QPushButton {"
                                            "   background-color: #4CAF50;"
                                            "   border: none;"
                                            "   color: white;"
                                            "   padding: 10px 20px;"
                                            "   text-align: center;"
                                            "   text-decoration: none;"
                                            "   display: inline-block;"
                                            "   font-size: 16px;"
                                            "   margin: 4px 2px;"
                                            "   cursor: pointer;"
                                            "}"
                                            "QPushButton:hover {"
                                            "   background-color: #45a049;"
                                            "}");

        Like_buttons[number]->setStyleSheet("QPushButton {"
                                              "   background-color: #f44336;"
                                              "   border: none;"
                                              "   color: white;"
                                              "   padding: 10px 20px;"
                                              "   text-align: center;"
                                              "   text-decoration: none;"
                                              "   display: inline-block;"
                                              "   font-size: 16px;"
                                              "   margin: 4px 2px;"
                                              "   cursor: pointer;"
                                              "}"
                                              "QPushButton:hover {"
                                              "   background-color: #d32f2f;"
                                              "}");

        // Вы можете также добавить стили для текста и других элементов по аналогии
        Names_of_books[number]->setStyleSheet("QLabel { color: #333; font-size: 14px; }");
        layout->addWidget(Names_of_books[number]);
        layout->addWidget(Img_of_books[number]);
        layout->addWidget(Download_buttons[number]);
        layout->addWidget(Like_buttons[number]);
        qDebug()<<"end";
    }
    ui->scrollArea->setWidget(contentWidget);
    ui->scrollArea->viewport()->update();
}
void List_books::Open_Buttonclicked(){
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
void List_books::Like_Buttonclicked(){

    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());

    int index = Like_buttons.indexOf(senderButton);
    qDebug()<<index;


    int size_name[2];
    int size_img[2];
    QLabel *bookLabel = Names_of_books[index];
    qDebug() << Names_of_books[index]->text();
    // Если соответствующий QLabel найден, получаем его размеры
    if (bookLabel) {
        qDebug() <<Names_of_books[index]->width();
        qDebug()<<Names_of_books[index]->height();
        qDebug()<< ui->scrollArea->width();
        qDebug()<< ui->scrollArea->width();
        size_name[0] = Names_of_books[index]->width();
        size_name[1] = Names_of_books[index]->height();
        size_img[0] = ui->scrollArea->width(); // Используем ширину scrollArea
        size_img[1] =  ui->scrollArea->width(); // Используем высоту scrollArea
        liked->setLabelText(Names_of_books[index]->text(), Names_of_books[index]->text(), size_name, size_img);

        QFile file_saves("C:/Users/Andrew/Documents/library/Accaunts_saves.txt");


        if (file_saves.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file_saves);
            out <<Names_of_books[index]->text()<<", ";
            file_saves.close();
        } else {
            qDebug() << "Ошибка открытия файла для добавления названия книги: " << file_saves.errorString();
        }
    }
}
