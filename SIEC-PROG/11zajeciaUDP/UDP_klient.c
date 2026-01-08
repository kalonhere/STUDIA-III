#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

/* A. Mroz - zad. na SK, do modyfikacji */
/* bez pelnej obslugi bledow! */

struct my_msg{
	char name[16];
	char text[255];
};

int main(int argc, char *argv[]) {

	int sockfd;
	struct sockaddr_in server_addr;
	struct my_msg msg;
	ssize_t bytes;

	/* przygotowanie adresu serwera */
	server_addr.sin_family      = AF_INET; /* IPv4 */
	 /* 1 argument = adres IP serwera */
	inet_aton(argv[1], &server_addr.sin_addr ); 
	 /* 2 argument = port serwera*/
	server_addr.sin_port        = htons((u_short)atoi(argv[2]));  

	/* towrze gniazdo - na razie tylko czesc "protokol" */
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);


	printf("[Klient]: Podaj swoj nick:\n> "); 
	fgets(msg.name, 16, stdin);
	msg.name[strlen(msg.name)-1] = '\0';
	printf("[Klient]: Podaj wiadomosc do serwera:\n> ");
	fgets(msg.text, 255, stdin);
	msg.text[strlen(msg.text)-1] = '\0';

	
	printf("[Klient]: wysylam...");

	bytes = sendto(sockfd, &msg, sizeof(msg), 0, 
				(struct sockaddr *)&server_addr, sizeof(server_addr));
	
	printf(" (%s: %zd bajtow)\n", (bytes > 0)?"OK":"cos nie tak!", bytes);

	close(sockfd);
	return 0;

}

