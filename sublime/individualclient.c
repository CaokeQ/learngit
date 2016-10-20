
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#define MAX_SIZE  1024
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

	connect(socketClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	char recvBuf[MAX_SIZE];
	FILE *fp; 
	fp = fopen("d:\\out.txt", "w");
	while(1) {
		int count=0;
		recv(socketClient, recvBuf, 100, 0);
		while(recvBuf[count++]!=EOF){
			fputc(recvBuf[count],fp);
		}
	}
	fclose(fp);
	printf("%s\n", recvBuf);
	system("pause");
}
