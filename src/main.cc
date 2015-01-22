#include "include/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.move(-2000,0);
    w.showMaximized();

//    ServerReceive serverR(&w,9000);
//    ServerReceive serverR1(&w,9001);



    return a.exec();
}
