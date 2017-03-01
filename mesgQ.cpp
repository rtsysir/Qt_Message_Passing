#include "mesgQ.h"

MesgQ::MesgQ()
{
    mesgQ.clear();
}


void MesgQ::postMSG(mesg_t *msg)
{
    Mutex.lock();
    qDebug()<<"post";
    mesgQ.push_back(msg);
    waitCon.wakeAll();
    Mutex.unlock();
}

void* MesgQ::pendMSG(uint32_t timeout)
{
    void *msg=nullptr;
    //    mesg_t retmsg;

    Mutex.lock();
    qDebug()<<"wait";
    if(waitCon.wait(&Mutex, timeout)==true){
        if(!mesgQ.isEmpty())
        {
            printf("mesq not empty:%d\n",mesgQ.length());
            msg = mesgQ.takeFirst();
        }
    }
    Mutex.unlock();
    return msg;
}
