#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <fstream>
#include <QRegularExpression>
#include <QMessageBox>
QString type_of_publication;
QStringList genres;

class Book {
public:
    QString author_;
    QString name_;
    QString id_;
    QString filling_;
    QString type_;
    QStringList genres_;
    Book(QString author, QString name, QString id, QString filling, QString type, QStringList genres) : author_(author), name_(name), id_(id),
        filling_(filling), type_(type), genres_(genres) {

    }
    void save_file(Book book1){
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
            result.close();
        }
        else {
            QMessageBox::critical(nullptr, "Error", "File is not open");
        }
    }
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


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveButton_clicked()
{
    bool is_correct = true;
    QString text = ui->name_text->text();
    QRegularExpression nameRegex("^.*\"$");
    if (text.isEmpty()){
        QMessageBox::critical(nullptr, "Error", "Book`s name is empty");
        return;
    }
    if (!nameRegex.match(text).hasMatch()){
        QMessageBox::critical(nullptr, "Error", "Book`s name must be with \"...\"");
        is_correct = false;
    }
    text = ui->author_text->text();
    if (text.isEmpty()){
        QMessageBox::critical(nullptr, "Error", "Author`s name is empty");
        return;
    }

    QRegularExpression authorRegex("^[А-ЯЁ][а-яё]+\\s[А-ЯЁ]{1,2}$");
    if (!authorRegex.match(text).hasMatch()){
        QMessageBox::critical(nullptr, "Error", "Author name must consist of: first name (capitalized Russian letters), last name (2 capital Russian letters)");
        is_correct = false;
    }

    QString id = ui->id_text->text();
    QRegularExpression idRegex("^\\d{3}-\\d{5}$");
    if (!idRegex.match(id).hasMatch()){
        QMessageBox::critical(nullptr, "Error", "ID must consist of digits with one dash inside");
        is_correct = false;
    }


    text = ui->book_filling->text();
    QString filling = ui->book_filling->text();
    QRegularExpression fillingRegex("^(\\d+)/(\\d+)$");
    QRegularExpressionMatch match = fillingRegex.match(filling);
    if (!match.hasMatch()){
        QMessageBox::critical(nullptr, "Error", "Filling must consist of two numbers separated by / ");
        is_correct = false;
    }
    else {
        int number1 = match.captured(1).toInt();
        int number2 = match.captured(2).toInt();
        if (number1 <= number2){
            QMessageBox::critical(nullptr, "Error","The second number must be less than the first number");
            is_correct = false;
        }
    }
    if (type_of_publication.size() == 0){
        QMessageBox::critical(nullptr, "Error","Type of publication is required");
        is_correct = false;
    }



    if (is_correct){
        QString author = ui->author_text->text();
        QString name = ui->name_text->text();
        QString id = ui->id_text->text();
        QString filling = ui->book_filling->text();
        QString type = type_of_publication;
        QStringList genres1 = genres;
        Book book1(author, name, id, filling, type, genres1);
        book1.save_file(book1);



        // std::ofstream result("C:\\Users\\geram\\Desktop\\result.txt");
        // if (result.is_open()){
        //     result << "========================\n";
        //     result << "Book:\n";
        //     result << "Author: " << book1.author_.toStdString() << "\n";
        //     result << "Name: " << book1.name_.toStdString() << "\n";
        //     result << "ID: " << book1.id_.toStdString() << "\n";
        //     result << "Filling: " << book1.filling_.toStdString() << "\n";
        //     result << "Type: " <<book1.type_.toStdString() << "\n";
        //     result << "Genres: \n";
        //     for (int i = 0; i < book1.genres_.length(); i++){
        //         result << book1.genres_[i].toStdString() << "\n";
        //     }
        //     qInfo() << "All is good";
        // }
        // else {
        //     qInfo() << "File is not open";
        // }
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

    ui->genre1_checkBox->setChecked(false);
    ui->genre2_checkBox->setChecked(false);
    ui->genre3_checkBox->setChecked(false);
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

