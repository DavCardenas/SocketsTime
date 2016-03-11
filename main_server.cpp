#include <iostream>
#include "Server.h"
#include <unistd.h>
#include "MyThread.h"
#include "CustomerSupport.h"

using namespace std;

int main()
{
	Server server (12345);

	while (true){

	server.acceptS();

	MyThread *myThread = new MyThread(new CustomerSupport(), server);
	myThread -> createMyThread();
	}
	return 0;
}
