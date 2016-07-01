#ifndef LEXER_H
#define LEXER_H

#include <QString>
#include <QStringList>
#include <iostream>
#include <string>
#include <QRegExp>
#include <QVector>

using namespace std;

class Lexer
{
public:
    Lexer(QString source);
    struct token_type{
        QString type;
        QString name;
    };

    void MakingToken(QStringList StrList);
private:
    QVector<token_type> tokenList;
};

#endif // LEXER_H
