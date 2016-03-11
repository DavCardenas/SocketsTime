#include <iostream>
#include "Client.h"
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
	Client client (argv[1],atoi(argv[2]));

	while(true){
	client.sendMsg();
	usleep(6000000);
	}

        client.closeCon();
	return 0;
}
