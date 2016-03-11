#include "MyThread.h"

void MyThread::createMyThread()
{
	pthread_create(&thread, NULL, &MyThread::ejecute, this);
}

MyThread::MyThread(IRunnable *ir, Server& new_sock)
{
	runnable = ir;
	mySock = new_sock;
}
