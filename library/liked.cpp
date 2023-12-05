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
#include<QFile>
#include <QMessageBox>
#include "open.h"
Liked::Liked(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Liked)
{

    ui->setupUi(this);
    setWindowTitle("Favorite Books");

}

Liked::~Liked()
{

    delete ui;

}
int Liked::setLabelText(const QString &text, const QString &book_name,int size_bookname[],int size_bookimg[])
{
    if(number_of_favorite>0){
        for(int i=0; i<number_of_favorite;i++){
            qDebug()<<BookNames[i]->text();
            if(text==BookNames[i]->text()){

                return 0;
            }
        }
    }
    qDebug()<<number_of_favorite;
    number_of_favorite++;

    BookName = new QLabel( this);
    BookName->setGeometry(9, 9, size_bookname[0], size_bookname[1]);
    Bookimg = new QLabel( this);
    Bookimg->setGeometry(9, 39, size_bookimg[0], size_bookimg[1]);
    BookName->setText(text);
    QPixmap Harry(":/img/picture/"+text+".jpg");
    Bookimg->setPixmap(Harry);

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
    return 1;

}
void Liked::onDeleteButtonClicked()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());

    int index = Delete_buttons.indexOf(senderButton);

    if (index >= 0 && index < BookNames.size()) {
        QFile file("C:/Users/Andrew/Documents/library/Accaunts_saves.txt");
        if (file.open(QIODevice::ReadWrite| QIODevice::Text)) {


            // Считываем файл построчно
            QTextStream in(&file);
            QString Email=in.readLine();
            QString Password=in.readLine();
            QString line = in.readLine();

            // Ищем строку, начинающуюся с "Saves:"
            if (line.startsWith("Saves:")) {
                    int bookIndex = line.indexOf(BookNames[index]->text());
                    int commaIndex = line.indexOf(',', bookIndex);
                    int endBookIndex = (commaIndex != -1) ? commaIndex : line.indexOf("\n");
                    line.remove(bookIndex, endBookIndex - bookIndex+2);

            }
            file.seek(0);

            // Очищаем содержимое файла
            file.resize(0);
            QTextStream out(&file);
            out<<Email<<"\n";
            out<<Password<<"\n";
            out<<line<<"\n";
        }
        delete BookNames[index];
        delete BookImgs[index];
        delete Open_buttons[index];
        delete Delete_buttons[index];

        BookNames.remove(index);
        BookImgs.remove(index);
        Open_buttons.remove(index);
        Delete_buttons.remove(index);
        number_of_favorite--;

        updateUI();

    }
}
void Liked::Open_Book(){
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    int index_of_book = Open_buttons.indexOf(senderButton);
    if(BookNames[index_of_book]->text()=="Harry Potter and the Philosopher's Stone"){
        Harry_book= new Harry_Potter__Stone(this);
        Harry_book->show();
        return;
    }
    if(BookNames[index_of_book]->text()=="Crime and Punishment"){
        crime_book= new Crime_and_Punishment(this);
        crime_book->show();
        return;
    }
    if(BookNames[index_of_book]->text()=="A Game of Thrones"){
        Thrones=new A_Game_of_Thrones(this);
        Thrones->show();
        return;
    }
    if(BookNames[index_of_book]->text()=="The Master and Margarita"){
        margarita= new Margarita(this);
        margarita->show();
        return;
    }
    if(BookNames[index_of_book]->text()=="Crime and Punishment"){
        war=new War_and_Peace(this);
        war->show();
        return;
    }
    if(BookNames[index_of_book]->text()=="The Hitchhiker's Guide to the Galaxy"){
        galaxy=new Galaxy(this);
        galaxy->show();
        return;
    }
    if(BookNames[index_of_book]->text()=="The Chronicles of Narnia"){
        narnia=new Narnia(this);
        narnia->show();
        return;
    }
    if(BookNames[index_of_book]->text()=="War and Peace"){
        war=new War_and_Peace(this);
        war->show();
        return;
    }
    else{
        open=new Open(this);
        open->Fill_area(BookNames[index_of_book]->text());
        open->show();
        return;
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
