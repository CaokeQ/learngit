#ifndef  __CHESSBOARD_IO_H
#define  __CHESSBOARD_IO_H


#include <stdio.h>
#define NOT 0
#define BLACK 1
#define WHITE 2



static int chessboard[15][15];
static void chessboard_Draw(void);
static int chessboard_IO();
static int chess_X();
static int chess_Y();
static int chess_whowin(void);








#endif