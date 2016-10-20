
/*Can we use the TCP function the chess play every time?*/
/*May will waste many resources*/

#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
char *buf = (char*)malloc(2);
char *rbuf = (char*)malloc(2);
int  sendbuf(char *buf, int x, int y, SOCKET S) {
	buf[0] = x + '0';
	buf[1] = y + '0';
	if (send(S, buf, sizeof(buf), 0) == SOCKET_ERROR)return 0;
	return 1;
}

int receive(char *rbuf, SOCKET S) {
	int x;
	int y;
	if (recv(S, rbuf, sizeof(rbuf), 0) == SOCKET_ERROR)return 0;
	x = rbuf[0] - '0';
	y = rbuf[1] - '0';
	printf("%d %d", x, y);
	return 1;
}
int main(int argc, char const *argv[])
{
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(1, 1);
	if (WSAStartup(wVersionRequested, &wsaData) != 0)return -1;


	SOCKET socketClient = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	puts("waiting");
	connect(socketClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	puts("connected\n");
	if (receive(rbuf, socketClient) == 0)exit(0);
RE:
	if (sendbuf(buf, 3, 4, socketClient) == 0)
		goto RE;

system("pause");
}

