#pragma once

#ifndef  __CHESSBOARDSUBJECT_H
#define  __CHESSBOARDSUBJECT_H
#include "UDP_SOCKET.h"
#include <stdio.h>
#define BLACK 1
#define WHITE 2
#define WIDTH 15
#define NONE 0

static int chessboard[15][15];
void chessboard_DrawB(int x, int y);
void chessboard_DrawW(int x, int y);
void chessboard_init();
void chess_start(SOCKET s, sockaddr_in sin);

int chessboard_IO();
int chess_X();
int chess_Y();
int chess_whowin(void);








#endif