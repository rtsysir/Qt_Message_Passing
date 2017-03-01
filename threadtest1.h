#ifndef THREADTEST1_H
#define THREADTEST1_H

#include<QThread>

class ThreadTest1 : public QThread
{
public:
    ThreadTest1();
    void run();
};

class ThreadTest2 : public QThread
{
public:
    ThreadTest2();
    void run();
};


class ThreadTest3 : public QThread
{
public:
    ThreadTest3();
    void run();
};
#endif // THREADTEST1_H
