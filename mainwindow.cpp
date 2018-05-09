#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}

void MainWindow::on_pushButton_continue_clicked()
{
    if(ui->radioEncryption->isChecked())
    {
        hide();
        encryption = new Encryption;
        encryption->setModal(true);
        encryption->exec();
    }
    else if(ui->radioDecode->isChecked())
    {
        hide();
        decode = new Decode;
        decode->setModal(true);
        decode->exec();
    }
}


