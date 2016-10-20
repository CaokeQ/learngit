/*Set up a dynamic array to receive arbitrary chars*/
/*Judge the first chars*/
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>

int IOfunction()
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

int  judge_X() {
	while (1) {
		printf("x=");
		int x = IOfunction();
		if (x < 0 || x>15)continue;
		else return x;
	}
}

int judge_Y() {
	while (1) {
		printf("y=");
		int x = IOfunction();
		if (x < 0 || x>15) {
			printf("error");
			continue;
		}
		else return x;
	}

}

int main() {
	fputs("please input :", stdout);
	while (1) {
		int k = judge_X();
		printf("%d", k);
	}
	system("pause");

}
