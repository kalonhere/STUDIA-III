#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<netinet/in.h>
#include<string.h>
#include<signal.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MESSAGE_SIZE 256
#define NI_MAXHOST 1025


int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Zla ilosc argumentow!\n");
        exit(-1);
    }

    struct addrinfo hints;
    struct addrinfo *addr_info;
    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    if((getaddrinfo(argv[1],"8888",&hints,&addr_info)) != 0){
        perror("getaddrinfo");
        exit(-1);
    }


    int sockfd;

    if((sockfd = socket(addr_info->ai_family,addr_info->ai_socktype,0)) == -1){
        perror("socket");
        exit(-1);
    }
    char message[MESSAGE_SIZE];
    printf("Podaj wiadomosc do servera:\n>");
    fgets(message,sizeof(message),stdin);
    
    int bits = 0;
    if(((bits = sendto(sockfd,message,strlen(message),0,addr_info->ai_addr,addr_info->ai_addrlen))) == -1){
        perror("sendto");
        exit(-1);
    }

    recvfrom(sockfd,&message,MESSAGE_SIZE,0,NULL,NULL);
    printf("Odpowiedz serwera: %s",message);

    freeaddrinfo(addr_info);
    close(sockfd);




    return 0;
}
