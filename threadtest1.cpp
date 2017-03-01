#include "threadtest1.h"
#include"mesgQ.h"


extern MesgQ msg1;


ThreadTest1::ThreadTest1()
{

}
ThreadTest2::ThreadTest2()
{

}
ThreadTest3::ThreadTest3()
{

}

void ThreadTest1::run()
{
    int i=0;
    while(1)
    {
        mesg_t *msg;
        msg = (mesg_t*)calloc(1,sizeof(mesg_t));
        qDebug()<<"thread1";
        sprintf((char *)&msg->data,"message Thread1:%d",i++);
        msg->len = 5;
        msg1.postMSG(msg);
        printf("..............\n");
        sleep(1);
    }
}


void ThreadTest3::run()
{
    int i=0;
    while(1)
    {
        mesg_t *msg;
        msg = (mesg_t*)calloc(1,sizeof(mesg_t));
        qDebug()<<"thread3";
        sprintf((char *)&msg->data,"message Thread3:%d",i++);
        msg->len = 5;
        msg1.postMSG(msg);
        printf("+++++++++++++++++++\n");
        sleep(1);
    }
}




void ThreadTest2::run()
{

    while(1)
    {
        mesg_t *msg;
        qDebug()<<"thread2";
        msg = (mesg_t*)msg1.pendMSG(1000000);
        if(msg!=nullptr)
        {
          printf("Data Recived:%s\n",msg->data);

        }
        printf("************\n");

    }
}
