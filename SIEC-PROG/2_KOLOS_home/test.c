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
 
 
 

int main(int argc, char *argv[]) {
    int sockfd;

    if (argc != 2) {
        printf("Zla liczba argumentow!\n");
        exit(-1);
    }

    struct addrinfo hints, *addr_info;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family   = AF_INET;      // IPv4
    hints.ai_socktype = SOCK_DGRAM;   // UDP

    if (getaddrinfo(argv[1], "7777", &hints, &addr_info) != 0) {
        perror("getaddrinfo");
        exit(-1);
    }

    sockfd = socket(addr_info->ai_family,
                    addr_info->ai_socktype,
                    addr_info->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(-1);
    }

    char message[MESSAGE_SIZE];
    printf("Podaj wiadomosc do serwera:\n> ");
    fgets(message, MESSAGE_SIZE, stdin);

    if (sendto(sockfd,message,strlen(message),0,addr_info->ai_addr,addr_info->ai_addrlen) == -1) {
        perror("sendto");
        exit(-1);
    }

    recvfrom(sockfd, message, MESSAGE_SIZE, 0, NULL, NULL);
    printf("Odpowiedz od serwera: %s", message);

    freeaddrinfo(addr_info);
    close(sockfd);
    return 0;
}

