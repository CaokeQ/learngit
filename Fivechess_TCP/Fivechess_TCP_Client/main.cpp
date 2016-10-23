
#include "Chesssubject.h"
#include "TCP_SOCKET.h"
#include <windows.h>
int main()
{
	chessboard_init();
	WINSOCK_Startup();
	BackupTcp *tcp_client = (BackupTcp*)malloc(10 * sizeof(BackupTcp));
	tcp_Connecting(tcp_client);
	puts("Connected you can play chess\n");
	puts("Initialing...");
	Sleep(3000);
	system("cls");


	chessboard_init();
	chess_start(tcp_client->sockConn);

	WSACleanup();
	free(tcp_client);
}