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
Catalog::Catalog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Catalog)
{
    ui->setupUi(this);
    QPixmap Harry(":/img/picture/Harry Potter and the Philosopher's Stone.jpg");
    QPixmap Crime(":/img/picture/Crime and Punishment.jpg");
    QPixmap Game_of_throne(":/img/picture/A Game of Thrones.jpg");
    QPixmap Pride(":/img/picture/Pride and Prejudice.jpg");
    QPixmap Narnia(":/img/picture/The Chronicles of Narnia.jpg");
    QPixmap Galaxy(":/img/picture/The Hitchhiker's Guide to the Galaxy.jpg");
    QPixmap Margarita(":/img/picture/The Master and Margarita.jpg");
    QPixmap War_and_Peace(":/img/picture/War and Peace.jpg");
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
    delete ui;
}
void Catalog::onSearchTextChanged(const QString &text)
{

    for (int i = 0; i < Names_of_books.size(); ++i) {
        if (Names_of_books[i]->text().contains(text, Qt::CaseInsensitive)) {
            // Book found, move the scroll area to its position
            int y = i * Names_of_books[i]->height(); // Adjust this based on your layout
            ui->scrollArea_2->verticalScrollBar()->setValue(y);
            return;
        }
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

void Catalog::on_Harry_like_clicked()
{
    if(liked_open==0){
        liked=new Liked(this);
        liked->show();
        liked_open=true;
    }
    QString book=ui->Harry->text();
    int size_name[2];
    int size_img[2];
    size_name[0]=ui->Harry->width();
    size_name[1]=ui->Harry->height();
    size_img[0]=ui->Harry_img->width();
    size_img[1]= ui->Harry_img->height();
    liked->setLabelText(book,"Harry", size_name,size_img);
}
void Catalog::on_Crime_Like_clicked()
{
    if(liked_open==0){
        liked=new Liked(this);
        liked->show();
        liked_open=true;
    }
    QString book=ui->Crime->text();
    int size_name[2];
    int size_img[2];
    size_name[0]=ui->Crime->width();
    size_name[1]=ui->Crime->height();
    size_img[0]=ui->Crime_img->width();
    size_img[1]= ui->Crime_img->height();
    liked->setLabelText(book,"Crime", size_name,size_img);
}


void Catalog::on_Margarita_Like_clicked()
{
    if(liked_open==0){
        liked=new Liked(this);
        liked->show();
        liked_open=true;
    }
    QString book=ui->Margarita->text();
    int size_name[2];
    int size_img[2];
    size_name[0]=ui->Margarita->width();
    size_name[1]=ui->Margarita->height();
    size_img[0]=ui->Margarita_img->width();
    size_img[1]= ui->Margarita_img->height();
    liked->setLabelText(book,"Margarita", size_name,size_img);
}


void Catalog::on_War_like_clicked()
{
    if(liked_open==0){
        liked=new Liked(this);
        liked->show();
        liked_open=true;
    }
    QString book=ui->War_and_peace->text();
    int size_name[2];
    int size_img[2];
    size_name[0]=ui->War_and_peace->width();
    size_name[1]=ui->War_and_peace->height();
    size_img[0]=ui->War_and_peace_img->width();
    size_img[1]= ui->War_and_peace_img->height();
    liked->setLabelText(book,"War", size_name,size_img);
}


void Catalog::on_Thrones_Like_clicked()
{
    if(liked_open==0){
        liked=new Liked(this);
        liked->show();
        liked_open=true;
    }
    QString book=ui->Thrones->text();
    int size_name[2];
    int size_img[2];
    size_name[0]=ui->Thrones->width();
    size_name[1]=ui->Thrones->height();
    size_img[0]=ui->Thrones_img->width();
    size_img[1]= ui->Thrones_img->height();
    liked->setLabelText(book,"Thrones", size_name,size_img);
}


void Catalog::on_Galaxy_LIke_clicked()
{
    if(liked_open==0){
        liked=new Liked(this);
        liked->show();
        liked_open=true;
    }
    QString book=ui->Galaxy->text();
    int size_name[2];
    int size_img[2];
    size_name[0]=ui->Galaxy->width();
    size_name[1]=ui->Galaxy->height();
    size_img[0]=ui->Galaxy_img->width();
    size_img[1]= ui->Galaxy_img->height();
    liked->setLabelText(book,"Galaxy", size_name,size_img);
}


void Catalog::on_Narnia_Like_clicked()
{
    if(liked_open==0){
        liked=new Liked(this);
        liked->show();
        liked_open=true;
    }
    QString book=ui->Narnia->text();
    int size_name[2];
    int size_img[2];
    size_name[0]=ui->Narnia->width();
    size_name[1]=ui->Narnia->height();
    size_img[0]=ui->Narnia_img->width();
    size_img[1]= ui->Narnia_img->height();
    liked->setLabelText(book,"Narnia", size_name,size_img);
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



