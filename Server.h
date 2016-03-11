#ifndef Server_class
#define Server_class
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

using namespace std;

class Server{
public:
	int sockfd;
	int newsockfd;
	int portno;
	int n;

	socklen_t clilen;
	char buffer[1024];

	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;

	Server(int port);

	Server(){};
	void create();
	void bindS();
	void listenS();
	void acceptS();
	//void sendMsg();
	bool readMsg();
	void closeCon();
};

#endif
