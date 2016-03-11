#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "Server.h"

using namespace std;

//constructor
Server::Server(int port)
{
	portno = port;
	Server::create();
	Server::bindS();
	Server::listenS();
}

// creacion del socket
void Server::create()
{
	cout << "Creando el servidor ..." << endl;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (sockfd < 0)
	{
		cout<<"ERROR abriendo el socket"<<endl;
	}
}

//direccionamiento del socket
void Server::bindS()
{
	bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd,(struct sockaddr *) &serv_addr,
    		sizeof(serv_addr)) < 0)
    {
    	cout<<"ERROR en bind"<<endl;
    }
}

//escuha del socket
void Server::listenS()
{
	cout << "Escuchando ..." << endl;
	listen(sockfd,5);
}

//aceptar la conexion
void Server::acceptS()
{
	clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,
    			&clilen);
     if (newsockfd < 0)
     {
     	{
     		cout<<"ERROR aceptando"<<endl;
     	}
     }

    cout << "Se ha realizado una conexión exitosa ..." << endl;
}

//leer
bool Server::readMsg()
{
      bzero(buffer,1024);
     n = read(newsockfd,buffer,1023);
     if (n < 0)
     {
     	cout<<"ERROR de lectura"<<endl;
	return false;
     }
     if(n == 0)
	{
	cout << "Cerrando conexión con el cliente: "<<newsockfd<<endl;
	Server::closeCon();
	return false;
	}
     cout<< "Hora recibida desde el cliente "<<newsockfd<<": "<<buffer<<endl;
     return true;
}

//escribir
//void Server::sendMsg()
//{
//	n = write(newsockfd,"mensaje del server",18);
//	if (n<0)
//	{
//		cout<<"ERROR de escritura"<<endl;
//	}
//}

//cerrar conexiones
void Server::closeCon()
{
	close(newsockfd);
	close(sockfd);
}
