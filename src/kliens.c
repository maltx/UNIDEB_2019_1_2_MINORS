#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PORT 3500

char *letterRand (int num);

bool isIttartalmaz(char szo[10], char sendstring[10], int hossz);


int main(int argc, char *argv[])
{
	srand(time(NULL));
	int sock = 0;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		printf("%s\n","Nem sikerüt socketet készíteni.\n");  //cout << "Nem sikerüt socketet készíteni.\n";
		exit(1);
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);

	char server_addr[16];
	sprintf(server_addr, "%s", argv[1]);
	server.sin_addr.s_addr = inet_addr(server_addr);

	int server_cimhossz = sizeof server;

	if( connect(sock, (struct sockaddr *) &server, server_cimhossz) < 0 )
	{
		printf("Nem tudtál csatlakozni a szerverhez.\n"); //cout<<"Nem tudtál csatlakozni a szerverhez.\n";
		exit(2);
	}
	else
	{
		printf("Csatlakoztál a szerverhez.\n"); //cout<<"Csatlakoztál a szerverhez.\n";
	}

	char msg[400];
	int recvs = 0; // receive size
	char szo[10];
	char irany;
	int pozicioy = 0;
	int poziciox = 0;
	bool tartalmaz[10];
	bool isIt = false;
	char sendstring[10];
	char tablazat[400];
	char tablazat2[20][20];
