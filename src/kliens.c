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
		printf("%s\n","Nem siker�t socketet k�sz�teni.\n");  //cout << "Nem siker�t socketet k�sz�teni.\n";
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
		printf("Nem tudt�l csatlakozni a szerverhez.\n"); //cout<<"Nem tudt�l csatlakozni a szerverhez.\n";
		exit(2);
	}
	else
	{
		printf("Csatlakozt�l a szerverhez.\n"); //cout<<"Csatlakozt�l a szerverhez.\n";
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
	

    while(1)
        {
					int rightdirection = 0;
					char szo[10];

        //recvMsg(sock,*msg);
				read(sock, tablazat2, 1000);

				/*for (int i = 0; i < 400; i++)
				{
						tablazat[i] = msg[i];
				}*/

				printf("%s","Tablazat: \n");
				printf("\n");
		    printf("X  ");

		      for(int i = 0; i < 20; i++)
		      {
		        if(i < 9)
		        {
		        printf("0");
		        printf("%d", i + 1);
		        printf(" ");
		        }
		        else{
		          printf("%d", i + 1);
		          printf(" ");
		        }
		      }
		      printf("\n");

		      for (int i = 0; i < 20; i++)       //tablazat megjelenites
		          {
		            if(i < 9)
		            {
		            printf("0");
		            printf("%d", i + 1);
		            printf(" ");
		            }
		            else{
		              printf("%d", i + 1);
		              printf(" ");
		            }

		              for(int j = 0; j < 20; j++)
		              {

		                  printf("%c",tablazat2[i][j]);
		                  printf("  ");
		                    //tablazat2[i][j] = tablazat[i * j];
		              }
		          printf("\n");
		          }

				char letters[200] = {'a','a','a','a','a','a','a','a','a','b',
		                         'b','c','c','d','d','d','d','e','e','e',
		                         'e','e','e','e','e','e','e','e','e','f',
		                         'f','g','g','g','h','h','i','i','i','i',
		                         'i','i','i','i','i','j','k','l','l','l',
		                         'l','m','m','n','n','n','n','n','n','o',
		                         'o','o','o','o','o','o','o','p','p','q',
		                         'r','r','r','r','r','r','s','s','s','s',
		                         't','t','t','t','t','t','u','u','u','u',
		                         'v','v','w','w','x','y','y','z','*','*',
		                         'a','a','a','a','a','a','a','a','a','b',
		                         'b','c','c','d','d','d','d','e','e','e',
		                         'e','e','e','e','e','e','e','e','e','f',
		                         'f','g','g','g','h','h','i','i','i','i',
		                         'i','i','i','i','i','j','k','l','l','l',
		                         'l','m','m','n','n','n','n','n','n','o',
		                         'o','o','o','o','o','o','o','p','p','q',
		                         'r','r','r','r','r','r','s','s','s','s',
		                         't','t','t','t','t','t','u','u','u','u',
		                         'v','v','w','w','x','y','y','z','*','*'};

		    for (int i = 0; i < 10;i++)
		    {
								struct timespec ts;
								clock_gettime(CLOCK_MONOTONIC, &ts);
								srand((time_t)ts.tv_nsec);
		            sendstring[i] = letters[rand() % 200];
		    }





        	for (int i = 0; i < 10; i++)
            {
                 printf("%c ",sendstring[i]);//kiiratom a betuket
            }
					do{
	        printf("\nAdd meg a kiirando szot: \n");//cout<<"add meg a kiirando szot: \n";
			    scanf("%s",szo);
						}while(!(isIttartalmaz(szo, sendstring,strlen(szo))));
	        printf("add meg a kezdo betu x koordinatajat (0 - 20): \n");//cout<<"add meg a kezdo betu x koordinatajat (0 - 20): \n";
	        scanf("%d", &poziciox);
	        printf("add meg a kezdo betu y koordinatajat (0 - 20): \n");//cout<<"add meg a kezdo betu y koordinatajat (0 - 20): \n";
	        scanf("%d", &pozicioy);
	        printf("add meg a szo iranyat (l - le, f- fel, j - jobbra, b- balra: \n");//cout<<"add meg a szo iranyat (le, fel, j - jobbra, b- balra: \n";
	        scanf(" %c", &irany);

        bool tartalmaz[strlen(szo)];

				for (int i = 0; i < strlen(szo); i++)
					{
						tartalmaz[i] = false;
					}




        for (int i = 0; i < strlen(szo) + rightdirection; i++)
            {
                if(irany == 'l')
                    {
												if (pozicioy + strlen(szo) - 1 > 20)
												{
													printf("add meg a kezdo betu y koordinatajat (0 - 20): \n");//cout<<"add meg a kezdo betu y koordinatajat (0 - 20): \n";
									        scanf("%d", &pozicioy);
													rightdirection++;
												}
												else
												{
													tablazat2[pozicioy - 1 + i - rightdirection][poziciox - 1] = szo[i - rightdirection];
													//rightdirection = 0;
												}


                    }
                if(irany == 'f')
                    {

												if (pozicioy < strlen(szo))
													{
														printf("add meg a kezdo betu y koordinatajat (0 - 20): \n");//cout<<"add meg a kezdo betu y koordinatajat (0 - 20): \n";
														scanf("%d", &pozicioy);
														rightdirection++;
													}
												else
													{
		                        tablazat2[pozicioy - i + rightdirection - 1][poziciox - 1] = szo[i - rightdirection];
														//rightdirection = false;
													}
                    }
                if(irany == 'j')
                    {
												if (poziciox + strlen(szo)-1 > 20)
													{
														printf("add meg a kezdo betu x koordinatajat (0 - 20): \n");//cout<<"add meg a kezdo betu y koordinatajat (0 - 20): \n";
														scanf("%d", &poziciox);
														rightdirection++;
													}
												else
													{
		                        tablazat2[pozicioy - 1][poziciox + i - rightdirection - 1] = szo[i - rightdirection];
														//rightdirection = false;
													}

                    }
                if(irany == 'b')
                    {
												if (poziciox < strlen(szo))
													{
														printf("add meg a kezdo betu x koordinatajat (0 - 20): \n");//cout<<"add meg a kezdo betu y koordinatajat (0 - 20): \n";
														scanf("%d", &poziciox);
														rightdirection++;
													}
												else
													{
														//printf("%d", strlen(szo));
		                        tablazat2[pozicioy - 1][poziciox - i + rightdirection -1] = szo[i - rightdirection];
														//rightdirection = false;
													}
                    }
            }

				write(sock, tablazat2, 1000);

        }

	close(sock);

	return 0;
}

