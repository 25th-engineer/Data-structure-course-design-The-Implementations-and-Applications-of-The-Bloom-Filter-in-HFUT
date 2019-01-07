#ifndef MYHIGHLIGHT_H
#define MYHIGHLIGHT_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>

class QTextDocument;

class myHighLight : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    myHighLight(QTextDocument *parent = 0);
    ~myHighLight();

    static QStringList cppKeyword();

    // get a Hash Value Array from a word
    QVector<int> Hash(QString word);
    // append a keyword to the bloom filter
    void appendKey(QString key);
    // delete a keyword from the bloom filter
    void deleteKey(QString key);
    // judge if the word is existing in the bloom filter
    bool isKeyExisted(QString key);

protected:
    // highlight the keyword block on updating document
    void highlightBlock(const QString &text);

private:
    // regression expression for searching every words
    QRegExp* rule;
    // the format we plan to apply in keyword
    QTextCharFormat format;

    // the structure to store keywords. it is expected to store 8000 words in total.
    // More details in program report.
    unsigned char bitMap[10000];
//    QVector<unsigned char> BloomFilter;
    // each keyword in the whitelist is considered not to be in the BloomFilter
    QVector<QString> whiteNameList;

//    // the hash function count. 7 is best for 1% error possibility
//    const int hashCount = 7;
};

#endif // MYHIGHLIGHT_H
