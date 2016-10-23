#pragma once
#ifndef __TCP_SOCKET_H_
#define  __TCP_SOCKET_H_
#include <winsock2.h>
#pragma comment (lib,"ws2_32.lib")

typedef struct BackupTcp_
{
	SOCKET sockConn;
	SOCKET sockSrv;
	SOCKADDR_IN addrSrv;
	SOCKADDR_IN addrClient;
}BackupTcp;

void WINSOCK_Startup();
void tcp_Connecting(BackupTcp *tcp_client);






#endif