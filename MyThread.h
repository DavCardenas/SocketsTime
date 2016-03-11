#include <iostream>
#include <pthread.h>
#include "IRunnable.h"
#include "Server.h"

using namespace std;

class MyThread
{

public:

	pthread_t thread;
	IRunnable *runnable;
	Server mySock;
	void createMyThread();
	static void *ejecute(void *arg)
	{
		((MyThread *) arg) -> runnable->run(((MyThread *)arg)->mySock);
	}
	MyThread(IRunnable *, Server&);
};
