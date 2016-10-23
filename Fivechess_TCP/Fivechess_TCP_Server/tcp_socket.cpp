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



void tcp_Connecting(BackupTcp *tcp_server)
{
	tcp_server->sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	tcp_server->addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	tcp_server->addrSrv.sin_family = AF_INET;
	tcp_server->addrSrv.sin_port = htons(6000);
	if (bind(tcp_server->sockSrv, (SOCKADDR*)&(tcp_server->addrSrv), sizeof(SOCKADDR)) == SOCKET_ERROR) {
		printf("bind()failed:%d/n", WSAGetLastError());
		return;
	}

	if (listen(tcp_server->sockSrv, 10) == SOCKET_ERROR) {
		printf("listen()failed:%d/n", WSAGetLastError());
		return;
	}
	int len = sizeof(SOCKADDR);
	puts("waiting");
	tcp_server->sockConn = accept(tcp_server->sockSrv, (SOCKADDR*)&(tcp_server->addrClient), &len);
	if (tcp_server->sockConn == INVALID_SOCKET)
	{
		printf("accept() Failed: %d/n", WSAGetLastError());
		return;
	}
}