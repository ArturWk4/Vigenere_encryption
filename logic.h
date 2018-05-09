#ifndef LOGIC_H
#define LOGIC_H
#include <QLineEdit>
#include <QRegExp>
#include <QString>
#include <algorithm>
#include <vector>



bool fieldsIsFill(QWidget* form);

QRegExp getValidWord();

void fillAlphabet(QString& alphabet);
void createVigenereTable(std::vector<QString>& english_table);

QString completeKey( QString& key, const int word_size);
int findWordIndex(const QString& str, QChar value);
QString encryption(std::vector<QString> table, QString word, QString _key);

#endif // LOGIC_H
