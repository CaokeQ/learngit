/*Identifie the form of array and classify them*/
// 10th,September,2016

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <cstdio>

static void function2(const char *name, char *p,int j)
{
	int i = 0;
	fputs(name, stdout);
	fputs(":", stdout);
	for (i = 0; i <=j; i++) {
		fputc(p[i], stdout);
	}
	fputs("\n", stdout);
}





static void function1(char *p)
{
	int i = 0;
	int j , k,l;
	j = k = l = 0;
	char *a = (char *)malloc(10), *b = (char *)malloc(8 * sizeof(char)),*c = (char *)malloc(10 * sizeof(char));
	
	while (p[i++] != '\0')
	{
		if (isdigit(p[i])) {
			a[j++] = p[i];
		}
		if (isalpha(p[i])) {
			b[k++] = p[i];
		}
		if (ispunct(p[i]))
		{
			c[l++] = p[i];
		}
	}
	function2("isdigit", a,j);
	function2("isalpha", b,k);
	function2("ispunc", c,l);
}


int main(int argc, char const *argv[])
{
	char *p;
	p = "sfaxv\'''  ''vxcv  12234";//
	function1(p);
	system("pause");
	return 0;
}