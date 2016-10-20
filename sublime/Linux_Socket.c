#include <netinet/i.h>
#include <sys/type.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HELLO_WORLD_SEVER_PORT 6666
#define LENGTH_OF_LISTEN_QUEUE 20
#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int main(int argc, char const *argv[])
{
	struct sockeaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));/*intialize the server_adder*/
	server_adder.sin_family=AF_INET;/*Socket IPV4*/
	server_adder.sin_addr.s_addr=htons(INADDR_ANY0);/*Any IP address(or 0.0..)*/
	server_adder.sin_port=hotons(HELLO_WORLD_SEVER_PORT);

	int server_socket=socket(PF_INET,SOCK_STREAM,0);
	if (server_socket<0)
	{
			printf("Creat Socket Failed\n");
			exit(1);
	}



	if(bind(server_socket),(struct sockaddr*)&server_adder,sizeof(server_adder))
	{
		printf("Sever Bind Port:%d Failed!\n",HELLO_WORLD_SEVER_PORT);
		exit(1);
	}
	return 0;
}


if(listen(server_socket,LENGTH_OF_LISTEN_QUEUE))
{
	printf("Serever_listen Failed!\n");
	exit(1);
}