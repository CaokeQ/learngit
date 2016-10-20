#include <stdio.h>
#include<stdlib.h>
#include <string.h>


/*word count*/

typedef  struct ListElem
{
	struct ListElem *next;
	struct ListElem *prev;
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
	p = head->next;
	while (p!= NULL) {
		fputs(p->data,stdout);
		puts("\n");
		p = p->next;
	}
	puts("\nDone");
}

void ListE_Fprintf(ListElem *head) {
	FILE *fp;
	ListElem *p;
	p = head->next;
	errno_t err;
	if ((err = fopen_s(&fp, "d:\\result.txt", "w+")) == 0)fputs("error", stderr);
	while (p != NULL) {
		fputs(p->data, fp);
		fputc('\n', fp);
		p = p->next;
	}
	fclose(fp);
}

void listE_Sort(ListElem *head) {
	ListElem *current, *prev;
	current = head->next;
	prev = head;
	while (current != NULL)
	{

		for (; current != NULL; current = current->next) {
			if (strcmp(prev->data, current->data)>0)
			{
				char *backup = prev->data;
				prev->data = current->data;
				current->data = backup;
			}
		}
		prev = prev->next;
		current = prev->next;
	}
}
ListElem  *listE_Insert(ListElem *p, ListElem *NewELem) {
	ListElem  *still;
	still = p;
	if(strcmp(NewELem->data,p->data)>=0){
		p->next = NewELem;
		NewELem->prev = p;
		NewELem->next = NULL;
		p = p->next;
		return p;
	}
	else{
		while (strcmp(NewELem->data, p->data) < 0&&p->prev!=NULL) 
		{
			p = p->prev;
		}
		NewELem->next = p->next;
		p->next = NewELem;
		p->next->prev = NewELem;
		NewELem->prev = p;
		p = still;
		return p;
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

	while (1)
	{
		ch = fgetc(fp);
		if (ch ==EOF)
		{
			if (head->next == NULL)
			{
				head->next = NewElem;
				NewElem->prev = head;
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
			if (head->next == NULL)
			{
				head->next = NewElem;
				NewElem->prev = head;
				p = NewElem;
				p->next = NULL;
			}
			else
			{
				p=listE_Insert(p, NewElem);
			}
			i = 0;
			NewElem = (ListElem *)malloc(10 * sizeof(ListElem));
			ListE_Initialize(NewElem);
		}

		if (ch != '\n') 
		{
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
	head->prev = NULL;
	ListE_Initialize(head);
	Read_File(head);
	ListE_Print(head);
	listE_Sort(head);
	ListE_Print(head);
	//ListE_Fprintf(head);
	system("pause");
	return 0;
}