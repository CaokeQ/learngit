/*test the Function of insert*/

#include <stdio.h>
#include <string.h>

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


void listE_Sort(ListElem *head){
	ListElem *current,*prev;
	current=head->next;
	prev=head;
	while(current->next!=NULL)
	{

		for(;current->next!=NULL;current=current->next){
			if(strcmp(prev->data,current->data)>0)
			{
				char *backup=prev->data;
				prev->data=current->data;
				current->data=backup;
			}
		}
		prev=prev->next;
		current=prev->next;
	}
}