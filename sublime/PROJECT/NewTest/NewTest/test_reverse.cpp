#include  <stdio.h>
#include  <string.h>
/*The programm archieve the funciton that reverse string*/
/*The lvalue must a variable*/
char *reverse(char *k) {
	char *head = k;
	char *tail = k;
	char temp;
	while (*tail) {
		++tail;
	}
	tail--;
	while (tail > head) {
		temp = *head;
		
		head++;
		*head = *tail;
		//This is a question
	//	*tail-- = temp;
	}
	return k;
}


int main(int argc,char const *argv[]) {
	char *s = "asdfsadf";
	s = "sdfsdf";
//	*k = *reverse(k);
}