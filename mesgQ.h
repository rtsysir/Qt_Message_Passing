#ifndef THREADQ_H
#define THREADQ_H
#include<QThread>
#include<QWaitCondition>
#include<QDebug>


typedef struct{
    uint8_t data[1024];
    uint16_t len;
}mesg_t;

class MesgQ
{
public:
    MesgQ();
    void run();
    void postMSG(mesg_t *msg);
    void* pendMSG(uint32_t timeout);
private:
    QMutex Mutex;
    QWaitCondition waitCon;
    QVector<void *> mesgQ;
};

#endif // THREADQ_H
