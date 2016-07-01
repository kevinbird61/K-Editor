#include "lexer.h"

Lexer::Lexer(QString source)
{
    // Filter out all non-use character
    QRegExp expression("[ ]+|[\t]+|[\n]+");
    // Dealing with Lexical analysis
    QStringList List = source.split(expression);
    // Transfer all List elements from QString into Token
    MakingToken(List);

    // Print for debug
    /*for(int i = 0; i < List.size(); i++){
        cout << List.at(i).toStdString() << endl;
    }
    cout << endl;*/

}

void Lexer::MakingToken(QStringList StrList)
{
    QRegExp id("[i][d][A-Za-z]+");
    QRegExp loop("[l][o][o][p]");
    for(int i = 0; i < StrList.size(); i++){
        token_type temp;
        if(id.indexIn(StrList.at(i)) == 0){
            // Compare with Id
            temp.name = StrList.at(i);
            temp.type = QString("Identifier");
            tokenList.append(temp);
        }
        else if(loop.indexIn(StrList.at(i)) == 0){
            // Compare with Loop condition
            temp.name = StrList.at(i);
            temp.type = QString("Loop");
            tokenList.append(temp);
        }
    }
}
