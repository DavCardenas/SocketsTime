#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "Client.h"
#include <iostream>
#include "Clock.h"
using namespace std;

Client::Client(char  *hostS,int port)
{
	portno = port;
	Client::create();

	server = gethostbyname(hostS);
	if (server == NULL)
	{
		cout<<"ERROR no se encontro el host"<<endl;
	}

	Client::connectC();
}

// creacion del socket
void Client::create()
{
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (sockfd < 0)
	{
		cout<<"ERROR abriendo el socket"<<endl;
	}
}

//conexion hacia el server
void Client::connectC()
{
	 bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,
    			sizeof(serv_addr))<0)
    {
    	cout<<"ERROR de conexion"<<endl;
    }
}

//enviar
void Client::sendMsg()
{

	string aux = clock.currentDateTime();
	n = write(sockfd,aux.c_str(),18);
	if (n<0)
	{
		cout<<"ERROR de escritura"<<endl;
	}
}

//leer
//void Client::readMsg()
//{
//    bzero(buffer,1024);
//     n = read(sockfd,buffer,1023);
//    if (n < 0)
//     {
//     	cout<<"ERROR de lectura"<<endl;
//     }
//     cout<<buffer<<endl;
//}

void Client::closeCon()
{
	close(sockfd);
}

