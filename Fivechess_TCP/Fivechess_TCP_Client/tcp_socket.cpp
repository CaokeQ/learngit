/*Creat a function to establish a linkage*/
#include <stdio.h>
#include "TCP_SOCKET.h"

void WINSOCK_Startup() {
	WORD socketVersion = MAKEWORD(1, 1);
	WSADATA wsaData;
	if (WSAStartup(socketVersion, &wsaData) != 0)
	{
		return;
	}
}



void tcp_Connecting(BackupTcp *tcp_client)
{
	tcp_client->sockConn = socket(AF_INET, SOCK_STREAM, 0);
	tcp_client->addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	tcp_client->addrSrv.sin_family = AF_INET;
	tcp_client->addrSrv.sin_port = htons(6000);
	connect(tcp_client->sockConn, (SOCKADDR*)&(tcp_client->addrSrv), sizeof(SOCKADDR));
}