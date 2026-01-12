#include<stdio.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

/* Na SK - do modyfikacji
   Brak pelnej obslugi bledow! */

int main(int argc, char * argv[]) {

	struct addrinfo *res;
	struct sockaddr_in *sain;
	int co;
	struct addrinfo hints;

	hints.ai_flags = AI_CANONNAME;
	//co = getaddrinfo(argv[1], NULL, NULL, &res);
	co = getaddrinfo(argv[1], NULL, &hints, &res);
	if (co != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(co));
        return -1;
    }

	printf("Pola (pierwszej na liscie) struktury addrinfo:\n");

	printf("ai_flags: %d\n", res->ai_flags);
	
	printf("ai_family: %d (", res->ai_family);
	if(res->ai_family == AF_INET) printf("AF_INET)\n");
	else if(res->ai_family == AF_INET6) printf("AF_INET6)\n");
	else printf("nieznany typ adresu)\n");
	
	printf("ai_socktype: %d\n", res->ai_socktype);
	switch(res->ai_socktype){
		case 1:// sys/socket.h
			printf("(SOCK_STREAM)\n");
			break;
	}
	printf("ai_protocol: %d\n", res->ai_protocol);
	printf("ai_addrlen: %d\n", res->ai_addrlen);
	
	printf("ai_addr: ");
	if(res->ai_family == AF_INET) {
		sain = (struct sockaddr_in*)(res->ai_addr);
		printf("%s\n", inet_ntoa(sain->sin_addr));
	}
	
	printf("ai_canonname: %s\n", res->ai_canonname);
	
	return 0;

}

