#include "myhighlight.h"
#include "bloomfilter.cpp"
#include <QtGui>

myHighLight::myHighLight(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    // find each word
    rule = new QRegExp("(\\b)(\\w+)(\\b)");

    format.setForeground(Qt::blue);
    format.setFontWeight(QFont::Bold);

    initBitMap(bitMap);
    QStringList keyWords = cppKeyword();
    for(QString key : keyWords)
    {
        appendKey(key);
    }
}

myHighLight::~myHighLight()
{
    if(rule)
        delete rule;
}

QStringList myHighLight::cppKeyword()
{
    return QStringList()<<"asm"<<"auto"<<"bool"<<"break"<<"case"<<"catch"<<"char"
                       <<"class"<<"const"<<"const_cast"<<"continue"<<"default"<<"delete"
                      <<"do"<<"double"<<"dynamic_cast"<<"else"<<"enum"<<"explicit"
                     <<"export"<<"extern"<<"false"<<"float"<<"for"<<"friend"<<"goto"
                    <<"if"<<"inline"<<"int"<<"long"<<"mutable"<<"namespace"<<"new"
                   <<"operator"<<"private"<<"protected"<<"public"<<"register"
                  <<"reinterpret_cast"<<"return"<<"short"<<"signed"<<"sizeof"<<"static"
                 <<"static_cast"<<"struct"<<"switch"<<"template"<<"this"<<"throw"
                <<"true"<<"try"<<"typedef"<<"typeid"<<"typename"<<"union"<<"unsigned"
               <<"using"<<"virtual"<<"void"<<"volatile"<<"wchar_t"<<"while";
}

//QVector<int> myHighLight::Hash(QString word)
//{
//    std::hash<std::string> str_hash;
//    QVector<int> res;
//    if(word.size()%hashCount == 0)
//    {
//        word += " ";
//    }
//    QString key;
//    while(key.size() < 100)
//    {
//        key += word;
//    }

//    for(int i = 0; i<hashCount; i++)
//    {
//        QString key0;
//        for(int j = i;j<key.size(); j+=hashCount)
//        {
//            key0.append(key[j]);
//        }
//        res.append(abs(int(str_hash(key0.toStdString()))%(BloomFilter.size()*8-1)));
//    }

//    return res;
//}

void myHighLight::appendKey(QString key)
{
    if(!rule->exactMatch(key))
    {
        qDebug()<<"KeyWord "<<key<<" is not a word";
        return;
    }

    if(whiteNameList.contains(key))
    {
        whiteNameList.removeOne(key);
    }

    appendKey2BitMap(bitMap, key.toStdString().data());
//    if(isKeyExisted(key))
//    {
//        qDebug()<<"KeyWord "<<key<<" alredy existed!";
//        return;
//    }

//    QVector<int> hash = Hash(key);
//    for(auto code : hash)
//    {
//        if(!((BloomFilter[code/8] >> code%8) % 2))
//        {
//            BloomFilter[code/8] += 1 << code%8;
//        }
//    }
}

void myHighLight::deleteKey(QString key)
{
    if(!rule->exactMatch(key))
    {
        qDebug()<<"KeyWord "<<key<<" is not a word";
        return;
    }

    if(whiteNameList.contains(key))
    {
        qDebug()<<"KeyWord "<<key<<" to be deleted has already been in whitelist";
        return;
    }

    if(!isKeyExisted(key))
    {
        qDebug()<<"KeyWord "<<key<<" to be deleted is not in the BloomFilter!";
        return;
    }

    whiteNameList.push_back(key);
    qDebug()<<whiteNameList;
}

bool myHighLight::isKeyExisted(QString key)
{
    if(whiteNameList.contains(key))
    {
        return false;
    }

    return isKeyExistInBitMap(bitMap, key.toStdString().data());
//    QVector<int> hash = Hash(key);
//    for(auto code : hash)
//    {
//        if(!((BloomFilter[code/8] >> code%8) % 2))
//        {
//            return false;
//        }
//    }
//    return true;
}

void myHighLight::highlightBlock(const QString &text)
{
    int index = rule->indexIn(text);
    while(index >= 0)
    {
        int length = rule->matchedLength();
        if(isKeyExisted(text.mid(index, length)))
        {
            setFormat(index, length, format);
        }
        index = rule->indexIn(text, index + length);
    }
}
