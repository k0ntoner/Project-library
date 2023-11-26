#include "liked.h"
#include "ui_liked.h"
#include <QPixmap>
#include <QGridLayout>
#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include<QPushButton>
Liked::Liked(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Liked)
{

    ui->setupUi(this);
}

Liked::~Liked()
{
    delete ui;

}
void Liked::setLabelText(const QString &text, const QString &book_name,int size_bookname[],int size_bookimg[])
{
    number_of_favorite++;
    BookName = new QLabel( this);
    qDebug() <<size_bookname[0];
    qDebug() <<size_bookname[1];
    qDebug() <<size_bookimg[0];
    qDebug() <<size_bookimg[1];
    BookName->setGeometry(9, 9, size_bookname[0], size_bookname[1]);
    Bookimg = new QLabel( this);
    Bookimg->setGeometry(9, 39, size_bookimg[0], size_bookimg[1]);
    if(book_name=="Harry"){
        BookName->setText("Harry Potter and the Philosopher's Stone");
        QPixmap Harry(":/img/picture/Harry Potter and the Philosopher's Stone.jpg");
        Bookimg->setPixmap(Harry);
    }
    if(book_name=="Crime"){
        BookName->setText("Crime and Punishment");
        QPixmap Crime(":/img/picture/Crime and Punishment.jpg");
        Bookimg->setPixmap(Crime);
    }
    if(book_name=="War"){
        BookName->setText("War and Peace");
        QPixmap War_and_Peace(":/img/picture/War and Peace.jpg");
        Bookimg->setPixmap(War_and_Peace);
    }
    if(book_name=="Thrones"){
        BookName->setText("Game_of_throne");
        QPixmap Game_of_throne(":/img/picture/A Game of Thrones.jpg");
        Bookimg->setPixmap(Game_of_throne);
    }
    if(book_name=="Narnia"){
        BookName->setText("The Chronicles of Narnia");
        QPixmap Narnia(":/img/picture/The Chronicles of Narnia.jpg");
        Bookimg->setPixmap(Narnia);
    }
    if(book_name=="Margarita"){
        BookName->setText("The Master and Margarita");
        QPixmap Margarita(":/img/picture/The Master and Margarita.jpg");
        Bookimg->setPixmap(Margarita);
    }
    if(book_name=="Galaxy"){
        BookName->setText("The Hitchhiker's Guide to the Galaxy");
        QPixmap Galaxy(":/img/picture/The Hitchhiker's Guide to the Galaxy.jpg");
        Bookimg->setPixmap(Galaxy);
    }
    QPushButton* Open_button = new QPushButton("Open", this);
    QPushButton* Delete_button = new QPushButton("Delete", this);
    connect(Delete_button, &QPushButton::clicked, this, &Liked::onDeleteButtonClicked);
    connect(Open_button, &QPushButton::clicked, this, &Liked::Open_Book);
    BookNames.push_back(BookName);
    BookImgs.push_back(Bookimg);
    Open_buttons.push_back(Open_button);
    Delete_buttons.push_back(Delete_button);
    QWidget* contentWidget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout(contentWidget);
    for(int number=0; number<number_of_favorite;number++){
        qDebug() <<"start";
        Open_buttons[number]->setStyleSheet("QPushButton {"
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

        Delete_buttons[number]->setStyleSheet("QPushButton {"
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
        BookNames[number]->setStyleSheet("QLabel { color: #333; font-size: 14px; }");
        layout->addWidget(BookNames[number]);
        layout->addWidget(BookImgs[number]);
        layout->addWidget(Open_buttons[number]);
        layout->addWidget(Delete_buttons[number]);
        qDebug()<<"end";
    }
    ui->scrollArea->setWidget(contentWidget);
    ui->scrollArea->viewport()->update();

}
void Liked::onDeleteButtonClicked() {
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());

    int index = Delete_buttons.indexOf(senderButton);

    if (index >= 0 && index < BookNames.size()) {
        delete BookNames[index];
        delete BookImgs[index];
        delete Open_buttons[index];
        delete Delete_buttons[index];

        BookNames.remove(index);
        BookImgs.remove(index);
        Open_buttons.remove(index);
        Delete_buttons.remove(index);


        updateUI();
    }
}
void Liked::Open_Book(){
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    int index_of_book = Open_buttons.indexOf(senderButton);
    if(BookNames[index_of_book]->text()=="Harry Potter and the Philosopher's Stone"){
        Harry_book= new Harry_Potter__Stone(this);
        Harry_book->show();
    }
    if(BookNames[index_of_book]->text()=="Crime and Punishment"){
        crime_book= new Crime_and_Punishment(this);
        crime_book->show();
    }
    if(BookNames[index_of_book]->text()=="A Game of Thrones"){
        Thrones=new A_Game_of_Thrones(this);
        Thrones->show();
    }
    if(BookNames[index_of_book]->text()=="The Master and Margarita"){
        margarita= new Margarita(this);
        margarita->show();
    }
    if(BookNames[index_of_book]->text()=="Crime and Punishment"){
        war=new War_and_Peace(this);
        war->show();
    }
    if(BookNames[index_of_book]->text()=="The Hitchhiker's Guide to the Galaxy"){
        galaxy=new Galaxy(this);
        galaxy->show();
    }
    if(BookNames[index_of_book]->text()=="The Chronicles of Narnia"){
        narnia=new Narnia(this);
        narnia->show();
    }
    if(BookNames[index_of_book]->text()=="War and Peace"){
        war=new War_and_Peace(this);
        war->show();
    }

}
void Liked::updateUI() {
    QWidget* contentWidget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout(contentWidget);
    for (int number = 0; number < BookNames.size(); number++) {
        layout->addWidget(BookNames[number]);
        layout->addWidget(BookImgs[number]);
        layout->addWidget(Open_buttons[number]);
        layout->addWidget(Delete_buttons[number]);
    }

    ui->scrollArea->setWidget(contentWidget);
    ui->scrollArea->viewport()->update();
}
