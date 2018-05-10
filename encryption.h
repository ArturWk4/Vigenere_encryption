#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <QDialog>
#include <QMessageBox>
#include "logic.h"
#include <vector>

namespace Ui {
class Encryption;
}

class Encryption : public QDialog
{
    Q_OBJECT

public:
    explicit Encryption(QWidget *parent = 0);
    ~Encryption();

private slots:
    void on_pushButton_encryption_clicked();

private:
    Ui::Encryption *ui;
};

#endif // ENCRYPTION_H
