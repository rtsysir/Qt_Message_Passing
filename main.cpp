#include <QCoreApplication>
#include<QVector>
#include<QThread>
#include<QWaitCondition>
#include<QDebug>
#include"mesgQ.h"
#include"threadtest1.h"

MesgQ msg1;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadTest1 th1;
    ThreadTest2 th2;
//    ThreadTest3 th3;
    th1.start();
    th2.start();
//    th3.start();
    th1.wait();
    th2.wait();
//    th3.wait();

    return a.exec();
}

