#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include "Chesssubject.h"
#include "TCP_SOCKET.h"

/*Should more and more simplyfied*/
int  sendbuf(char *buf, int x, int y, SOCKET S) {
	buf[0] = x + '0';
	buf[1] = y + '0';
	if (send(S, buf, sizeof(buf), 0) == SOCKET_ERROR)return 0;
	return 1;
}

int receive(char *rbuf, SOCKET S) {

	if (recv(S, rbuf, sizeof(rbuf), 0) == SOCKET_ERROR)return 0;
	return 1;
}

int chessboard_DrawB(int x,int y) {
	 int i, j;
	 if (chessboard[y][x] != NONE)
	 {
		 printf("ERROR\n");
		 return -1;
	 }
	 else if (x >= 0)
	 {
		 system("cls");
		 chessboard[y][x] = BLACK;
		 char p[15][15][4];
		 for (j = 0; j < 15; j++)
			 for (i = 0; i < 15; i++)
			 {
				 if (chessboard[j][i] == NONE)
					 strcpy_s(p[j][i], "  \0");
				 if (chessboard[j][i] == BLACK)
					 strcpy_s(p[j][i], "¡ñ\0");
				 if (chessboard[j][i] == WHITE)
					 strcpy_s(p[j][i], "¡ð\0");

			 }
		 printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");   printf("       ©°©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©´\n");
		 for (i = 0, j = 0; i < 14; i++, j++)
		 {
			 printf("     %2d©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%d\n", j, p[i][0], p[i][1], p[i][2], p[i][3], p[i][4], p[i][5], p[i][6], p[i][7], p[i][8], p[i][9], p[i][10], p[i][11], p[i][12], p[i][13], p[i][14], j);
			 printf("       ©À©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©È\n");
		 }
		 printf("     14©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦0\n", p[14][0], p[14][1], p[14][2], p[14][3], p[14][4], p[14][5], p[14][6], p[14][7], p[14][8], p[14][9], p[14][10], p[14][11], p[14][12], p[14][13], p[14][14]);
		 printf("       ©¸©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©¼\n");
		 printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");
	 }
	 return 1;
 }
 int chessboard_DrawW(int x, int y) {
	 int i, j;
	 if (chessboard[y][x] != NONE)
	 {
		 printf("ERROR\n");
		 return -1;
	 }
	 else if (x >= 0)
	 {
		 system("cls");
		 chessboard[y][x] = WHITE;
		 char p[15][15][4];
		 /*The next statement must should be simplyfied*/
		 for (j = 0; j < 15; j++)
			 for (i = 0; i < 15; i++)
			 {
				 if (chessboard[j][i] == NONE)
					 strcpy_s(p[j][i], "  \0");
				 if (chessboard[j][i] == BLACK)
					 strcpy_s(p[j][i], "¡ñ\0");
				 if (chessboard[j][i] == WHITE)
					 strcpy_s(p[j][i], "¡ð\0");

			 }
		 printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n"); 
		 printf("       ©°©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©´\n");
		 for (i = 0, j = 0; i < 14; i++, j++)
		 {
			 printf("     %2d©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%d\n", j, p[i][0], p[i][1], p[i][2], p[i][3], p[i][4], p[i][5], p[i][6], p[i][7], p[i][8], p[i][9], p[i][10], p[i][11], p[i][12], p[i][13], p[i][14], j);
			 printf("       ©À©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©È\n");
		 }
		 printf("     14©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦0\n", p[14][0], p[14][1], p[14][2], p[14][3], p[14][4], p[14][5], p[14][6], p[14][7], p[14][8], p[14][9], p[14][10], p[14][11], p[14][12], p[14][13], p[14][14]);
		 printf("       ©¸©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©¼\n");
		 printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");
	 }
	 return 1;
 }

 void chessboard_init()
 {
	 system("mode con  cols=72 lines=37");
	 system("color E0");
	 char p[15][15][4];
	 for (int j = 0; j < 15; j++)
		 for (int i = 0; i < 15; i++)
		 {
				 strcpy_s(p[j][i], "  \0");

		 }
	 printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");   printf("       ©°©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©´\n");
	 for (int i = 0, j = 0; i < 14; i++, j++)
	 {
		 printf("     %2d©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%d\n", j, p[i][0], p[i][1], p[i][2], p[i][3], p[i][4], p[i][5], p[i][6], p[i][7], p[i][8], p[i][9], p[i][10], p[i][11], p[i][12], p[i][13], p[i][14], j);
		 printf("       ©À©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©È\n");
	 }
	 printf("     14©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦%s©¦0\n", p[14][0], p[14][1], p[14][2], p[14][3], p[14][4], p[14][5], p[14][6], p[14][7], p[14][8], p[14][9], p[14][10], p[14][11], p[14][12], p[14][13], p[14][14]);
	 printf("       ©¸©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©¼\n");
	 printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");
 }


 void Main_Init()
 {
	 system("cls");
	 system("mode con  cols=72 lines=37");
	 system("color E0");
	 for (int i = 0; i < 18; i++)fputs("\n", stdout);
	 printf("%36s\n", "1.Run TCP Server");
	 printf("%36s\n", "2.Run TCP Client");
	 printf("%26s\n", "3.exit");
 }

 int chessboard_IO()
{
	int N = 10;
	int count = 0;
	char *parray = (char*)malloc(N * sizeof(char));
	if (parray == NULL)return -1;
	memset(parray, 0, N * sizeof(char));
	while ((parray[count++] = getchar()) != '\n') {
		if (count > N - 1)
		{
			N = 2 * N;
			parray = (char*)realloc(parray, N * sizeof(char));
		}
	}
	parray[count] = '\0';
	if (isdigit(parray[0]))
	{

		int var = atoi(parray);
		free(parray);
		return var;

	}
	else
		return -1;
}


int  chess_X() {
	while (1) {
		printf("\rx=");
		int x = chessboard_IO();
		if (x < 0 || x>=15)continue;
		else return x;
	}
}


int chess_Y()
{
	while (1) {
		printf("y=");
		int x = chessboard_IO();
		if (x < 0 || x>=15) {
			printf("error");
			continue;
		}
		else return x;
	}
}


int chess_whowin(void) {
	int x;
	int y;

	for (x = 0; x < WIDTH; x++) {
		for (y = 0; y < WIDTH; y++) {
			if (chessboard[x][y] != NONE) {
				if (y + 4 < WIDTH) {
					if (chessboard[x][y + 1] == chessboard[x][y] &&
						chessboard[x][y + 2] == chessboard[x][y] &&
						chessboard[x][y + 3] == chessboard[x][y] &&
						chessboard[x][y + 4] == chessboard[x][y]) {
						return chessboard[x][y];
					}
				}
				if (x + 4 < WIDTH) {
					if (chessboard[x + 1][y] == chessboard[x][y] &&
						chessboard[x + 2][y] == chessboard[x][y] &&
						chessboard[x + 3][y] == chessboard[x][y] &&
						chessboard[x + 4][y] == chessboard[x][y]) {
						return chessboard[x][y];
					}
				}
				if (x + 4 < WIDTH && y + 4 < WIDTH) {
					if (chessboard[x + 1][y + 1] == chessboard[x][y] &&
						chessboard[x + 2][y + 2] == chessboard[x][y] &&
						chessboard[x + 3][y + 3] == chessboard[x][y] &&
						chessboard[x + 4][y + 4] == chessboard[x][y]) {
						return chessboard[x][y];
					}
				}
				if (x - 4 > 0 && y + 4 < WIDTH) {
					if (chessboard[x - 1][y + 1] == chessboard[x][y] &&
						chessboard[x - 2][y + 2] == chessboard[x][y] &&
						chessboard[x - 3][y + 3] == chessboard[x][y] &&
						chessboard[x - 4][y + 4] == chessboard[x][y]) {
						return chessboard[x][y];
					}
				}
			}
		}
	}

	return NONE;
}


/*the question of overwrite 
 *don't cls(simple)
*/
void Server_Chess_Start(SOCKET socketConn)
{
	for (;;)
	{
		char *buf = (char*)malloc(2);
		char *rbuf = (char*)malloc(2);

		fputs("The black\n", stdout);
		int x = chess_X();
		int y = chess_Y();
		while (chessboard_DrawB(x, y) != 1){
			x = chess_X();
			y = chess_Y();
		}

		if (sendbuf(buf, x, y, socketConn) == 0)exit(0);
		if (chess_whowin() == BLACK)
		{
			fputs("the black is win\n", stdout);
			fputs("do you want to go next?(y or n)\n", stdout);
			if (getchar() == 'y') {
				chessboard_init();
				Assign_None_Chessboard();
				continue;
			}
			else if (getchar() == 'n')exit(0);
			else {
				fputs("Input error,default configuration\n", stdout);
				chessboard_init();
			}
		}


		
		while (!receive(rbuf, socketConn)) {}
		x = rbuf[0] - '0';
		y = rbuf[1] - '0';
		chessboard_DrawW(x, y);


		if (chess_whowin() == WHITE)
		{
			fputs("the black is win\n", stdout);
			fputs("do you want to go next?(y or n)\n", stdout);
			if (getchar() == 'y') {
				chessboard_init();
				Assign_None_Chessboard();
				continue;
			}
			else if (getchar() == 'n')exit(0);
			else {
				fputs("Input error,default configuration\n", stdout);
				chessboard_init();
			}
		}

	}
}


void Client_Chess_Start(SOCKET socketClient)
{
	for (;;)
	{
		int x;
		int y;
		char *buf = (char*)malloc(2);
		char *rbuf = (char*)malloc(2);
		while (!receive(rbuf, socketClient)) {}
		x = rbuf[0] - '0';
		y = rbuf[1] - '0';
		chessboard_DrawB(x, y);
		if (chess_whowin() == BLACK)
		{
			fputs("the black is win\n", stdout);
			fputs("do you want to go next?(y or n)\n", stdout);
			if (getchar() == 'y') {
				chessboard_init();
				Assign_None_Chessboard();
				continue;
			}
			else if (getchar() == 'n')exit(0);
			else {
				fputs("Input error,default configuration\n", stdout);
				chessboard_init();
			}
		}
		fputs("The white\n", stdout);
		x = chess_X();
		y = chess_Y();
		while (chessboard_DrawW(x, y) != 1)
		{
			x = chess_X();
			y = chess_Y();
		}
		if (sendbuf(buf, x, y, socketClient) == 0)exit(1);
		if (chess_whowin() == WHITE)
		{
			fputs("the black is win\n", stdout);
			fputs("do you want to go next?(y or n)\n", stdout);
			if (getchar() == 'y') {
				chessboard_init();
				Assign_None_Chessboard();
				continue;
			}
			else if (getchar() == 'n')exit(0);
			else {
				fputs("Input error,default configuration\n", stdout);
				chessboard_init();
			}
		}
	}
}


void Assign_None_Chessboard() {
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			chessboard[i][j] = NONE;
}