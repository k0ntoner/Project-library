#include "catalog.h"
#include "ui_catalog.h"
#include <QTimer>
#include <QPixmap>
#include <QLabel>
#include <QDateTime>
#include <QTime>
#include <QScrollBar>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
Catalog::Catalog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Catalog)
{
    ui->setupUi(this);
    setWindowTitle("Recomended");
    QPixmap Harry(":/img/picture/Harry Potter and the Philosopher's Stone.jpg");
    QPixmap Crime(":/img/picture/Crime and Punishment.jpg");
    QPixmap Game_of_throne(":/img/picture/A Game of Thrones.jpg");
    QPixmap Pride(":/img/picture/Pride and Prejudice.jpg");
    QPixmap Narnia(":/img/picture/The Chronicles of Narnia.jpg");
    QPixmap Galaxy(":/img/picture/The Hitchhiker's Guide to the Galaxy.jpg");
    QPixmap Margarita(":/img/picture/The Master and Margarita.jpg");
    QPixmap War_and_Peace(":/img/picture/War and Peace.jpg");
    QFile file_saves("C:/Users/Andrew/Documents/library/Accaunts_saves.txt");
    if (file_saves.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream in(&file_saves);
        fileContent = in.readAll();
        file_saves.close();
    }

    ui->Harry_img->setPixmap(Harry);
    ui->Crime_img->setPixmap(Crime);
    ui->Thrones_img->setPixmap(Game_of_throne);
    ui->Narnia_img->setPixmap(Narnia);
    ui->Galaxy_img->setPixmap(Galaxy);
    ui->Margarita_img->setPixmap(Margarita);
    ui->War_and_peace_img->setPixmap(War_and_Peace);

    Names_of_books.push_back(new QLabel("Harry Potter and the Philosopher's Stone"));
    Names_of_books.push_back(new QLabel("Crime and Punishment"));
    Names_of_books.push_back(new QLabel("The Master and Margarita"));
    Names_of_books.push_back(new QLabel("War and Peace"));
    Names_of_books.push_back(new QLabel("A Game of Thrones"));
    Names_of_books.push_back(new QLabel("The Hitchhiker's Guide to the Galaxy"));
    Names_of_books.push_back(new QLabel("The Chronicles of Narnia"));
    Search_of_books.push_back(ui->Harry);
    Search_of_books.push_back(ui->Crime);
    Search_of_books.push_back(ui->Margarita);
    Search_of_books.push_back(ui->War_and_peace);
    Search_of_books.push_back(ui->Thrones);
    Search_of_books.push_back(ui->Galaxy);
    Search_of_books.push_back(ui->Narnia);
    Img_of_books.push_back(ui->Harry_img);
    Img_of_books.push_back(ui->Crime_img);
    Img_of_books.push_back(ui->Margarita_img);
    Img_of_books.push_back(ui->War_and_peace_img);
    Img_of_books.push_back(ui->Thrones_img);
    Img_of_books.push_back(ui->Galaxy_img);
    Img_of_books.push_back(ui->Narnia_img);
    Like_buttons.push_back(ui->Harry_like);
    Like_buttons.push_back(ui->Crime_Like);
    Like_buttons.push_back(ui->Margarita_Like);
    Like_buttons.push_back(ui->War_like);
    Like_buttons.push_back(ui->Thrones_Like);
    Like_buttons.push_back(ui->Galaxy_LIke);
    Like_buttons.push_back(ui->Narnia_Like);
    addSavesLiked();
    for (QPushButton* likeButton : Like_buttons) {
        connect(likeButton, &QPushButton::clicked, this, [=]() {
            qDebug() << "Button clicked:" << likeButton->text();
            onLikeButtonClicked(likeButton->text());
        });
    }
    current_time = new QTimer(this);
    connect( current_time, SIGNAL(timeout()), this, SLOT(timerTick()));
    current_time->start(1000);
    QDateTime currentDateTime = QDateTime::currentDateTime();
    currentTime = currentDateTime.time();
    currentDate = currentDateTime.date();
    ui->Time->setText(currentTime.toString("hh:mm:ss"));
    ui->Data->setText(currentDate.toString("yyyy-MM-dd"));
    connect(ui->Find, &QPushButton::clicked, this, [=]() {
        onSearchTextChanged(ui->line_for_find->text());
    });
}

Catalog::~Catalog()
{
    clearFile("C:/Users/Andrew/Documents/library/Accaunts_saves.txt");
    delete ui;
}
void Catalog::addSavesLiked(){
    QFile files("C:/Users/Andrew/Documents/library/Books.txt");
    if (!files.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
        return;
    }
    QTextStream in(&files);
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

    files.close();
    for (const auto& genre : genreBooks.keys()) {
        qDebug() << "Genre:" << genre;
        const QList<Book>& booksInGenre = genreBooks[genre];
        for (const Book& book : booksInGenre) {
            qDebug() << "  Book:" << book.title << "Author:" << book.author;
            Names_of_books.push_back(new QLabel(book.title));
        }
    }
    QStringList savedBooks;
    if (liked_open == 0) {
        liked = new Liked(this);
        liked->show();
        liked_open = true;
    }
    // Открываем файл для чтения
    QFile file("C:/Users/Andrew/Documents/library/Accaunts_saves.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {


        // Считываем файл построчно
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();

            // Ищем строку, начинающуюся с "Saves:"
            if (line.startsWith("Saves:")) {
                // Извлекаем названия книг после "Saves:"
                QString savesLine = line.mid(6).trimmed();
                savedBooks = savesLine.split(", ", Qt::SkipEmptyParts);
                break;  // Мы нашли нужную строку, выходим из цикла
            }
        }
        for (int i=0;i<savedBooks.size();i++) {
            if(i==savedBooks.size()-1){
                savedBooks[i].chop(1); // Удаляем последний символ
            }
            qDebug()<<savedBooks[i];
        }
        for (const QString& book : savedBooks) {
            for(int index=0; index<Names_of_books.size();++index){
                qDebug()<< book;
                qDebug()<<Names_of_books[index]->text();
                if(book==Names_of_books[index]->text()){
                    int size_name[2];
                    int size_img[2];
                    QLabel *bookLabel = Names_of_books[index];
                    qDebug() << Names_of_books[index]->text();
                    // Если соответствующий QLabel найден, получаем его размеры
                    if (bookLabel) {
                        size_name[0] = Names_of_books[index]->width();
                        size_name[1] = Names_of_books[index]->height();
                        size_img[0] = ui->scrollArea_2->width(); // Используем ширину scrollArea
                        size_img[1] = ui->scrollArea_2->height(); // Используем высоту scrollArea
                        liked->setLabelText(Names_of_books[index]->text(), Names_of_books[index]->text(), size_name, size_img);
                    }
                }
            }
        }
        // Закрываем файл
        file.close();
    }
}
void Catalog::onSearchTextChanged(const QString &text)
{
    int y=0;
    for (int i = 0; i < Search_of_books.size(); ++i) {
        qDebug()<<Search_of_books[i]->height();
        qDebug()<<Img_of_books[i]->height();

        if (Names_of_books[i]->text().contains(text, Qt::CaseInsensitive)) {
            ui->scrollArea_2->verticalScrollBar()->setValue(y);
            return;
        }
        y+=Search_of_books[i]->height()+Img_of_books[i]->height();
    }
}
void Catalog::replaceLinesInFile(const QString &searchText, const QString &replaceText){
    QFile file("C:/Users/Andrew/Documents/library/Accaunts.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла: " << file.errorString();
            return;
    }

    // Считываем весь текстовый файл
    QTextStream in(&file);
    QString fileContent = in.readAll();

    // Заменяем необходимые строки
    fileContent.replace(searchText, replaceText);

    // Перемещаем указатель файла в начало
    file.seek(0);

    // Очищаем содержимое файла
    file.resize(0);

    // Записываем обновленный текст обратно в файл
    QTextStream out(&file);
    out << fileContent;

    // Закрываем файл
    file.close();
}
void Catalog::clearFile(const QString &filePath){
    QFile file_saves(filePath);
    if(file_saves.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream in(&file_saves);
            fileContent_saves = in.readAll();
            file_saves.close();
    }
    if (file_saves.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
            file_saves.close();
    } else {
            qDebug() << "Ошибка открытия файла для очистки: " << file_saves.errorString();
    }

    QFile file("C:/Users/Andrew/Documents/library/Accaunts.txt");
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent_main = in.readAll();
            fileContent_main.replace(fileContent, fileContent_saves);
            // Перемещаем указатель файла в начало
            file.seek(0);

            // Очищаем содержимое файла
            file.resize(0);
            QTextStream out(&file);
            out << fileContent_main;
            file.close();
    }

}
void Catalog::timerTick()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    currentTime = currentDateTime.time();
    currentDate = currentDateTime.date();
    ui->Time->setText(currentTime.toString("hh:mm:ss"));
    ui->Data->setText(currentDate.toString("yyyy-MM-dd"));
}

void Catalog::onLikeButtonClicked(const QString &bookName)
{

    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());

    int index = Like_buttons.indexOf(senderButton);
    qDebug()<<index;
    if (liked_open == 0) {
        liked = new Liked(this);
        liked->show();
        liked_open = true;
    }

    int size_name[2];
    int size_img[2];
    QLabel *bookLabel = Names_of_books[index];
    qDebug() << Names_of_books[index]->text();

    // Если соответствующий QLabel найден, получаем его размеры
    if (bookLabel) {
        size_name[0] = Names_of_books[index]->width();
        size_name[1] = Names_of_books[index]->height();
        size_img[0] = ui->scrollArea_2->width(); // Используем ширину scrollArea
        size_img[1] = ui->scrollArea_2->height(); // Используем высоту scrollArea
        int k=liked->setLabelText(Names_of_books[index]->text(), Names_of_books[index]->text(), size_name, size_img);
        if(k==1){
            QFile file_saves("C:/Users/Andrew/Documents/library/Accaunts_saves.txt");
            if (file_saves.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file_saves);
                out <<Names_of_books[index]->text()<<", ";
                qDebug() <<Names_of_books[index]->text();
                file_saves.close();
            } else {
                qDebug() << "Ошибка открытия файла для добавления названия книги: " << file_saves.errorString();
            }
        }


    }
}


void Catalog::on_Open_Harry_clicked()
{
    Harry_book= new Harry_Potter__Stone(this);
    Harry_book->show();
}


void Catalog::on_Open_Crime_clicked()
{
    crime_book= new Crime_and_Punishment(this);
    crime_book->show();
}





void Catalog::on_Open_Margarita_clicked()
{
    margarita= new Margarita(this);
    margarita->show();
}


void Catalog::on_Open_War_clicked()
{
    war=new War_and_Peace(this);
    war->show();
}


void Catalog::on_Open_Thrones_clicked()
{
    Thrones=new A_Game_of_Thrones(this);
    Thrones->show();
}


void Catalog::on_Open_Galaxy_clicked()
{
    galaxy=new Galaxy(this);
    galaxy->show();
}


void Catalog::on_Open_Narnia_clicked()
{
    narnia=new Narnia(this);
    narnia->show();
}




void Catalog::on_FullList_clicked()
{

    listbook = new List_books(this);
    listbook->setLikedInstance(liked);
    listbook->show();

}

