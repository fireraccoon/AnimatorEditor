#include "mainwindow.h"
#include "spriteranimationreader.h"
#include <QApplication>
#include <QDebug>
#include <animator.h>

int main(int argc, char *argv[])
{




    QApplication a(argc, argv);

    MainWindow w;
    w.show();





    return a.exec();
}
