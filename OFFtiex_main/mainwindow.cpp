#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <fstream>

QString type_of_publication;
QStringList genres;

struct Book
{
    QString author_;
    QString name_;
    QString id_;
    QString filling_;
    QString type_;
    QStringList genres_;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->saveButton->setStyleSheet("background-color: green;");
    ui->resetButton->setStyleSheet("background-color: red;");
    publicationGroup = new QButtonGroup(this);
    publicationGroup->addButton(ui->paper_button, 0);
    publicationGroup->addButton(ui->electronic_button, 1);
    publicationGroup->setExclusive(true);

    // ui->paper_button->setChecked(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveButton_clicked()
{
    bool is_correct = true;
    QString text = ui->name_text->text();
    if (text.isEmpty()){
        qInfo() << "Book`s name is empty";
        return;
    }
    if (text[0] != u'"' || text[text.length()-1] != u'"'){
        qInfo() << "Book`s name must be with  “...”";
        is_correct = false;
    }

    text = ui->author_text->text();
    if (text.isEmpty()){
        qInfo() << "Author`s name is empty";
        return;
    }
    for (int i = 0; i < text.length()-1; i++){
        int letter_uncode = text[i].unicode();
        if ((letter_uncode < 1040 || letter_uncode > 1103) && (letter_uncode != 1025 && letter_uncode != 1105)){ // Проверка на русские буквы и ё
            if (letter_uncode != 32){                                                                            // Проверка на пробел
                qInfo() <<  "There are only russian letters in the author`s name";
                is_correct = false;
                break;
            }
        }
    }
    QStringList words = text.split(' ', Qt::SkipEmptyParts);
    if (words.size() != 2){
        qInfo() << "The author`s full name must consist of two words";
        is_correct = false;
    }
    else {
        QString word1 = words[0];
        QString word2 = words[1];
        int word1_unicode = word1[0].unicode();
        if ((word1_unicode  > 1071 || word1_unicode < 1040) && (word1_unicode != 1025)){                        // Проверка на заглавные русские буквы
            qInfo() << "The first letter of author`s name must be capital";
            is_correct = false;
        }
        if (word2.length() > 2){
            qInfo() << "The leght of the second word of the author`s name must be 2";
            is_correct = false;
        }
        for (int i = 0; i < word2.length(); i++){
            int word2_unicode = word2[i].unicode();
            if ((word2_unicode  > 1071 || word2_unicode < 1040) && (word2_unicode != 1025)){                        // Проверка на заглавные русские буквы
                qInfo() << "The second word of author`s name must consist of capital letters";
                is_correct = false;
            }
        }

    }
    text = ui->id_text->text();
    auto is_dash = std::find(text.begin(),text.end(),'-');
    if (is_dash == text.begin() || is_dash == text.end()-1){
        qInfo() << "Dash must include inside the ID";
        is_correct = false;
    }
    else {
        text.erase(is_dash);
        for (int i = 0; i < text.length(); i++){
            int text_unicode = text[i].unicode();
            if (text_unicode > 57 || text_unicode < 48){                                                                // Проверка на цифры
                qInfo() << "The ID must consist only of digits and dash";
                is_correct = false;
            }
        }
    }

    text = ui->book_filling->text();
    auto is_splitter = std::find(text.begin(),text.end(),'/');
    if (is_splitter == text.begin() || is_splitter == text.end()-1){
        qInfo() << "Splitter must include inside the filling of the book";
        is_correct = false;
    }
    else {
        text.erase(is_splitter);
        for (int i = 0; i < text.length(); i++){
            int text_unicode = text[i].unicode();
            if (text_unicode > 57 || text_unicode < 48){                                                                // Проверка на цифры
                qInfo() << "The filling of the book must consist only of digits and splitter";
                is_correct = false;
            }
        }
    }
    text = ui->book_filling->text();
    QStringList numbers = text.split('/', Qt::SkipEmptyParts);
    if (numbers.size()!= 2){
        qInfo() << "The filling of the book must consist of two numbers";
        is_correct = false;
    }
    else {
        int number1 = numbers[0].toInt();
        int number2 = numbers[1].toInt();
        if (number1 <= number2){
            qInfo() << "The second number must be less than the first number";
            is_correct = false;
        }
    }


    qInfo() << type_of_publication;

    if (is_correct){
        Book book1;
        book1.author_ = ui->author_text->text();
        book1.name_ = ui->name_text->text();
        book1.id_ = ui->id_text->text();
        book1.filling_ = ui->book_filling->text();
        book1.type_ = type_of_publication;
        book1.genres_ = genres;

        std::ofstream result("C:\\Users\\geram\\Desktop\\result.txt");
        if (result.is_open()){
            result << "========================\n";
            result << "Book:\n";
            result << "Author: " << book1.author_.toStdString() << "\n";
            result << "Name: " << book1.name_.toStdString() << "\n";
            result << "ID: " << book1.id_.toStdString() << "\n";
            result << "Filling: " << book1.filling_.toStdString() << "\n";
            result << "Type: " <<book1.type_.toStdString() << "\n";
            result << "Genres: \n";
            for (int i = 0; i < book1.genres_.length(); i++){
                result << book1.genres_[i].toStdString() << "\n";
            }
            qInfo() << "All is good";
        }
        else {
            qInfo() << "File is not open";
        }
    }
    else{
        return;
    }

}


void MainWindow::on_resetButton_clicked()
{
    ui->author_text->clear();
    ui->name_text->clear();
    ui->id_text->clear();
    ui->book_filling->clear();

    publicationGroup->setExclusive(false);
    ui->paper_button->setChecked(false);
    ui->electronic_button->setChecked(false);
    publicationGroup->setExclusive(true);
}




void MainWindow::on_author_text_textChanged(const QString &arg1)
{

}


void MainWindow::on_name_text_textChanged(const QString &arg1)
{

}


void MainWindow::on_id_text_textChanged(const QString &arg1)
{

}


void MainWindow::on_book_filling_textChanged(const QString &arg1)
{

}

void MainWindow::on_paper_button_clicked()
{
    type_of_publication = ui->paper_button->text();
}


void MainWindow::on_electronic_button_toggled(bool checked)
{
    type_of_publication = ui->electronic_button->text();
}





void MainWindow::on_genre1_checkBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        genres.append(ui->genre1_checkBox->text());
    }
}


void MainWindow::on_genre2_checkBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        genres.append(ui->genre2_checkBox->text());
    }
}


void MainWindow::on_genre3_checkBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        genres.append(ui->genre3_checkBox->text());
    }
}

