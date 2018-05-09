#include "encryption.h"
#include "ui_encryption.h"

Encryption::Encryption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Encryption)
{
    ui->setupUi(this);

    ui->lineEditWord->setValidator(new QRegExpValidator(getValidWord(), this));
    ui->lineEditKey->setValidator(new QRegExpValidator(getValidWord(), this));
}

Encryption::~Encryption()
{
    delete ui;
}

void Encryption::on_pushButton_encryption_clicked()
{
    if(fieldsIsFill(this))
    {
        std::vector<QString> vec;
        createVigenereTable(vec);
        QString result = encryption(vec, ui->lineEditWord->text(), ui->lineEditKey->text());
        QMessageBox::information(this, "Шифрование слова", result);
    }
    else
    {
        QMessageBox::warning(this, "Ошибка!", "Заполните все поля!");
    }


}
