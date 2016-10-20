
#include "UDP_ChessSubject.h"
#include "UDP_SOCKET.h"
#include <windows.h>



int main() 
{

		WSADATA wsaData;
		WORD sockVersion = MAKEWORD(2, 2);
		if (WSAStartup(sockVersion, &wsaData) != 0)
		{
			return 0;
		}

		SOCKET serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (serSocket == INVALID_SOCKET)
		{
			printf("socket error !");
			return 0;
		}

		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;
		serAddr.sin_port = htons(8888);
		serAddr.sin_addr.S_un.S_addr = INADDR_ANY;
		if (bind(serSocket, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		{
			printf("bind error !");
			closesocket(serSocket);
			return 0;
		}

		sockaddr_in remoteAddr;
		int nAddrLen = sizeof(remoteAddr);
		char recvData[100];
	    recvfrom(serSocket, recvData, 255, 0, (sockaddr *)&remoteAddr, &nAddrLen);
		printf("%s", recvData);
	chessboard_init();
	chess_start(serSocket,remoteAddr);
	WSACleanup();
}
