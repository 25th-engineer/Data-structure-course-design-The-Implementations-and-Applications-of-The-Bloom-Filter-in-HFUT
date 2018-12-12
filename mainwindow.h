#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myhighlight.h"
#include <QTextEdit>
#include <QtCore>

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
    // append selected text for ui
    void appendKey();
    void deleteKey();

private:
    Ui::MainWindow *ui;

    QTextEdit *editor;
    myHighLight *highlighter;
};

#endif // MAINWINDOW_H
