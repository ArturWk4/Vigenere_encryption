#include "logic.h"

bool fieldsIsFill(QWidget* form)
{
    QList<QLineEdit*> fields = form->findChildren<QLineEdit*>();
    for(auto i : fields)
    {
        if(i->text().isEmpty())
            return false;
    }
    return true;
}

QRegExp getValidWord()
{
    return QRegExp("[a-z]+");
}

void fillAlphabet(QString &alphabet)
{
    for(char i = 'a'; i <= 'z'; ++i)
    {
        alphabet.push_back(i);
    }
}

void createVigenereTable(std::vector<QString> &english_table)
{
    QString temp;
    fillAlphabet(temp);
    for(int i = 0; i < 26; ++i)
    {
        english_table.push_back(temp);
        std::rotate(temp.begin(), temp.begin()+1, temp.end());
    }
}


QString completeKey(QString& key, int word_size)
{
    QString temp = key;
    int key_size = key.size();
    int temp_size = temp.size();

    for(; temp_size < word_size;)
    {
        for(int i = 0; i < key_size; ++i)
        {
            if(temp_size == word_size)
                break;
            temp.push_back(key[i]);
            ++temp_size;
        }
    }
    return temp;
}

int findWordIndex(const QString &str, QChar value)
{
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == value)
            return i;
    }
    return -1;
}

QString encryption(std::vector<QString> table, QString word, QString _key)
{
    QString key = completeKey(_key, word.size());
    QString result;
    int word_size = word.size();
    int word_index = 0;
    int key_index = 0;

    for(int i = 0; i < word_size; ++i)
    {
        word_index = findWordIndex(table.at(0), word.at(i));
        key_index = findWordIndex(table.at(0), key.at(i));
        result.push_back( table.at(key_index).at(word_index) );
    }
    return result;
}
