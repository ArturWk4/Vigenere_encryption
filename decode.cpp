#include "decode.h"
#include "ui_decode.h"

Decode::Decode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Decode)
{
    ui->setupUi(this);
    ui->lineEditCode->setValidator(new QRegExpValidator(getValidWord(), this));
    ui->lineEditKey->setValidator(new QRegExpValidator(getValidWord(), this));
}

Decode::~Decode()
{
    delete ui;
}

void Decode::on_pushButton_decode_clicked()
{
    if(fieldsIsFill(this))
    {
        std::vector<QString> table;
        createVigenereTable(table);
        QString result = decode(table, ui->lineEditCode->text(), ui->lineEditKey->text());
        QMessageBox::information(this, "Дешифрование", result);
    }
    else
    {
        QMessageBox::warning(this, "Ошибка!", "Заполните все поля!");
    }
}
