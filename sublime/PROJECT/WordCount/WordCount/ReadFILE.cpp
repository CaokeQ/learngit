#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
	struct node *next;
	char *data;
};

//int main() {
//	FILE *fp;
//	node *test;
//	test = (node *)malloc(10 * sizeof(node));
//	char *a;
//	test->data = (char*)malloc(200);
//	a = (char*)malloc(200);
//	memset(test->data,'\0',200);
//	//test->data =a;
//	if ((fp = fopen("D:\\test.txt", "r")) == NULL) {
//	fputs("Error,The file not exist", stderr);
//		exit(0);
//	}
//	char ch;
//	int i = 0;
//	while ((ch = fgetc(fp)) != EOF) {
//			test->data[i++] = ch;
//	}
//	printf("%s", test->data);
//	char *p;
//	p = "sdfsdfsdf";
//	printf("\n%c", p[2]);
//	system("pause");
//}