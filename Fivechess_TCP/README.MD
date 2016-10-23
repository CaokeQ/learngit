# Fivechess

This programm achieve the Gobang  which can play in LAN

[ChessSubject](#ChessSubject)

[tcp_socket](#TCP_SOCKET)

[main](#main)



###ChessSubject
- Declaration
```C
#define BLACK 1
#define WHITE 2
#define WIDTH 15
#define NONE 0

static int chessboard[15][15];
void chessboard_DrawB( int x,int y);
void chessboard_DrawW(int x, int y);
void chessboard_init();
void chess_start(SOCKET s);
```




###TCP_SOCKET
- Declaration
```C
typedef struct BackupTcp_
{
	SOCKET sockConn;
	SOCKET sockSrv;
	SOCKADDR_IN addrSrv;
	SOCKADDR_IN addrClient;
}BackupTcp;

void WINSOCK_Startup();
void tcp_Connecting(BackupTcp *tcp_client);
```
###main
- Realization
```c
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
```
- Explain
   - 
     The *chessboard_init*  to draw a chessboard,and the ***WINSOCK_Startup*** to initialize the winsock,  ***tcp_connecting***   to creat connection for client.When the client  connected,***chess_start*** to start the game
   - The ***chess_start***  only include error control for input .














