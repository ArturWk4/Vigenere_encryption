#include "decode.h"
#include "ui_decode.h"

Decode::Decode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Decode)
{
    ui->setupUi(this);
}

Decode::~Decode()
{
    delete ui;
}

void Decode::on_pushButton_decode_clicked()
{
    if(fieldsIsFill(this))
    {

        QMessageBox::information(this, "Дешифрование", "Слово");
    }
    else
    {
        QMessageBox::warning(this, "Ошибка!", "Заполните все поля!");
    }
}
