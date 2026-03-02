#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<netinet/in.h>
#include<string.h>
#include<signal.h>
#include<netdb.h>
#include<ctype.h>

#define MESSAGE_SIZE 256
#define PORT 7777



void signalHandler(int signal){
    if(signal == SIGINT){
        printf("Koncze...\n");
        exit(1);
    }
}


int main(int argc, char *argv[]){
    int sockfd;
    if(argc != 2){
        printf("Zla liczba argumentow!\n");
        exit(-1);
    }
    struct addrinfo *addr_info;
    struct sockaddr_in *sock_addr;
    
    if((getaddrinfo(argv[1],"7777",NULL,&addr_info)) != 0){
        perror("getaddrinfo\n");
        exit(-1);
    }
    
    char message[MESSAGE_SIZE];
    printf("Podaj wiadomosc do serwera: \n>");
    fgets(message,MESSAGE_SIZE,stdin);
    if((sockfd = socket(AF_INET,SOCK_DGRAM,0)) == -1){
        perror("socket");
        exit(-1);
    }

    if((sendto(sockfd,&message,sizeof(message),0,(struct sockaddr*)&sock_addr,sizeof(*sock_addr))) == -1){
        perror("sendto");
        exit(-1);
    }

    recvfrom(sockfd,&message,sizeof(message),0,NULL,NULL);
    printf("Odpowiedz od serwera: %s",message);


    

    


    return 0;
}
