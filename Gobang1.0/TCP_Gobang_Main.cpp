
#include "Chesssubject.h"
#include "TCP_SOCKET.h"
#include <windows.h>
int main()
{
	WINSOCK_Startup();
	BackupTcp *tcp_universe = (BackupTcp*)malloc(10 * sizeof(BackupTcp));
jump:	Main_Init();
    int choose=0;
	choose = chessboard_IO();
	switch (choose)
	{
	case TCP_SERVER:
		chessboard_init();
		TCP_Server_Connecting(tcp_universe);
		Server_Chess_Start(tcp_universe->sockConn);

	case TCP_CLIENT:
		chessboard_init();
		TCP_Client_Connecting(tcp_universe);	
		Client_Chess_Start(tcp_universe->sockConn);

	case QUIT:
		exit(-1);

	default:
		goto jump;
	}

	

	WSACleanup();
	free(tcp_universe);
	puts("Bye-bye");
}