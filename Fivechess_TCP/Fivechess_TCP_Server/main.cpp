
#include "Chesssubject.h"
#include "TCP_SOCKET.h"
#include <windows.h>
int main()
{
	chessboard_init();

	WINSOCK_Startup();
	BackupTcp *tcp_server = (BackupTcp*)malloc(10 * sizeof(BackupTcp));
	tcp_Connecting(tcp_server);


	puts("\nConnected you can play chess\n");
	puts("Initialing...");
	Sleep(2000);
	system("cls");


	chessboard_init();
	chess_start(tcp_server->sockConn);

	WSACleanup();
	free(tcp_server);
	puts("Bye-bye");
}