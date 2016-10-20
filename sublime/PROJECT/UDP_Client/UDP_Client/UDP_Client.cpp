#include "UDP_ChessSubject.h"
#include "UDP_SOCKET.h"
#include <windows.h>


int main(int argc, char* argv[])
{
	WORD socketVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(socketVersion, &wsaData) != 0)
	{
		return 0;
	}
	SOCKET sclient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int len = sizeof(sin);
	char *sendData = "Connecting";
	sendto(sclient, sendData, strlen(sendData), 0, (sockaddr *)&sin, len);
	chessboard_init();
	chess_start(sclient, sin);
	WSACleanup();
}