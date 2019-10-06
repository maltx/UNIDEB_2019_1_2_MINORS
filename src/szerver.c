#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PORT 3500

//void writeClientsMsg(int * cli_sockfd, char *msg);

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int my_socket; // az én socket-em (a szerveré)

	my_socket = socket(AF_INET, SOCK_STREAM, 0); //adott egy számot a my_socket-nek
	if (my_socket < 0)
	{
		printf("Nem sikerült lekreálni a socketet.\n");
		exit(1);
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;

	int server_cimhossz = sizeof server;


	if ( bind(my_socket, (struct sockaddr *) &server, server_cimhossz) == -1)
	{
		printf("Sikertelen bind-olás.\n");
		exit(2);
	}
	else
		printf("Sikeres bind-olás.\n");

	if(listen(my_socket, 2) == -1) // Figyeli a socketet
	{
		printf("Hiba. Listen error.\n");
		exit(3);
	}

	printf("Várakozás a beérkező kapcsolatra...\n");

	struct sockaddr_in client1;
	struct sockaddr_in client2;
	int cli_sockfd[2];
	int client_cimhossz = sizeof server; // a client2 is ezt használja


	cli_sockfd[0] = accept(my_socket, (struct sockaddr *) &client1, &client_cimhossz);
	if(cli_sockfd[0] < 0)
	{
		printf("Nem sikerült fogadni a kliens1 kérését.\n");
		exit(4);
	}
	else
	{
		printf("Sikerült csatlakozni a kliens1-nek.\n");
	}

	cli_sockfd[1] = accept(my_socket, (struct sockaddr *) &client2, &client_cimhossz);
	if(cli_sockfd[1] < 0)
	{
		printf("Nem sikerült fogadni a kliens2 kérését.\n");
		exit(5);
	}
	else
	{
		printf("Sikerült csatlakozni a kliens2-nek.\n");
	}


		printf("Játékra fel!\n");


		char tablazat[20][20];


		for (int i = 0; i < 20; i++)       //tablazat feltoltese
			 {
				 for(int j = 0; j < 20; j++)
				 {
						 tablazat[i][j] = '-';
				}
			 }

			 //char *ptabla = tablazat;

		 for (int i = 0; i < 20; i++)       //tablazat megjelenites
					 {
							 for(int j = 0; j < 20; j++)
							 {
								 	printf("%c",tablazat[i][j]);
								 	printf(" ");
							 }
					 printf("\n");
				 }


 				write(cli_sockfd[0], tablazat, 1000);
				 //write(cli_sockfd[1], ptabla, 1000);

     while(1)
	 		{


	      //recvString(cli_sockfd[0],ptabla);
				read(cli_sockfd[0], tablazat, 1000);
	      //writeClientMsg(cli_sockfd[1],*ptabla);
				write(cli_sockfd[1], tablazat, 1000);

				read(cli_sockfd[1], tablazat, 1000);
	      //writeClientMsg(cli_sockfd[0],*ptabla);
				write(cli_sockfd[0], tablazat, 1000);


			}
    printf("Játék vége.\n");
    close(cli_sockfd[0]);
    close(cli_sockfd[1]);
    close(my_socket);


	return 0;
}
