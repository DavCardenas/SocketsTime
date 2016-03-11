#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <iostream>
#include "Clock.h"

using namespace std;

class Client{
public:
	int sockfd;
	int portno;
	int n;

	Clock clock;

	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[1024];

	Client(char *hostS,int port);

	void create();
	void connectC();
	void sendMsg();
	//void readMsg();
	void closeCon();
};
