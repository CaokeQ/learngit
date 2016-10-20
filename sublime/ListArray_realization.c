#include <stdio.h>
#include<stdlib.h>
#include <string.h>


/*word count*/

typedef  struct ListElem
{
	struct ListElem *next;
	char  *data;

}ListElem;


void ListE_Initialize(ListElem *p) {
	
	p->data=(char*)malloc(20);
	memset(p->data, '\0', 20);
	return ;
}

void ListE_Print(ListElem *head) {
	ListElem *p=(ListElem *)malloc(sizeof(ListElem));
	//ListE_Initialize(p);
	p = head;
	while (p!= NULL) {
		fputs(p->data,stdout);
		puts("\n");
		p = p->next;
	}
	puts("\nDone");
}

void listE_Insert(ListElem *p, ListElem *NewELem) {
	if (p->next == NULL) {
		p->next = NewELem;
		NewELem->next = NULL;
	}
	else {
		NewELem->next = p->next;
		p->next = NewELem;
	}
}
void Read_File(ListElem *head) {
	FILE *fp;
	ListElem *p=(ListElem *)malloc(10 * sizeof(ListElem));
	
	p = head;

	
	if ((fp = fopen("D:\\test.txt", "r")) == NULL) {
		fputs("Error,The file not exist",stderr);
		exit(0);
	}
	char ch;
	int i = 0;
	ListElem *NewElem = (ListElem *)malloc(10 * sizeof(ListElem));
	ListE_Initialize(NewElem);
	while (ch = fgetc(fp)) 
	{
		if (ch ==EOF)
		{
			if (head->next == NULL)
			{
				head->next = NewElem;
				p = NewElem;
				p->next = NULL;
			}
			else
			{
				listE_Insert(p, NewElem);
				p = p->next;
			}
			break;
		}
		if (ch == '\n')
		{
			if (head->next == NULL) {
				head->next =NewElem;
				p = NewElem;
				p->next = NULL;
			}
			else {
				listE_Insert(p, NewElem);
				p = p->next;
			}
			i = 0;
			NewElem = (ListElem *)malloc(10 * sizeof(ListElem));
			ListE_Initialize(NewElem);

		}
		if (ch != '\n') {
			NewElem->data[i++] = ch;
		}
			
	 
	}
	fclose(fp);
}

int main(int argc, char const *argv[])
{
	ListElem *head;
	head = (struct ListElem*)malloc(10*sizeof(ListElem));
	head->next = NULL;
	ListE_Initialize(head);
	Read_File(head);
	//printf("%d", p->data);
	
	//node *head=new node;
	//head = NULL;
	//ListE_Initialize(head);
	ListE_Print(head);
	//printf("%c", p->data);
	system("pause");
	return 0;
}