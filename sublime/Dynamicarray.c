/*Set up a dynamic array to receive arbitrary chars*/
/*Judge the first chars*/
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int IOfunction(char *p)
{
	if(isdigit(p[0])){
		if(p[1]!='\0'&&isdigit(p[1]))
			return atoi(p)
	}
	else
		return -1;
}

int  judge_X(char *p) {
	while (1) {
		printf("x=");
		int x = IOfunction(p);
		if (x<0 || x>15)continue;
		else return x;
	}
}

int judge_Y(char *p) {
	while (1) {
		printf("y=");
		int x = IOfunction(p);
		if (x < 0 || x>15) {
			printf("error");
			continue;
		}
		else return x;
	}

}

int count = 0;

int main(int argc, char const *argv[])
{
	int N = 10;
	char *parray = (char*)malloc(N * sizeof(char));
	if (parray == NULL)return -1;
	memset(parray, 0, N * sizeof(char));
	while ((parray[count++] = getchar()) != '\n') {
		if (count > N - 1)
		{
			N = 2*N;
			parray = (char*)realloc(parray, N * sizeof(char));
		}
	}
 

	parray[count] = '\0';

	fputs(parray, stdout);
	puts("\n");

	printf("The digit is %d",judge_X(paa));
	free(parray);
	system("pause");
	return 0;
}