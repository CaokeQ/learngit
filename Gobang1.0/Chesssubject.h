#pragma once

#ifndef  __CHESSBOARDSUBJECT_H
#define  __CHESSBOARDSUBJECT_H
#include "TCP_SOCKET.h"
#include <stdio.h>
#define TCP_SERVER 1
#define TCP_CLIENT 2
#define QUIT 3
#define BLACK 1
#define WHITE 2
#define WIDTH 15
#define NONE 0

static int chessboard[15][15];
int  chessboard_DrawB( int x,int y);
int  chessboard_DrawW(int x, int y);
void chessboard_init();
void Server_Chess_Start(SOCKET s);
void Main_Init();
void  Client_Chess_Start(SOCKET s);
void Assign_None_Chessboard();

int chessboard_IO();
int chess_X();
int chess_Y();
int chess_whowin(void);








#endif