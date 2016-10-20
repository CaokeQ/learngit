/*Test the rand() function*/

#include <stdio.h>

extern void srand(unsigned int x);
extern int rand(void);

int main(void)
{
	int count;
	unsigned seed;
	printf("please enter your choice for seed\n");
	while(scanf("%u",&seed==1))
	{
		srand1(seed);
		for(count=0;count<5;count++)
			printf("%d\n",rand());
		printf("please enter next seed(q)\n");
	}
	printf("done\n");
	return 0;
}
