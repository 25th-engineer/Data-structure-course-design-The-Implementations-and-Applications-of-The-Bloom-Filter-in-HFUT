#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSyntaxHighlighter>
#include <QPushButton>
#include <QObject>
#include <QTextEdit>
#include "myhighlight.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font;
    font.setFamily("Consolas");
    font.setFixedPitch(true);
    font.setPointSize(20);

    editor = new QTextEdit;
    editor->setFont(font);

    highlighter = new myHighLight(editor->document());

    setCentralWidget(editor);
    setWindowTitle("Simple C++ Code Editor");

    connect(ui->actionappend_key, &QAction::triggered, this, &MainWindow::appendKey);
    connect(ui->actionDelete_key, &QAction::triggered, this, &MainWindow::deleteKey);
}

MainWindow::~MainWindow()
{
    delete editor;
    delete ui;
}

void MainWindow::appendKey()
{
    QString selectedText = editor->textCursor().selectedText();
    highlighter->appendKey(selectedText);
    highlighter->setDocument(editor->document());
}

void MainWindow::deleteKey()
{
    QString selectedText = editor->textCursor().selectedText();
    highlighter->deleteKey(selectedText);
    highlighter->setDocument(editor->document());
}
