
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#define MAX_SIZE 1024

 int main(int argc, char const *argv[])
{
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(1, 1);
	if (WSAStartup(wVersionRequested, &wsaData) != 0)return -1;

	SOCKET sockConn;
	SOCKET socketSrv = socket(AF_INET, SOCK_STREAM, 0);
	if(socketSrv==INCALID_SOCKET){
		printf("socket()failed:%d/n",WSAGetLastError());
		return -1;
	}
    


	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	if(bind(socketSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR))==SOCKET_ERROR){
		printf("bind()failed:%d/n",WSAGetLastError());
		return -1;
	}


	if(listen(socketSrv, 10)==SOCKET_ERROR){
		printf("listen()failed:%d/n",WSAGetLastError());
		return -1;
	}

	int len = sizeof(SOCKADDR);
	SOCKADDR_IN addrClient;

	sockConn=accept(socketSrv,(SOCKADDR*)&addrClient,&len);
        if(sockConn==INVALID_SOCKET)
	       {
			printf("accept() Failed: %d/n",WSAGetLastError());
			return -1;
			}

/*send loop*/
		int count=0;
		FILE *fp；
		fp=fopen("d:\\2.txt","w")
		char sendbuf[MAX_SIZE];
		while((sendbuf[count++]=fgetc(fp))!=EOF)
		{
			if(count==MAX_SIZE)
			{
				send(sockConn,sendbuf,MAX_SIZE,0);
				memset(sendbuf,'\0',MAX_SIZE);
				count=0;
				continue;
			}
		}
	send(sockConn,sendbuf,count,0);
	system("pause");
	closesocket(sockConn);
	fclose(fp);
	WSACleanup();
}






