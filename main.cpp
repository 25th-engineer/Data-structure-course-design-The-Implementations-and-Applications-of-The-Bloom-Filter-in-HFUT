#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*w.show();*/
    QIcon icon("E:/code/Qt/build-TangTang-DFZ-Release/release/th.jpg");
    w.setWindowIcon(icon);
	w.setWindowTitle("Simple Code Editor");
    w.show();

    return a.exec();
}
