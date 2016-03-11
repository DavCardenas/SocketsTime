#include "CustomerSupport.h"
#include <unistd.h>
#include <iostream>

using namespace std;

void CustomerSupport::run(Server myServer)
{
	bool flag = true;
	while(flag)
	{
	if(myServer.readMsg())
	{
		usleep(6000000);
	} else {
		flag = false;
		}
	}
}
