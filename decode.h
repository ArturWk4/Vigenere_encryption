#ifndef DECODE_H
#define DECODE_H
#include <QDialog>
#include <QMessageBox>
#include "logic.h"
#include <vector>

namespace Ui {
class Decode;
}

class Decode : public QDialog
{
    Q_OBJECT

public:
    explicit Decode(QWidget *parent = 0);
    ~Decode();

private slots:
    void on_pushButton_decode_clicked();

private:
    Ui::Decode *ui;
};

#endif // DECODE_H
