#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "encryption.h"
#include "decode.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_continue_clicked();

private:
    Ui::MainWindow *ui;
    Encryption* encryption;
    Decode* decode;
};

#endif // MAINWINDOW_H
