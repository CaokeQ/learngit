
#include <stdio.h>

static int chessboard[15][15];
void draw() /* 画棋盘 */
 {  
 	int i,j;  
 	char p[15][15][4];  
 	for(j=0;j<15;j++)   
 		for(i=0;i<15;i++)
 			{    
 				if(chessboard[j][i]==0) 
	 				strcpy_s(p[j][i],"  \0");    
 				if(chessboard[j][i]==1) 
 					strcpy_s(p[j][i],"●\0");    
 				if(chessboard[j][i]==2) 
 					strcpy_s(p[j][i],"◎\0");   

 			}
 				  printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");   printf("       ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐\n");  
 				  for(i=0,j=0;i<14;i++,j++)
 				  	{  printf("     %2d│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%d\n",j,p[i][0],p[i][1],p[i][2],p[i][3],p[i][4],p[i][5],p[i][6],p[i][7],p[i][8],p[i][9],p[i][10],p[i][11],p[i][12],p[i][13],p[i][14],j);  
 				  printf("       ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤\n");  } 
    printf("     14│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│0\n",p[14][0],p[14][1],p[14][2],p[14][3],p[14][4],p[14][5],p[14][6],p[14][7],p[14][8],p[14][9],p[14][10],p[14][11],p[14][12],p[14][13],p[14][14]); 
    printf("       └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘\n");  
    printf("         0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  \n");
     }